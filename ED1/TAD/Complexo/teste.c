#include "complexo.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
  float x, y, a, b, z, w, c, d;
  
  printf("Escolha um numero para ser a parte real do numero complexo 1: \n");
  scanf("%f", &x);
  printf("Escolha um numero para ser a parte imaginaria do numero complexo 1: \n");
  scanf("%f", &y);

  Complexo* nc1 =  Complexo_create(x, y);
  
  printf("Escolha um numero para ser a parte real do numero complexo 2: \n");
  scanf("%f", &a);
  printf("Escolha um numero para ser a parte imaginaria do numero complexo 2: \n");
  scanf("%f", &b);
  
  Complexo* nc2 = Complexo_create(a, b);
  
  printf("Número complexo 1: %+.1f %+.1fi\n", x, y); 
  printf("Número complexo 2: %+.1f %+.1fi\n", a, b);
  
  Complexo* nc3 = somar_complexos(nc1, nc2);
  
  Complexo_get_real(nc3, &z);
  Complexo_get_imaginaria(nc3, &w);
  
  printf("Número complexo feito na soma = %+.1f %+.1f\n", z, w);

  Complexo* nc4 = subtrair_complexos(nc1, nc2);
  
  Complexo_get_real(nc4, &c);
  Complexo_get_imaginaria(nc4, &d);
  
  printf("Número complexo feito na subtração = %+.1f %+.1f\n", c, d);
  
  
  destroy_complexo(nc1);
  destroy_complexo(nc2);
  destroy_complexo(nc3);
  destroy_complexo(nc4);
  
}
