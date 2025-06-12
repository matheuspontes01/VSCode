#include "RedBlack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Color:
// 0 - Black
// 1 - Red

RedBlack* RedBlack_createTree() {
    RedBlack* T = malloc(sizeof(RedBlack));
    T->nil = malloc(sizeof(Node));
    T->nil->color = 0;
    T->nil->left = T->nil;
    T->nil->right = T->nil;
    T->nil->p = T->nil;
    T->root = T->nil;
    return T;
}

Node* createNode(RedBlack* T, int key) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->left = T->nil;
        node->right = T->nil;
        node->p = T->nil;
        node->color = 1;
        node->key = key;
    }
    return node;
}

void RedBlack_insert(RedBlack* T, int key) {
    Node* node = createNode(T, key);
    if (!node) {
        free(node);
        return;
    }

    Node* x = T->root, *y = T->nil;
    while (x != T->nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }  
    node->p = y;

    if (y == T->nil) {
        T->root = node;
    } else if (node->key < y->key){
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = T->nil;
    node->right = T->nil;
    node->color =  1; // Inserimos sempre vermelho para manter as propriedades da árvore da forma mais flexível e simples possível

    RedBlack_insertFixUp(T, node);
}

void RedBlack_insertFixUp(RedBlack* T, Node* z) {
    // Enquanto o pai de z for vermelho
    while (z->p->color == 1) {
        // Se o pai de z é filho à esquerda do avô
        if (z->p == z->p->p->left) {
            Node* y = z->p->p->right; // y é o tio de z (filho direito do avô)

            // Caso 1: o tio (y) é vermelho
            if (y->color == 1) { 
                // Recolorir o pai e o tio de preto
                z->p->color = 0; 
                y->color = 0;

                // Recolorir avô para vermelho
                z->p->p->color = 1;

                // Avança z para o avô (para continuar a verificação)
                z = z->p->p;
            } else { 
                // Caso 2: z é filho direito -> rotação para a esquerda
                if (z == z->p->right) {
                    z = z->p;
                    left_rotate(T, z);
                }

                // Caso 3: z é filho esquerdo -> rotação para a direita e recoloração
                z->p->color = 0; // Pinta o pai de preto
                z->p->p->color = 1; // Pinta o avô de vermelho
                right_rotate(T, z->p->p);
            }
        } else {
            // Mesmo que acima, mas simétrico (pai de z é filho à direita)
            Node* y = z->p->p->left;

            if (y->color == 1) {
                z->p->color = 0;
                y->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            } else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate(T, z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                left_rotate(T, z->p->p);
            }
        }

        // Evita que z continue subindo além da raiz
        if (z == T->root)
            break;
    }

    // Garante que a raiz sempre seja preta
    T->root->color = 0;
}


void left_rotate(RedBlack* T, Node* x) {
    // y é o filho direito de x
    Node* y = x->right;

    // O filho esquerdo de y se torna o filho direito de x
    x->right = y->left;

    // Se o novo filho direito de x não é nil, atualiza o pai
    if (y->left != T->nil) {
        y->left->p = x;
    }

    // O pai de y passa a ser o pai de x 
    y->p = x->p;
    
    // Atualiza o pai de x para apontar para y
    if (x->p == T->nil) {
        T->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    // x passa a ser o filho esquerdo de y
    y->left = x;
    x->p = y;
}

void right_rotate(RedBlack* T, Node* y) {
    // x é o filho esquerdo de y 
    Node* x = y->left;

    // O filho direito de x se torna o filho esquerdo de y
    y->left = x->right;

    // Se o novo filho direito de x for diferente de nil, atualiza o pai
    if (x->right != T->nil) {
        x->right->p = y;
    }

    // O pai de x passa a ser o pai de y
    x->p = y->p;

    // Atualiza o pai de y para apontar para x
    if (y->p == T->nil) {
        T->root = x;
    } else if (y == y->p->right) {
        y->p->right = x;
    } else {
        y->p->left = x;
    }

    // y passa a ser o filho direito de x
    x->right = y;
    y->p = x;
}

void RedBlack_pre(RedBlack* T, Node* root) {
    if (root != T->nil) {
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->left);
        RedBlack_pre(T, root->right);
    }
}

void RedBlack_in(RedBlack* T, Node* root) {
    if (root != T->nil) {
        RedBlack_pre(T, root->left);
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->right);
    }
}

int RedBlack_Height(RedBlack* T, Node* x) {
    if (x == T->nil || (x->left == T->nil && x->right == T->nil)) {
        return 0;
    }

    int hl = RedBlack_Height(T, x->left);
    int hr = RedBlack_Height(T, x->right);

    if (hl > hr) {
        return hl + 1;
    } else {
        return hr + 1;
    }
}

int RedBlack_height_start(RedBlack* T) {
    return RedBlack_Height(T, T->root);
}

Node* RedBlack_min(RedBlack* T, Node* x) {
    while (x->left != T->nil) {
        x = x->left;
    }
    return x;
}

