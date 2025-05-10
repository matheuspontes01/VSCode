#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

/*
    Rotacoes a serem feitas quando pt.bal == +- 2:
    - Insercao na subarvore direita do filho direito: pt.bal = +2 e ptu.bal = +1 (rotacao simples a esquerda)
    - Insercao na subarvore esquerda do filho direito: pt.bal = +2 e ptu.bal = -1 (rotacao dupla direita-esquerda)
    - Insercao na subarvore esquerda do filho esquerdo: pt.bal = -2 e ptu.bal = -1 (rotacao simples a direita)
    - Insercao na subarvore direita do filho esquerdo: pt.bal = -2 e ptu.bal = +1 (rotacao dupla esquerda-direita)


    Se esta desbalanceado de um lado, vamos rotacionar para o outro lado para balancear!
*/

// Cria a estrutura da arvore com raiz
AvlTree* AvlTree_create() {
    AvlTree* T = malloc(sizeof(AvlTree));
    if (T) {
        T->root = NULL;
    }
    return T;
}

// Cria os nos que serao alocados na arvore
Node* createNode(int key) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->key = key;
        node->right = NULL;
        node->left = NULL;
        node->bal = 0; // Fator de balanceamento que cada no possui
        /*
        bal = altura da subarvore direita - altura da subarvore esquerda
        +1 -> mais alta a direita
        -1 -> mais alta a esquerda
        +2 -> desbalanceamento a direita (rotacao a esquerda)
        -2 -> desbalanceamento a esquerda (rotacao a direita)
        */
    }
    return node;
}

void CASE_1(Node** pt, bool* h) { // Caso quando o lado esquerdo esta desbalanceado, entao, iremos balancear para o lado direito
    Node* ptu = (*pt)->left; // ptu é o filho esquerdo do nó desbalanceado (*pt)

    if (ptu->bal == -1) { // Caso de rotacao simples a direita (ou seja, tem filho a esquerda de ptu)
        (*pt)->left = ptu->right; // Subarvore direita de ptu vira filho esquerdo de pt
        ptu->right = *pt; // pt vira filho direito de ptu
        (*pt)->bal = 0; // Resetando balanceamentos
        *pt = ptu; // ptu agora ocupa a posicao de pt
    } else { // Caso de rotacao dupla (esquerda-direita)
        Node* ptv = ptu->right; // ptv é o filho direito do filho esquerdo (ptu)
        ptu->right = ptv->left; // Subarvore esquerda de ptv vira filho direito de ptu
        ptv->left = ptu; // ptu vira filho esquerdo de ptv
        (*pt)->left = ptv->right; // Subarvore direita de ptv vira filho esquerdo de (*pt)
        ptv->right = *pt; // pt vira filho direito de ptv

        // Ajustando fatores de balanceamento apos a rotacao
        if (ptv->bal == -1) // Se o fator de balanceamento de ptv for -1, isso indica que o nó recém-inserido estava na subárvore ESQUERDA de ptv
            (*pt)->bal = 1; // Após a rotação, o antigo *pt (nó desbalanceado) se torna filho direito de ptv.
                            // Como o nó novo estava na esquerda de ptv, o lado direito (*pt) fica mais leve — então seu balanceamento vira 1 (ligeiro peso à direita)
        else
            (*pt)->bal = 0; // Caso contrário (ptv->bal seja 0 ou 1), não houve inserção significativa no lado esquerdo de ptv.
                            // Logo, o balanceamento do antigo *pt (que agora é filho direito de ptv) zera

        if (ptv->bal == 1) // Se o fator de ptv for 1, significa que o nó novo foi inserido na subárvore DIREITA de ptv
            ptu->bal = -1; // Nesse caso, o filho esquerdo (ptu) ficou mais pesado à esquerda após a rotação, então recebe -1
        else
            ptu->bal = 0;  // Caso contrário, ptu (filho esquerdo de ptv após a rotação) está balanceado


        *pt = ptv; // ptv ocupa a posicao de (*pt)
    }
    (*pt)->bal = 0; // Arvore fica balanceado apos a rotacao
    *h = 0; // Altura nao aumentou
}

void CASE_2(Node** pt, bool* h) { // Caso quando o lado direito esta desbalanceado, entao, iremos balancear para o lado esquerdo
    Node* ptu = (*pt)->right; // ptu é o filho direito do nó desbalanceado

    if (ptu->bal == 1) { // Caso rotacao a esquerda
        (*pt)->right = ptu->left;
        ptu->left = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    } else { // Caso rotacao dupla (direita-esquerda)
        Node* ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        (*pt)->right = ptv->left;
        ptv->left = *pt;

        if (ptv->bal == 1)
            (*pt)->bal = -1;
        else
            (*pt)->bal = 0;

        if (ptv->bal == -1)
            ptu->bal = 1;
        else
            ptu->bal = 0;

        *pt = ptv;
    }
    (*pt)->bal = 0;
    *h = 0;
}


int getHeight(Node* node) {
    if (node == NULL) return 0;

    int hl = getHeight(node->left);
    int hr = getHeight(node->right);

    if (hl > hr) {
        return hl + 1;
    } else {
        return hr + 1;
    }
}

