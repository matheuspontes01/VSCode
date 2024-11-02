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
// Funcoes abaixo feitas pelo professor
bool TStaticList_delete_end(TStaticList*, int*);
bool TStaticList_delete_begin(TStaticList*, int*);
bool TStaticList_delete_at(TStaticList*, int*, int);

bool TStaticList_delete_beginMine(TStaticList*);
bool TStaticList_deleteOneValue(TStaticList*, int);
bool lista_is_empty(TStaticList*);

bool TStaticList_is_empty(TStaticList*);

TStaticList* TStaticList_intersecao(TStaticList*, TStaticList*);

bool TStaticList_info_igual(TStaticList*, int);

#endif

