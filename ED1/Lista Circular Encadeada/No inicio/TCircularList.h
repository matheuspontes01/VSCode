#ifndef TCIRCULARLIST_H
#define TCIRCULARLIST_H
#include <stdbool.h>

typedef struct tcirc_list TCircularList;

TCircularList* TCircularList_Create();

bool TCircularList_insert(TCircularList*, int);

bool TCircularList_insert_end(TCircularList*, int);

void TCircularList_print(TCircularList*);

bool TCircularList_Resposta(TCircularList*, int);

bool TCircularList_sorted(TCircularList*, int);

void TCircularList_print_Resposta(TCircularList*);

bool TCircularList_delete(TCircularList*, int);

bool TCircularList_deleteList(TCircularList*);

int TCircularList_contar_elementos(TCircularList*);

bool TCircularList_insert_no_inicio(TCircularList*, int);

TCircularList* TCircularList_concatenar(TCircularList*, TCircularList*);

TCircularList* TCircularList_intercalar(TCircularList*, TCircularList*);

bool TCircularList_info_igual(TCircularList*, int);

TCircularList* TCircularList_intersecao(TCircularList*, TCircularList*);

float TCircularList_calcular_media(TCircularList*);

bool TCircularList_insert_position(TCircularList*, int, char, int);

bool TCircularList_equals_list(TCircularList*, TCircularList*);

TCircularList* TCircularList_reverse_list(TCircularList*);

bool TCircularList_remove_n_firstElements(TCircularList*, int);


#endif //TCIRCULARLIST_H