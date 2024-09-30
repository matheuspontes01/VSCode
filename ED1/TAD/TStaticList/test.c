#include "TStaticList.h"

int main(void)
{
    TStaticList* lista = lista_create(6);
    lista_insert_end(lista, 5);
    lista_insert_begin(lista, 3);
    lista_sorted(lista, 4);
    lista_print(lista);

    TStaticList_deleteOneValue(lista, 5);
    lista_print(lista);
    return 0;
}