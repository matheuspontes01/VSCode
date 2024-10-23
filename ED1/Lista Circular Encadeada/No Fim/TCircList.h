#ifndef TCIRCLIST_H
#define TCIRCLIST_H
#include <stdbool.h>

typedef struct tcirc_list TCircList;

TCircList* TCircList_create();

bool TCircList_insert_begin(TCircList*, int);

bool TCircList_insert_end(TCircList*, int);

#endif //TCIRCLIST_H
