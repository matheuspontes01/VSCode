#include "Stack.h"
#include <stdio.h>

int main() {
    Stack* s1 = stack_create();

    int V[] = {15, 2, 6, 1};

    for (int i = 0; i < 4; i++) {
        if (!Stack_sorted(s1, V[i])) {
            printf("Nao pude inserir V[%d] = %d\n", i, V[i]);
        }
    }

    Stack_print(s1);

    int temp;
    Stack_show_remove(s1, &temp);
    
    printf("Valor do topo da pilha: %d\n", temp);
    Stack_print(s1);
}