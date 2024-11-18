#include "Stack.h"
#include <stdio.h>

int main() {
    Stack* stack1 = stack_create();
    int V[] = {2, 4, 6, 8, 10, 25};
    for (int i = 0; i < 6; i++) {
        if (!Stack_push(stack1, V[i])) {
            printf("Erro ao inserir V[%d] = %d na pilha\n", i, V[i]);
        }
    }
    printf("Pilha 1:\n");
    Stack_print(stack1);

    Stack* stack2 = stack_create();
    int B[] = {2, 10, 8, 25, 16};
    for (int i = 0; i < 5; i++) {
        if (!Stack_push(stack2, B[i])) {
            printf("Erro ao inserir V[%d] = %d na pilha\n", i, B[i]);
        }
    }
    printf("Pilha 2:\n");
    Stack_print(stack2);

    printf("Pilha 3 concatenada com a lista 1 e 2: \n");
    Stack* stack3 = Stack_concatenar(stack1, stack2);
    Stack_print(stack3);
}