#include "QueuePix.h"
#include <stdio.h>
// A logica desse codigo esta correto,
// porém, nao esta funcionando corretamente,
// provavelmente tem algum erro no arquivo .c
// desse exercício
int main() {
    int id_orig, id_dest, orig, dest, tamanho;
    float valor, v;

    scanf("%d", &tamanho); 
    Queue* f1 = Queue_create(tamanho);
    if (!f1) {
        printf("Erro ao alocar a fila\n");
        return 1;
    }
    while(1) {
        scanf("%d %d %f", &id_orig, &id_dest, &valor);
        if (id_orig == 0 && id_dest == 0 && valor == 0.0) break;
        if (!Queue_full(f1)) {
            Queue_enqueue(f1, id_orig, id_dest, valor);
        } else {
            while(Queue_dequeue(f1, &orig, &dest, &v)) {
                printf("(%d, %d, %.2f),", orig, dest, v);
            }
            putchar('\n');
        }
    }
    if (!Queue_empty(f1)) {
        while(Queue_dequeue(f1, &orig, &dest, &v)) {
            printf("(%d, %d, %.2f),", orig, dest, v);
        }
        putchar('\n');
    }
    Queue_destroy(f1);
    return 0;
}
