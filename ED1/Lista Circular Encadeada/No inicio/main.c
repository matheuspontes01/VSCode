#include "TCircularList.h"
#include <stdio.h>

int main() {
    TCircularList *list = TCircularList_Create();

    int N, M;
    printf("Entrada: ");
    scanf("%d %d", &N, &M);

    int V[N];
    for (int i = 0; i < N; i++) {
        V[i] = i + 1;
        if (!TCircularList_insert_end(list, V[i])){
            printf("Erro ao inserir V[%d]\n", V[i]);
        }
    }

    TCircularList_sorted(list, M);

    TCircularList_print_Resposta(list);
}
