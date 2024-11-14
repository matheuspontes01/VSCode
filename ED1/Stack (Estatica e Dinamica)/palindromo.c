#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Obs.: Utilizar as funcoes de DynamicStack.c

int main()
{
    char string[10];
    fgets(string, 10, stdin);
    Stack* stack = stack_create();
    
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') break; //interrompe o loop para não ler a nova linha que '\n' gera
        if (!Stack_push(stack, string[i])) {
            printf("Nao foi possível inserir %c\n", string[i]);
        }
    }
    int item;
    bool palim = true;
    
    for (int i = 0; i < strlen(string) && palim; i++) {
        if (string[i] == '\n') break; //interrompe o loop para não ler a nova linha que '\n' gera
        Stack_pop(stack, &item);
        if ((char)item != string[i]) {
            palim = false;
        }
    }
    
   if (palim)
        puts("palindromo\n");
   else
        puts("nao eh palindromo\n");
}
