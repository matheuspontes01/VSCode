#ifndef TCIRCULARLIST_H
#define TCIRCULARLIST_H
#include <stdbool.h>

typedef struct tcirc_list TCircularList;

TCircularList* TCircularList_Create();

bool TCircularList_insert(TCircularList*, int);

bool TCircularList_insert_end(TCircularList*, int);

void TCircularList_print(TCircularList*);

bool TCircularList_sorted(TCircularList*, int);

void TCircularList_print_Resposta(TCircularList*);

bool TCircularList_delete(TCircularList*, int);

void TCircularList_deleteList(TCircularList*);

#endif //TCIRCULARLIST_H