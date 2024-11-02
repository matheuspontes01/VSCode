#include "TStaticList.h"

int main(void)
{
    TStaticList* lista = lista_create(6);
    lista_insert_end(lista, 5);
    lista_insert_begin(lista, 3);
    lista_sorted(lista, 4);
    lista_print(lista);

    TStaticList* list2 = lista_create(8);
    lista_insert_end(list2, 2);
    lista_insert_end(list2, 4);
    lista_insert_end(list2, 7);
    lista_insert_end(list2, 5);
    lista_insert_end(list2, 10);

    lista_print(list2);

    TStaticList* list3 = TStaticList_intersecao(lista, list2);

    lista_print(list3);
    return 0;
}