#include "Ponto.h"
#include <stdio.h>

int main(){
    float x, y;
    float novo_x, novo_y, distancia_dos_dois_pontos;
    Ponto *umPonto = Ponto_create(2.4566, 6.877654);
    //A prox linha nao funciona, se descomentar.
    //printf("%f",umPonto->x);
    Ponto_print(umPonto);
    Ponto_get_x(umPonto, &x);
    Ponto_get_y(umPonto, &y);

    printf("Digite uma nova coordenada para x: \n");
    scanf("%f", &novo_x);
    Ponto_set_x(umPonto, novo_x);

    printf("Digite uma nova coordenada para y: \n");
    scanf("%f", &novo_y);
    Ponto_set_y(umPonto, novo_y);

    Ponto *segundoPonto = Ponto_create(3.64553, 9.6754);
    distancia_dos_dois_pontos = Ponto_dist(umPonto, segundoPonto);

    printf("Ponto 1: \n");
    Ponto_print(umPonto);

    printf("Ponto 2: \n");
    Ponto_print(segundoPonto);
    printf("Distancia entre os dois pontos: %.2f\n", distancia_dos_dois_pontos);
    return 0;
}