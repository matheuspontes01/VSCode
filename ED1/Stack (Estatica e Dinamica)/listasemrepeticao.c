#include "Stack.h"
#include <stdio.h>

int main() {
    Stack* stack = stack_create();
    int V[] = {12, 5, -7, 8, 5, 9, 12, 1, 8};
    for (int i = 0; i < 9; i++) {
        if (!Stack_push_no_repeat(stack, V[i])) {
            printf("Nao foi possivel inserir V[%d] = %d\n", i, V[i]);
        }
    }

    int temp;
    while (Stack_pop(stack, &temp)) {
        printf("%d, ", temp);
    }
    putchar('\n');
}