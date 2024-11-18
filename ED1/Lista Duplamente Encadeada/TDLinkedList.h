#ifndef TDLINKED_LIST
#define TDLINKED_LIST
#include <stdbool.h>

typedef struct _list TDLinkedList;

TDLinkedList* TDLinkedList_create();

bool TDLinkedList_insert_end(TDLinkedList*, int);

bool TDLinkedList_insert_begin(TDLinkedList*, int);

void TDLinkedList_print(TDLinkedList*);

void TDLinkedList_reverse_print(TDLinkedList*);

bool TDLinkedList_sorted(TDLinkedList*, int);

bool TDLinkedList_delete_oneValue(TDLinkedList*, int);

bool TDLinkedList_deleteList(TDLinkedList*);

TDLinkedList* TDLinkedList_intercalar(TDLinkedList*, TDLinkedList*);

TDLinkedList* TDLinkedList_intercalar_ordenado(TDLinkedList*, TDLinkedList*);

float TDLinkedList_calcular_media(TDLinkedList*);

TDLinkedList* TDLinkedList_gerar_lista_impares(TDLinkedList*);

bool TDLinkedList_equals_list(TDLinkedList*, TDLinkedList*);

TDLinkedList* TDLinkedList_reverse_list(TDLinkedList*);

bool TDLinkedList_ehDigito(char);

TDLinkedList* TDLinkedList_ordem_caracteres(TDLinkedList*, TDLinkedList*, TDLinkedList*);

bool TDLinkedList_sorted_decrescente(TDLinkedList*, int);

TDLinkedList* TDLinkedList_concatenar(TDLinkedList* list1, TDLinkedList* list2);

#endif