#include "TDLinkedList.h"
#include <stdio.h>

int main(void) {
    TDLinkedList* list = inicializar_polinomio();

    inserir_polinomio(list, 6, 3);

    inserir_polinomio(list, 2, 2);

    inserir_polinomio(list, 5, 0);
    
    printf("Lista criada: \n");
    imprimir_polinomio(list);

    printf("Valor de P(2): %d\n", calcular_polinomio(list, 2));

    printf("Lista sem o termo de grau 2: \n");
    eliminar_termo(list, 2);
    imprimir_polinomio(list);

    printf("Lista vazia: \n");
    reiniciar_polinomio(list);
    imprimir_polinomio(list);
}   