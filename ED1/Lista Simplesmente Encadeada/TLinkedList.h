#ifndef TLINKED_LIST
#define TLINKED_LIST
#include <stdbool.h>

typedef struct _list TLinkedList;

TLinkedList* TLinkedList_create();
bool TLinkedList_insert_begin(TLinkedList*, int);
bool TLinkedList_insert_end(TLinkedList*, int);
void TLinkedList_print(TLinkedList*);
bool TLinkedList_delete(TLinkedList*, int);
bool TLinkedList_insert_middle(TLinkedList*, int);
void TLinkedList_deleteAll(TLinkedList*);

// Funcoes criadas pelo professor
bool TLinkedList_delete_from_begin(TLinkedList*, int*);
bool TLinkedList_delete_info(TLinkedList* lista, int info);

#endif