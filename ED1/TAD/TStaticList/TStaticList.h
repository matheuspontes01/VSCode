#ifndef TSTATIC_LIST_H
#define TSTATIC_LIST_H
#include <stdbool.h>

typedef struct _lista TStaticList;

TStaticList* lista_create(unsigned int);

bool lista_insert_end(TStaticList*, int);

bool lista_insert_begin(TStaticList*, int);

bool lista_sorted(TStaticList*, int);

bool lista_is_full(TStaticList*);

void lista_print(TStaticList*);

#endif

