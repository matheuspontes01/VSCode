#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct _complexo Complexo;
/**
  Criacao de numero complexo
  @param float x parte real
  @param float y parte imaginaria
*/
Complexo* Complexo_create(float x, float y);
/**
  Destruir numero complexo para liberar memoria
  @param Complexo* C numero complexo
*/
void destroy_complexo(Complexo* C);
/**
  Somar dois numeros complexos e retorna um novo tipo que é a soma
  @param Complexo* C numero complexo 1
  @param Complexo* C1 numero complexo 2
  @return soma dos dois numeros complexos
*/
Complexo* somar_complexos(Complexo* C, Complexo* C2);
/**
  Subtrair dois numeros complexos e retorna um novo tipo que é a subtração
  @param Complexo* C numero complexo 1
  @param Complexo* C1 numero complexo 2
  @return subtracao dos dois numeros complexos
*/
Complexo* subtrair_complexos(Complexo* C, Complexo* C2);

void Complexo_get_real(Complexo* C, float* real);

void Complexo_get_imaginaria(Complexo* C, float* imaginaria);

#endif