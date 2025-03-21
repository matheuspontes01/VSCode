#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox;
} TNo;

struct stack{
    TNo* inicio;
    int qty;
};

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->info = info;
        novo->prox = NULL; 
    }
    return novo;
}

Stack* stack_create() {
    Stack* nova = malloc(sizeof(Stack));
    if (nova) {
        nova->inicio = NULL;
        nova->qty = 0;
    }
    return nova;
}

int Stack_push(Stack* stack, int info) {
    TNo* novo = TNo_createNFill(info);
    if (!novo) return 0; //overflow
    novo->prox = stack->inicio;
    stack->inicio = novo;
    stack->qty++;
    return 1;
}

int Stack_pop(Stack* stack, int* info) {
    if (!Stack_empty(stack)) {
        *info = stack->inicio->info;
        TNo* aux = stack->inicio;
        stack->inicio = stack->inicio->prox;
        free(aux);
        stack->qty--;
        return 1;
    }
    return 0;
}

int Stack_head(Stack* stack, int* info) {
    if (!Stack_empty(stack)) {
        *info = stack->inicio->info;
        return 1;
    }
    return 0;
}

void Stack_destroy(Stack* stack) { // feito por mim (deu certo)
    TNo* aux = stack->inicio;
    TNo* temp;
    while (aux != NULL) {
        temp = aux->prox;
        free(aux);
        aux = temp;
    }
    stack->inicio = NULL;
}

int Stack_full(Stack* stack) { // ficara cheio se passar do limite da memoria alocavel do sistema computacional
    return 0;
}

int Stack_empty(Stack* stack) {
    return stack->qty == 0;
}

int Stack_qty(Stack* stack) {
    return stack->qty;
}

void Stack_print(Stack* stack) { // feito por mim
    if (stack->inicio == NULL) {
        printf("Lista vazia.\n");
    }
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

bool Stack_element_equals(Stack* stack, int info) {
    if (Stack_empty(stack)) return false;
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        if (aux->info == info) {
            return true;
        }
    }
    return false;
}

int Stack_equals(Stack* stack1, Stack* stack2) {
    TNo* aux1 = stack1->inicio;
    TNo* aux2 = stack2->inicio;

    while (aux1 != NULL || aux2 != NULL) {
        if (aux1->info != aux2->info) {
            printf("As listas nao sao iguais\n");
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    
    if (aux1 == NULL && aux2 == NULL) {
        printf("As listas sao iguais\n");
        return 1;
    } else {
        printf("As listas nao sao iguais.\n");
        return 0;
    }
}

Stack* Stack_reversed_dynamic(Stack* stack) {
    Stack* P = stack_create();
    if (!P || Stack_empty(stack)) return NULL;
    
    int item;
    printf("Removendo elementos da pilha 1 e inserindo na pilha 2\n");
    while (Stack_pop(stack, &item)) {
        printf("%d\n", item);
        Stack_push(P, item);
    }
    return P;
}

Stack* Stack_transfer(Stack* stack) {
    Stack* P = stack_create();
    if (!P || Stack_empty(stack)) return NULL;
    int item;
    while (Stack_pop(stack, &item)) {
        Stack_push(P, item);
    }

    return P;
}

bool Stack_info_igual(Stack* stack, int info) {
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        if (aux->info == info) {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

Stack* Stack_intersecao(Stack* stack1, Stack* stack2) {
    Stack* stack3 = stack_create();
    if (!stack3 || !stack1->inicio || !stack2->inicio) return NULL;
    TNo* aux1 = stack1->inicio;
    TNo* i, j;
    while (aux1 != NULL) {
        TNo* aux2 = stack2->inicio;
        while (aux2 != NULL){
            if (aux1->info == aux2->info) {
                if (!Stack_info_igual(stack3, aux1->info)) {
                    Stack_push(stack3, aux1->info);
                }
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
    return stack3;
}

Stack* Stack_concatenar(Stack* stack1, Stack* stack2) {
    Stack* stack3 = stack_create();
    if (!stack3 || !stack1->inicio || !stack2->inicio) return NULL;
    TNo* aux = stack1->inicio;
    while (aux != NULL) {
        Stack_push(stack3, aux->info);
        aux = aux->prox;
    }
    aux = stack2->inicio;
    while (aux != NULL) {
        Stack_push(stack3, aux->info);
        aux = aux->prox;
    }
    return stack3;
}

bool Stack_isRepeating(Stack* stack, int info) {
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        if (aux->info == info) {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

int Stack_push_no_repeat(Stack* stack, int info) {
    TNo* novo = TNo_createNFill(info);
    if (!novo) return 0;
    if (!Stack_isRepeating(stack, info)) {
        novo->prox = stack->inicio;
        stack->inicio = novo;
        stack->qty++;
    } else {
        printf("Nao pode inserir numero repetido na pilha\n");
    }
    return 1;
}

bool Stack_sorted(Stack* stack, int info) {
    TNo* novo = TNo_createNFill(info);
    if (!novo) return false;

    if (stack->inicio == NULL) {
        stack->inicio = novo;
    } else {
        TNo* aux = stack->inicio;
        TNo* anterior;
        while (aux != NULL && novo->info > aux->info) {
            anterior = aux;
            aux = aux->prox;
        }
        if (aux == stack->inicio) {
            novo->prox = stack->inicio;
            stack->inicio = novo;
        } else if (aux == NULL) {
            TNo* fim = stack->inicio;
            while (fim->prox != NULL) {
                fim = fim->prox;
            }
            fim->prox = novo;
        } else {
            novo->prox = anterior->prox;
            anterior->prox = novo;
        }
    }

    return true;
}

bool Stack_show_remove(Stack* stack, int *info) {
    if (stack->inicio != NULL) {
        *info = stack->inicio->info;
        TNo* aux = stack->inicio;
        stack->inicio = stack->inicio->prox;
        free(aux);
    } else {
        printf("Lista Vazia.\n");
    }
}

bool Stack_concatenar_stack2NULL(Stack* stack1, Stack* stack2) {
    if (!stack1 || !stack2) return false;

    TNo* aux = stack2->inicio;
    int temp;
    while (Stack_pop(stack2, &temp)) {
        Stack_push(stack1, temp);
    }

    return true;
}
