#include "complexo.h"
#include <stdlib.h>
#include <stdio.h>

struct _complexo{
  float x; //real
  float y; //imaginaria
};

Complexo* Complexo_create(float x, float y){
  Complexo* novo_complexo = (Complexo*) malloc (sizeof(Complexo));
  if (novo_complexo != NULL){
    novo_complexo->x = x;
    novo_complexo->y = y;
  }
  return novo_complexo;
}

void destroy_complexo(Complexo* C){
  free(C);
}

Complexo* somar_complexos(Complexo* c1, Complexo* c2){
  if (c1 == NULL || c2 == NULL) return NULL;
  return Complexo_create(c1->x + c2->x, c1->y + c2->y);
}

Complexo* subtrair_complexos(Complexo* c1, Complexo* c2){
  if (c1 == NULL || c2 == NULL) return NULL;
  return Complexo_create(c1->x - c2->x, c1->y - c2->y);
}

void Complexo_get_real(Complexo* C, float* real)
{
    if (C != NULL && real != NULL) {
        *real = C->x;
    }
}

void Complexo_get_imaginaria(Complexo* C, float* imaginaria)
{
    if (C != NULL && imaginaria != NULL) {
        *imaginaria = C->y;
    }
}