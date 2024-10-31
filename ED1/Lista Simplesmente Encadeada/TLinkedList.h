#ifndef TLINKED_LIST
#define TLINKED_LIST
#include <stdbool.h>

typedef struct _list TLinkedList;

TLinkedList* TLinkedList_create();
bool TLinkedList_insert_begin(TLinkedList*, int);
bool TLinkedList_insert_end(TLinkedList*, int);
void TLinkedList_print(TLinkedList*);
//bool TLinkedList_delete(TLinkedList*, int);
//bool TLinkedList_insert_middle(TLinkedList*, int);
//void TLinkedList_deleteAll(TLinkedList*);

// Funcoes criadas pelo professor
//bool TLinkedList_delete_from_begin(TLinkedList*, int*);
//bool TLinkedList_delete_info(TLinkedList*, int);
bool TLinkedList_deleteOneValue(TLinkedList*, int);
bool TLinkedList_deleteList(TLinkedList*);

TLinkedList* TLinkedList_intercalar(TLinkedList*, TLinkedList*);

bool TLinkedList_sorted(TLinkedList*, int);

TLinkedList* TLinkedList_intercalar_ordenadamente(TLinkedList*, TLinkedList*);

#endif