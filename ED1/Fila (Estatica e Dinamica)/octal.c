#include "Queue.h"
#include <stdio.h>

int main() {
    Queue* q1 = Queue_create();

    int quociente, resto;

    printf("Digite um numero decimal para se tornar octal: \n");
    scanf("%d", &quociente);

    while (quociente != 0) {
        resto = quociente % 8;
        Queue_enqueue(q1, resto);
        quociente /= 8;
    }

    print_octal(q1);
}