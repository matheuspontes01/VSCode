#include "Queue.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    Queue* fila_par = Queue_create();
    Queue* fila_impar = Queue_create();
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n % 2 == 0) {
            Queue_enqueue(fila_par, n);
        } else {
            Queue_enqueue(fila_impar, n);
        }
    }

    Stack* pilha = stack_create();
    bool intercalando = true;
    int temp;
    while (!Queue_empty(fila_impar) || !Queue_empty(fila_par)) {
        if (intercalando && !Queue_empty(fila_impar)) {
            Queue_dequeue(fila_impar, &temp);
            if (temp > 0) {
                Stack_push(pilha, temp);
            } else {
                if (!Stack_empty(pilha)) {
                    Stack_pop(pilha, &temp);
                }
            }
        }
        if (!intercalando && !Queue_empty(fila_par)) {
            Queue_dequeue(fila_par, &temp);
            if (temp > 0) {
                Stack_push(pilha, temp);
            } else {
                if (!Stack_empty(pilha)) {
                    Stack_pop(pilha, &temp);
                }
            }
        }
        intercalando = !intercalando;
    } 

    printf("Conteudo da pilha: \n");
    Stack_print(pilha);

    Queue_destroy(fila_par);
    Queue_destroy(fila_impar);
    Stack_destroy(pilha);
    return 0;
}