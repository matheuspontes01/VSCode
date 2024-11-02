#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox; // variavel que armazena endereços para outros 'no'
}TNo;

struct _list{
    TNo* inicio; // A estrutura _list armazena um único ponteiro (inicio) que indica onde a lista começa.
};

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo)); // aloca um novo nó na memória
    if(novo){ // se o novo nó criado for diferente de null (se foi alocado corretamente na memoria), atribui-se os valores para ele em sua estrutura
        novo->info = info;
        novo->prox = NULL; // atribuimos o prox do novo nó como NULL para garantirmos com toda certeza que seu prox aponta pra NULL
    }
    return novo; // retorna o nó criado
}

TLinkedList* TLinkedList_create(){
    TLinkedList* list = malloc(sizeof(TLinkedList)); // aloca list na memoria
    if(list != NULL) // se o endereço do list for diferente de NULL (garantir se list foi alocado na memória)
        list->inicio = NULL; // o endereço da lista do início recebe como endereço NULL
    return list;
}
bool TLinkedList_insert_begin(TLinkedList* list, int info){
    TNo* novo = TNo_createNFill(info); // aloca-se na memoria o novo nó chamado 'novo', com seu endereço de memória, com a info colocada na chamada da função e seu ponteiro 'prox', que aponta pra NULL
    if(novo == NULL) return false; // se o endereço de 'novo' for igual a null, retorna falso
    if(list->inicio != NULL) // se o endereço da lista do inicio for diferente de NULL
        novo->prox = list->inicio; // o ponteiro prox do nó 'novo' vai ter o endereço do nó do início, e então, o ponteiro prox do 'novo' nó vai apontar para o próximo elemento da lista, que será o antigo início da lista
    list->inicio = novo; // o novo nó vai ser o nó do início da lista
    return true;
}
void TLinkedList_print(TLinkedList* list){
    TNo* aux = list->inicio; // atribui a um auxiliar o endereço da list do início, que vai percorrer toda a lista
    while(aux != NULL){ // enquanto o endereço de aux for diferente de NULL
        printf("%d, ", aux->info); // imprime a info dentro do seu campo aux
        aux = aux->prox; // o endereço de aux terá o valor do seu campo prox que aponta para o próximo nó
    }
    putchar('\n');
}

bool TLinkedList_insert_end(TLinkedList* list, int info){
    TNo* novo = TNo_createNFill(info); // aloca-se na memoria o novo nó 'novo', com seu endereço de memória, com a info colocada na chamada da função e seu prox, que é NULL
    if(novo == NULL) return false; // se o endereço de 'novo' for igual a null, retorna falso
    if(list->inicio == NULL) // compara o endereço de 'list->inicio' com 'null'
        list->inicio = novo; // atribui o endereço de 'novo' para 'list->inicio'
    else{
        TNo* aux = list->inicio; // atribui o endereço de 'aux' para 'list->inicio'
        while(aux->prox != NULL) // enquanto o endereço que prox do aux aponta para outro nó for diferente de null,
            aux = aux->prox;   //  aux terá endereço do proximo nó
        aux->prox = novo; // quando o prox do aux for igual a null, atribui o endereço do 'novo' nó para o prox do aux
    }
    return true;
}
/*
bool TLinkedList_insert_middle(TLinkedList* list, int info) { // Assumiremos que a ordem da lista é crescente
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) return false;
    if (list->inicio == NULL) {
        list->inicio = novo;
    } else { // A info do novo nó é menor que a info do nó do inicio da lista
        if (novo->info < list->inicio->info) { // Caso a info do novo nó for menor que a info do nó do inicio
            novo->prox = list->inicio; // o prox do novo nó aponta para o antigo nó do inicio da lista
            list->inicio = novo; // o novo nó se torna o inicio da lista
        } else { // A info do novo nó é maior que a info do nó do inicio da lista
            TNo* y = list->inicio;
            while (y->prox != NULL) {
                if (y->prox->info > novo->info) {
                    break;
                }
                y = y->prox;
            }
            novo->prox = y->prox; // novo nó aponta para o próximo
            y->prox = novo; // atualiza o nó anterior para apontar para o novo
        }
    }
    return true;
}

bool TLinkedList_delete(TLinkedList* list, int x) {
    if (list->inicio == NULL) {
        // A lista está vazia, não há nada a remover
        return false;
    }

    TNo* atual = list->inicio;
    TNo* anterior = NULL;

    // Situação 1: 'x' é o primeiro nó da lista
    if (atual->info == x) {
        list->inicio = atual->prox;  // O início da lista aponta para o próximo nó
        free(atual);                 // Libera a memória do nó removido
        return true;
    }

    // Situação 2: 'x' não é o primeiro nó
    // Percorre a lista até encontrar o nó 'x' ou até o final da lista
    while (atual != NULL && atual->info != x) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o nó 'x' não for encontrado
    if (atual == NULL) {
        return false;  // O nó 'x' não está na lista
    }

    // O nó 'x' foi encontrado, ajusta o ponteiro do nó anterior
    anterior->prox = atual->prox;  // O nó anterior aponta para o próximo nó
    free(atual);                   // Libera a memória do nó removido
    return true;
}

void TLinkedList_deleteAll(TLinkedList* list) {
    TNo* current = list->inicio;
    TNo* next;

    while (current != NULL) {
        next = current->prox;  // Armazena o próximo nó antes de liberar o atual
        printf("Apagando no com valor %d\n", current->info);
        free(current);         // Libera a memória do nó atual
        current = next;        // Avança para o próximo nó
    }

    // Depois de apagar todos os nós, o início da lista é NULL
    list->inicio = NULL;
    printf("Lista apagada com sucesso.\n");
}

bool TLinkedList_delete_from_begin(TLinkedList* lista, int* info){
    if(lista->inicio == NULL) return false;

    *info = lista->inicio->info;
    TNo* temp = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(temp);
    return true;
}


bool TLinkedList_delete_info(TLinkedList* lista, int info){
    if(lista->inicio == NULL) return false;
    TNo* search = TLinkedList_search(lista, info);
    if(search==NULL) return false;
    if(search == lista->inicio){
        lista->inicio = lista->inicio->prox;
    }else{
        TNo* y = lista->inicio;
        while(y->prox != search){
            y = y->prox;
        }
        y->prox = search->prox;
    }
    free(search);
    return true;
}
*/

