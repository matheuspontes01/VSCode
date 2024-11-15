#include "Stack.h"
#include <stdio.h>
#include <string.h>

void print_stack(Stack* stack) {
    int item;
    while (Stack_pop(stack, &item))
        printf("%c", item);
    putchar(' ');
}

int main()
{
    // Ler a string
    char string[1024];
    fgets(string, 1024, stdin); // Entrada padrão
    Stack *stack = stack_create();
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') // caso apareca \n, parar a operacao
            break;
        if(string[i] == ' ' || string[i] == '.') // imprime tudo que foi alocado na pilha, deletando e imprimindo tudo que esta sendo removido na pilha
            print_stack(stack);
        else
            Stack_push(stack, string[i]); 
    }
    if (!Stack_empty(stack))
        print_stack(stack);
    
    return 0;
}