#ifndef SISTEMA_ESCOLAR
#define SISTEMA_ESCOLAR
#include <stdbool.h>

typedef struct _list TCircularList;

TCircularList* TCircularList_create();

bool TCircularList_insert_end(TCircularList*, char*, float, int);

bool TCircularList_insert_begin(TCircularList*, char*, float, int);

void TCircularList_print(TCircularList*);

float TCircularList_calcular_media(TCircularList*);

#endif