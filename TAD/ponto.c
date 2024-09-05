#include "Ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct _ponto{
    float x, y;
};

Ponto* Ponto_create(float x, float y) {
    Ponto* novo = (Ponto*) malloc(sizeof(Ponto));
    if(novo!=NULL){
        novo->x = x; // (*novo).x = x; pode ser usado dessa maneira tambem
        novo->y = y; // (*novo).y = y; pode ser usado dessa maneira tambem
    }
    return novo; // Retorna o endereço do ponto criado
}

void Ponto_print(Ponto* ponto){
    if(ponto!=NULL)
        printf("(%.2f,%.2f)\n", ponto->x, ponto->y); // Acessa o valor de x e y para imprimir
}

void Ponto_destroy(Ponto* ponto){
    free(ponto);
}

void Ponto_get_x(Ponto* ponto, float* coordenada_x){
    *coordenada_x = ponto->x;
}

void Ponto_get_y(Ponto* ponto, float* coordenada_y){
    *coordenada_y = ponto->y; 
}

void Ponto_set_x(Ponto* ponto, float x){
    ponto->x = x;
    printf("Nova coordenada de x: %.2f\n", ponto->x);
}

void Ponto_set_y(Ponto* ponto, float y){
    ponto->y = y;
    printf("Nova coordenada de y: %.2f\n", ponto->y);
}

float Ponto_dist(Ponto* p1, Ponto* p2){
    float distancia_euclidiana = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    return distancia_euclidiana;
}
