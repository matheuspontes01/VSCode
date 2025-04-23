#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(Stack* stack) {
    int temp;
    while (Stack_pop(stack, &temp)) {
        printf("%d", temp);
    }
    putchar('\n');
}

int main() {
    Stack* p1 = stack_create();
    int quociente, resto;

    printf("Digite um numero decimal para se transformar em octal: \n");
    scanf("%d", &quociente);
    while (quociente != 0) {
        resto = quociente % 8;
        Stack_push(p1, resto);
        quociente /= 8;
    }

    print_stack(p1);
}