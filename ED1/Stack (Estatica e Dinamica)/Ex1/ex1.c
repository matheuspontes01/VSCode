#include "StaticStack.h"
#include <stdio.h>
#include <string.h>

int main() {
    Stack* S1 = stack_create();
    char texto[50] = "ESTE EXERCICIO E MUITO FACIL";
    int i = 0;

    while (texto[i] != '\0') {
        // Empilha cada caractere da palavra
        while (texto[i] != ' ' && texto[i] != '\0') {
            char temp[2] = {texto[i], '\0'};
            Stack_push(S1, temp);
            i++;
        }

        // Desempilha para inverter a palavra
        char temp[30];
        while (Stack_pop(S1, temp)) {
            printf("%s", temp);
        }

        // Imprime espaço entre palavras
        if (texto[i] == ' ') {
            printf(" ");
            i++;  // Avança para o próximo caractere depois do espaço
        }
    }
    
    printf("\n");
    return 0;
}