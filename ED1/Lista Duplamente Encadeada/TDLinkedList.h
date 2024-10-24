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

#endif