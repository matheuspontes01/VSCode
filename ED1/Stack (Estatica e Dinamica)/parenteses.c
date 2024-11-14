#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Dedução do exercício é:
// '(' push
// ')' pop (lembrar do aviso de underflow)

// Obs.: Utilizar as funcoes de DynamicStack.c

// *Lembrar na hora dos exercícios: tentar resolver os exercícios utilizando as funções do TAD construído pelo professor
int main()
{
    char string[100];
    fgets(string, 100, stdin);
    Stack* stack = stack_create();
    int item;
    
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') break;
        if (string[i] == '(') {
            if (!Stack_push(stack, string[i])) {
                printf("Nao foi possível inserir %c\n", string[i]);
            }
        } else if (string[i] == ')') {
            if (!Stack_pop(stack, &item)) {
                //printf("underflow\n");
            } 
        }
    }
    
    if (Stack_empty(stack)) {
        printf("Correto\n");
    } else {
        printf("Incorreto\n");
    }
}