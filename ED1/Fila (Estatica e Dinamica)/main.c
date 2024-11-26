#include "Queue.h"
#include <stdio.h>

int main() {
    Queue* f1 = Queue_create();
    
    int V[] = {25, 18};
    for (int i = 0; i < 2; i++) {
        if (!Queue_sorted(f1, V[i])) {
            printf("Nao pude inserir V[%d] = %d\n", i, V[i]);
        }
    }  
    printf("Lista normal.\n");
    Queue_print(f1);

    //Queue_reverse_static(f1);
    //printf("Lista invertida.\n");
    //Queue_print(f1);

    //Queue_media(f1);

    Queue* f2 = Queue_create();
    int M[] = {45, 22, 23};
    for (int i = 0; i < 3; i++) {
        if (!Queue_sorted(f2, M[i])) {
            printf("Nao pude inserir V[%d] = %d\n", i, M[i]);
        }
    }
    Queue_print(f2);

    Queue_concatenate(f1, f2);
    
    Queue_print(f1);
/*
    //Queue_compare_size(f1, f2);

    //Queue_pares_e_impares(f1);
    //Queue_pares_e_impares(f2);

    Queue_reverse_static(f2);
    Queue_print(f2);
    */
    //Queue* f3 = Queue_create();

    //Queue_fill_queue(f1, f2, f3);
    //Queue_concatenate(f1, f2);
    //Queue_print(f1);
    //Queue_print(f3);

    /*
    Queue* f2 = Queue_reverse(f1);

    Queue_print(f2);

    Queue_remove_negative_numbers(f2);

    Queue_print(f2);
    */
    return 0;
}