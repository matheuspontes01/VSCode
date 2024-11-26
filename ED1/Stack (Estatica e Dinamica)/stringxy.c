#include "Stack.h"
#include <stdio.h>
#include <string.h>

int main() {
    Stack* f1 = stack_create();

    char X[10];
    fgets(X, 10, stdin);

    char Y[10];
    fgets(Y, 10, stdin);

    int temp;
    for (int i = 0; i < strlen(Y); i++) {
        if (X[i] == '\n') break;
        if (!Stack_push(f1, X[i])) {
            printf("Erro ao inserir o caracter %c\n", X[i]);
        }
    }

    bool forma = true;
    for (int i = 0; i < strlen(Y); i++) {
        if (Y[i] == '\n') break;
        Stack_pop(f1, &temp);
        if (Y[i] != temp) {
            forma = false;
        }
    }

    if (forma) {
        printf("Esta na forma XY.\n");
    } else {
        printf("Nao esta na forma de XY.\n");
    }
}