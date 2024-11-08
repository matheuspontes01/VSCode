#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdbool.h>

typedef struct _list TLinkedList;

TLinkedList* TLinkedList_create();
bool TLinkedList_insert_end(TLinkedList*, int, float, int);
void TLinkedList_Toninho(TLinkedList*);

#endif