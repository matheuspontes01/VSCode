#include "TCircularList.h"
#include <stdio.h>

int main() {
    TCircularList *list = TCircularList_Create();
    /*
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
    */

    int V[] = {4, 2, 7, 1};

    for (int i = 0; i < 4; i++) {
        if (!TCircularList_sorted(list, V[i])) {
            printf("Erro ao inserir o valor: %d\n", V[i]);
        }
    }

    TCircularList_print(list);

    printf("Quantidade de elementos: %d\n", TCircularList_contar_elementos(list));

    TCircularList_insert_no_inicio(list, 10);

    TCircularList_print(list);

    TCircularList *list2 = TCircularList_Create();

    int R[] = {7, 2, 18};

    for (int i = 0; i < 3; i++) {
        if (!TCircularList_sorted(list2, R[i])) {
            printf("Erro ao inserir o valor: %d\n", R[i]);
        }
    }

    TCircularList_print(list2);

    //TCircularList* list3 = TCircularList_concatenar(list, list2);
    //printf("Lista concatenada: \n");
    //TCircularList_print(list3);

    printf("Lista 1: \n");
    TCircularList_print(list);

    printf("Lista 2: \n");
    TCircularList_print(list2);

    printf("Lista intercalada: \n");
    //TCircularList* list4 = TCircularList_intercalar(list, list2);

    //TCircularList_print(list4);

    printf("Intersecao da lista 1 e 2: \n");
    TCircularList* list5 = TCircularList_intersecao(list, list2);

    TCircularList_print(list5);
    
    printf("Media dos elementos da lista 5: %.2f\n", TCircularList_calcular_media(list5));


    int info_list, info_insert;
    char direction;
    printf("Numero da info que esta na lista || posicao com a info que esta na lista ('e' ou 'd')|| info que deseja inserir \n");
    scanf("%d %c %d", &info_list, &direction, &info_insert);

    TCircularList_insert_position(list5, info_list, direction, info_insert);

    TCircularList_print(list5);
}