// Inserção AVL
void BinTree_insert_r(int x, Node** pt, bool *h){ // X-> valor a ser inserido; *pt-> ponteiro para o no atual; h-> flag booleana que indica se a altura da arvore aumentou
    if(*pt == NULL){ // Quando achamos um lugar vazio para ser inserido na arvore, criamos o no no endereco de pt e sera inserido nele
        *pt = createNode(x); // Criamos o no
        *h = true; // Confirma que teve aumento na altura da arvore
    } else { // Caso nao seja vazio, vamos explorar os nos
        if(x < (*pt)->key){ // Se o nosso valor passado na funcao for menor que o valor do no, entramos nessa estrutura
            BinTree_insert_r(x, &(*pt)->left, h); // Vai passando recursivamente, e para quando para naquele primeiro if
            if (*h==true){ // Quando finaliza a insercao, verificamos se *h foi para true (aumentou a altura) e iremos equilibrar a nossa arvore apos a insercao
                switch((*pt)->bal){ // Ajustaremos o fator de balanceamento apos a insercao
                    case 1: (*pt)->bal = 0; *h = false; break; // -> Estava mais alto pela direita, agora fica equilibrado
                    case 0: (*pt)->bal = -1; break; // -> Estava equilibrado, agora fica mais alto a esquerda
                    case -1: CASE_1(pt, h); break; // Ja estava mais alto a esquerda, precisa rotacionar
                }
                //printf("Estou em [%d]: Valor de h=%d\n", (*pt)->key, *h);
            }
        }
        else {
            BinTree_insert_r(x, &(*pt)->right, h);
            if (*h==true){
                switch((*pt)->bal){
                    case -1: (*pt)->bal = 0; *h = false; break; // -> Estava mais alto pela esquerda, agora fica balanceado
                    case 0: (*pt)->bal = 1; break; // -> Estava equilibrado, agora fica mais alto a direita
                    case 1: CASE_2(pt, h); break; // -> Ja estava mais alto pela direita, precisa rotacionar
                }
            }
        }
    }
}

bool BinTree_insert(AvlTree *T, int key){
    bool h;
    BinTree_insert_r(key, &(T->root), &h);
    //TODO: modiciar aqui para retornar se alocou com sucesso...
    return true;
}

// Remoção AVL
bool REMOVE_AVL(int x, Node** pt, bool* h) {
    if (*pt == NULL) { // Nó nao encontrado
        *h = false; // nenhuma alteracao na arvore, nada foi removido
        return false;
    }

    if (x < (*pt)->key) { // se o valor procurado e menor que o valor do no
        /*
            OBSERVACAO: pt e o nó pai
        */
        bool res = REMOVE_AVL(x, &(*pt)->left, h); // chamada recursiva para o filho esquerdo
        if (res && *h) { // se o valor foi encontrado e houve diminuicao na altura da arvore
            switch ((*pt)->bal) { // verifica o valor de balanceamento atual do no
                case 1: CASE_2(pt, h); *h = true; break; // estava mais pesado pela direita, agora ficou mais (fazer rotacao para esquerda)
                case 0: (*pt)->bal = 1; *h = false; break; // estava balanceado, agora ficou levemente inclinado para a direita
                case -1: (*pt)->bal = 0; *h = true; break; // estava levemente inclinado para a esquerda, agora ficou balanceado
            }
        }
        return res; // retorna se a remocao foi bem-sucedida
    } else if (x > (*pt)->key) {
        bool res = REMOVE_AVL(x, &(*pt)->right, h);
        if (res && *h) {
            switch ((*pt)->bal) {
                case -1: CASE_1(pt, h); *h = true; break; // estava mais pesado pela esquerda, agora ficou mais (fazer rotacao para direita)
                case 0: (*pt)->bal = -1; *h = false; break; // estava balanceado, agora ficou levemente inclinado para a esquerda
                case 1: (*pt)->bal = 0; *h = true; break; // estava levemente inclinado para a direita, agora ficou balanceado
            }
        }
        return res;
    } else { // x == (*pt)->key (No encontrado)
        // Caso com no com apenas um filho ou nenhum
        if ((*pt)->left == NULL || (*pt)->right == NULL) {
            Node* temp = (*pt)->left ? (*pt)->left : (*pt)->right; // salva o filho se existir
            free(*pt);
            *pt = temp;
            *h = true;
            return true;
        } else { // Caso com no com dois filhos
            // Substitui o valor atual pelo valor do sucessor (o menor valor da subarvore direita) para garantir a propriedade BST
            Node* successor = findMin((*pt)->right);
            (*pt)->key = successor->key;
            return REMOVE_AVL(successor->key, &(*pt)->right, h); // Remover o sucessor duplicado da subarvore direita
        }
    }
}

bool Avl_remove(AvlTree* T, int key) {
    bool h;
    return REMOVE_AVL(key, &(T->root), &h);
}

Node* findMin(Node* root) {
    Node* x = root;
    while (x->left!= NULL) {
        x = x->left;
    }
    return x;
}

void printInOrder(Node* root) {
    if (root) {
        printInOrder(root->left);
        printf("%d, ", root->key);
        printInOrder(root->right);
    }
}

void printPreOrder(Node* root) {
    if (root) {
        printf("%d, ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}