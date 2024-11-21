#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack* stack = stack_create();
    int *V = malloc(32 * sizeof(int));
    if (V == NULL) {
        printf("Problema de alocacao de memoria.\n");
        return 1;
    }

    int quociente, resto, n1, i = 0;

    printf("Digite um numero para transformar ele em binario: \n");
    scanf("%d", &n1);

    quociente = n1;

    while(quociente != 0) {
        resto = quociente % 2;
        V[i] = resto;
        quociente /= 2;
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (!Stack_push(stack, V[j])) {
            printf("Erro ao inserir V[%d] = %d\n", j, V[j]);
        }
    }
    Stack_print(stack);

    return 0;
}