void RedBlack_transplant(RedBlack* T, Node* u, Node* v) { // Substitui a subarvore u pela subarvore v
    if (u->p == T->nil) {
        T->root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    v->p = u->p; // Nao se faz a verificação v != T->nil, porque T->nil não é NULL, é um nó sentinela 
    // que possui campos válidos, e se fosse igual ainda estariamos acessando campos validos de um no alocado.
    // Se v fosse NULL, isso causaria um segmentation fault, ou seja, estariamos acessando uma parte da memoria
    // que não existe.
}

void RedBlack_delete(RedBlack* T, Node* z) { // O nó z é o nó que o usuário quer remover
    Node* y = z, *x;  // O nó y é o nó que será realmente removido
    // O nó x é o filho de y que ocupará o lugar de y
    int y_original_color = y->color; // Pegamos a cor a qual será removida na árvore

    if (z->left == T->nil) { // Se o filho a esquerda de z for T->nil
        x = z->right; // Pegamos o filho da direita que é não é T->nil, que irá substituir o nó removido
        RedBlack_transplant(T, z, z->right); // Fazemos a substituição do filho em cima do nó removido

    } else if (z->right == T->nil) { // Se o filho a direita de z for T->nil
        x = z->left;// Pegamos o filho da esquerda que é não é T->nil, que irá substituir o nó removido
        RedBlack_transplant(T, z, z->left);// Fazemos a substituição do filho em cima do nó removido
    } else { // Caso o nó que deve ser removido tiver dois filhos
        y = RedBlack_min(T, z->right); // Pegamos o sucessor do nó que será removido
        y_original_color = y->color; // Pegamos a cor a qual será removida na árvore
        x = y->right; // Pegamos o filho que irá substituir o nó removido

        if (y->p != z) { // Se y não for filho direito de z
            RedBlack_transplant(T, y, y->right); // Substituimos o sucessor pelo seu unico filho valido (direita)
            y->right = z->right; // O nó y pega a subárvore direita do nó z
            y->right->p = y; // A subárvore que substituiu y terá como pai o nó que foi filho de y
        }
        RedBlack_transplant(T, z, y); // Substituimos o z pelo y
        y->left = z->left; // y fica com o filho a esquerda de z
        y->left->p = y; // A subarvore esquerda tem como pai o sucessor do nó y
        y->color = z->color; // Colocamos a cor que era presente no nó z
    }

    if (y_original_color == 0) // Se o nó removido foi preto, então fazemos o processo de FixUp
        RedBlack_delete_FixUp(T, x);
}

void RedBlack_delete_FixUp(RedBlack* T, Node* x) { // O nó x é o nó que substituiu o nó removido
    Node* w;
    while (x != T->root && x->color == 0) { // Se o nó x for diferente da raiz e tiver cor igual a preto, continua o loop
        if (x == x->p->left) { // Se o nó x for filho esquerdo do seu pai
            w = x->p->right; // O nó w é o irmão de x, e filho direito de seu pai

            if (w->color == 1) { // Se o irmão for vermelho
                w->color = 0; // Altere a cor do irmão para preto
                x->p->color = 1; // Troque a cor do pai para preto
                left_rotate(T, x->p); // Faça uma rotação a esquerda no pai
                w = x->p->right; // Direcione o w para o novo irmão de x novamente
            }

            if (w->left->color == 0 && w->right->color == 0) { // Se o irmao tiver os dois filhos pretos

                w->color = 1; // Troque a cor do irmao para vermelho (manter a propriedade)
                x = x->p; // Sobe o x para o pai

            } else { // Um dos filhos do irmão é vermelho
                if (w->right->color == 0) { // Se o filho da direita do irmão for preto
                    w->left->color = 0; // Troque a cor do filho da esquerda do irmão para preto
                    w->color = 1; // Altere a cor do irmao para vermelho
                    right_rotate(T, w); // Rotacione para a direita o irmão
                    w = x->p->right; // Mude w para o novo irmão de x
                }
                w->color = x->p->color; // Mude a cor do irmão para a mesma cor do pai
                x->p->color = 0; // Mude a cor do pai para preto
                w->right->color = 0; // Mude a cor do filho da direita do irmão para preto
                left_rotate(T, x->p); // Rotacione a esquerda o pai
                x = T->root; // leva x para a raiz da árvore para encerrar o loop
            }
        } else {
            w = x->p->left; // w é o irmão de x, e filho esquerdo do pai de x

            if (w->color == 1) { // Se o irmão for vermelho

                w->color = 0; // Troque a cor do irmão para preto
                x->p->color = 1; // Troque a cor do pai para vermelho
                right_rotate(T, x->p); // Rotacione a direita o pai
                w = x->p->left; // Localiza o novo irmão de x
            }

            if (w->left->color == 0 && w->right->color == 0) { // Se os dois filhos do irmão forem pretos

                w->color = 1; // Altere a cor do irmão para vermelho
                x = x->p; // x sobe para o seu próprio pai

            } else { // Um dos filhos são vermelhos

                if (w->left->color == 0) { // Se o filho esquerdo do irmão for preto
                    w->right->color = 0; // Muda a cor do filho direito do irmão para preto
                    w->color = 1; // Mude a cor do irmão para vermelho
                    left_rotate(T, w); // Rotacione para a esquerda o irmão
                    w = x->p->left; // Localiza o novo irmão de x
                }
                w->color = x->p->color; // Mude a cor do irmão pela cor do seu próprio pai
                x->p->color = 0; // Mude a cor do pai para preto
                w->left->color = 0; // Mude a cor do filho esquerdo do irmão
                x = T->root; // leva x para a raiz da árvore para encerrar o loop
            }
        }
    }
    x->color = 0; // Independente do que acontecer, SEMPRE coloque o nó x com cor preta
}