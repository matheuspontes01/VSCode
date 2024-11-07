#include "Stack.h"
#include <stdio.h>
#define MAX 12

int main(void) {
    Stack *S1 = stack_create();
    int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < MAX; i++) {
        if (!Stack_push(S1, V[i])) {
            printf("Nao consegui inserir o elemento V[%d] = %d\n", i, V[i]);
            puts("Overflow!\n");
        }
    }
    
    //int temp;
    
    /*
    while (Stack_pop(S1, &temp)){
        printf("%d, ", temp);
    }
    */
    // Inversao das posicoes da pilha
    Stack *S2 = stack_create();
    int B[] = {4, 5, 6};
    for (int i = 0; i < 3; i++) {
        if (!Stack_push(S2, B[i])) {
            printf("Nao foi possivel inserir o elemento B[%d] = %d\n", i, B[i]);
            puts("Overflow!\n");
        }
    }

    int temp;

    for (int i = 0; i < 3; i++) {
        Stack_pop(S2, &temp);
        int aux = temp;
        if (!Stack_push(S2, aux)) {
            printf("Nao foi possivel inserir o elemento B[%d] = %d\n", i, B[i]);
            puts("Overflow!\n");
        }
    }

    int teste;
    while (Stack_pop(S2, &teste)) {
        printf("%d, ", teste);
    }


    return 0;
}