/*
TNo* TLinkedList_search(TLinkedList* lista, int info){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        if(aux->info == info)
            break;
        aux=aux->prox;
    }
    return aux;
}
*/
bool TLinkedList_deleteOneValue(TLinkedList* list, int info) {
    if (list->inicio == NULL) return false;

    TNo* aux = list->inicio;
    TNo* anterior;
    while (aux != NULL && aux->info != info) {
        anterior = aux;
        aux = aux->prox;
    } 
    if (aux == list->inicio) {
        aux->prox = NULL;
        free(aux);
    } else if (aux == NULL) {
        printf("Nao existe esse valor\n");
    } else {
        anterior->prox = aux->prox;
        free(aux);
    }
    return true;
}

bool TLinkedList_deleteList(TLinkedList* list) {
    if (list->inicio == NULL) return false;

    TNo* aux = list->inicio;
    TNo* anterior;
    while (aux != NULL) {
        anterior = aux->prox;
        free(aux);
        aux = anterior;
    }
    return true;
}

TLinkedList* TLinkedList_intercalar(TLinkedList* list1, TLinkedList* list2) {
    TLinkedList* list3 = TLinkedList_create();

    if (list1->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list1->inicio;
    TNo* aux2 = list2->inicio;
    bool intercalando = true;
    do {
        if (aux1 != NULL && intercalando) {
            TLinkedList_insert_end(list3, aux1->info);
            aux1 = aux1->prox;
        }
        if (aux2 != NULL && !intercalando) {
            TLinkedList_insert_end(list3, aux2->info);
            aux2 = aux2->prox;
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return list3;
} 

bool TLinkedList_sorted(TLinkedList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (list->inicio == NULL) {
        list->inicio = novo;
    } else {
        TNo* aux = list->inicio;
        TNo* anterior;
        while (aux != NULL && novo->info > aux->info) {
            anterior = aux;
            aux = aux->prox;
        }
        if (aux == list->inicio) {
            novo->prox = list->inicio;
            list->inicio = novo;
        } else if (aux == NULL) {
            anterior->prox = novo;
        } else {
            anterior->prox = novo;
            novo->prox = aux;
        }
    }
    return true;
}

TLinkedList* TLinkedList_intercalar_ordenadamente(TLinkedList* list1, TLinkedList* list2) {
    TLinkedList* list3 = TLinkedList_create();

    if (list1->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list1->inicio;
    TNo* aux2 = list2->inicio;
    bool intercalando = true;
    do {
        if (aux1 != NULL && intercalando) {
            TLinkedList_sorted(list3, aux1->info);
            aux1 = aux1->prox;
        }
        if (aux2 != NULL && !intercalando) {
            TLinkedList_sorted(list3, aux2->info);
            aux2 = aux2->prox;
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return list3;
} 

TLinkedList* TLinkedList_retornar_impares(TLinkedList* list, TLinkedList* list2) {
    TLinkedList* list3 = TLinkedList_create();

    if (list->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list->inicio;
    TNo* aux2 = list2->inicio;
    bool intercalando = true;

    do {
        if (aux1 != NULL && intercalando) {
            if (aux1->info % 2 != 0) {
                TLinkedList_insert_end(list3, aux1->info);
            }
            aux1 = aux1->prox;
        }
        if (aux2 != NULL && !intercalando) {
            if (aux2->info % 2 != 0) {
                TLinkedList_insert_end(list3, aux2->info);
            }
            aux2 = aux2->prox;
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return list3;
}

TLinkedList* TLinkedList_retornar_pares(TLinkedList* list, TLinkedList* list2) {
    TLinkedList* list3 = TLinkedList_create();

    if (list->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list->inicio;
    TNo* aux2 = list2->inicio;
    bool intercalando = true;

    do {
        if (aux1 != NULL && intercalando) {
            if (aux1->info % 2 == 0) {
                TLinkedList_insert_end(list3, aux1->info);
            }
            aux1 = aux1->prox;
        }
        if (aux2 != NULL && !intercalando) {
            if (aux2->info % 2 == 0) {
                TLinkedList_insert_end(list3, aux2->info);
            }
            aux2 = aux2->prox;
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return list3;
}

bool TLinkedList_info_igual(TLinkedList* list, int info) {
    TNo* aux = list->inicio;
    while (aux != NULL) {
        if (aux->info == info){
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

TLinkedList* TLinkedList_intersecao(TLinkedList* list, TLinkedList* list2) {
    TLinkedList* list3 = TLinkedList_create();

    if (list->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list->inicio;
    
    while (aux1 != NULL){
        TNo* aux2 = list2->inicio;
        while (aux2 != NULL){
            if (aux1->info == aux2->info) {
                if (!TLinkedList_info_igual(list3, aux1->info))
                {
                    TLinkedList_insert_end(list3, aux1->info);
                }
                break;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }

    return list3;
}