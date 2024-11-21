#include "Queue.h"
#include <stdio.h>

int main() {
    Queue* f1 = Queue_create();
    int V[4] = {1, -2, 3, -4};
    for (int i = 0; i < 4; i++) {
        if (!Queue_enqueue(f1, V[i])) {
            printf("Nao pude inserir V[%d] = %d\n", i, V[i]);
        }
    }
    Queue_print(f1);

    Queue* f2 = Queue_reverse(f1);

    Queue_print(f2);

    Queue_remove_negative_numbers(f2);

    Queue_print(f2);
    
    return 0;
}