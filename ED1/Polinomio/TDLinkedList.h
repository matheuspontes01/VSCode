#ifndef TDLINKED_LIST
#define TDLINKED_LIST
#include <stdbool.h>

typedef struct _list TDLinkedList;

TDLinkedList* inicializar_polinomio();

bool inserir_polinomio(TDLinkedList*, int, int);

void imprimir_polinomio(TDLinkedList*);

bool eliminar_termo(TDLinkedList*, int);

bool reiniciar_polinomio(TDLinkedList*);

int calcular_polinomio(TDLinkedList*, int n);

#endif