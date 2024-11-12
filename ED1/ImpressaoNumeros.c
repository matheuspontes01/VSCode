#include <stdio.h>
#include <stdlib.h>

/** O que estudar depois disso:
     * 1) Aprofundar mais em BubbleSort, como funciona 
     * 2) Dar uma revisada em alocacao de memoria em C (ver as funcoes e o que fazem)
     */

int main() {
    int quantidade;

    printf("Digite a quantidade de numeros que ira colocar: \n");
    scanf("%d", &quantidade);

    // Vetor para armazenar todos os numeros lidos pelo usuario
    int *T = malloc(quantidade * sizeof(int));

    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &T[i]);
    }
    
    int *P = malloc(sizeof(int)); // Armazena os vetores na memoria
    int *I = malloc(sizeof(int)); // Armazena os vetores na memoria

    int ip = 0, iim = 0, tamanho_par = 0, tamanho_impar = 0;
    /**
     * ip e iim serao os indices onde serao inseridos os numeros pares e impares separados para cada vetor
     * tamanho_par e tamanho_impar indica a quantidade de elementos nos vetores de pares e impares
     */

    for(int i = 0; i < quantidade; i++) {
        if (T[i] % 2 == 0) {
            tamanho_par++;
            P = realloc(P, tamanho_par * sizeof(int));
            P[ip] = T[i];
            ip++;
        } else {
            tamanho_impar++;
            I = realloc(I, tamanho_impar * sizeof(int));
            I[iim] = T[i];
            iim++;
        }
    }

    // Ordenar os pares de forma crescente
    for (int i = 0; i < tamanho_par - 1; i++) {
        for (int j = 0; j < tamanho_par - 1 - i; j++) {
            if (P[j] > P[j + 1]) {
                int aux = P[j];
                P[j] = P[j + 1];
                P[j + 1] = aux;
            }
        }
    }

    // Ordenar os impares de forma decrescente
    for (int i = 0; i < tamanho_impar - 1; i++) {
        for (int j = 0; j < tamanho_impar - 1 - i; j++) {
            if (I[j] < I[j + 1]) {
                int aux2 = I[j];
                I[j] = I[j + 1];
                I[j + 1] = aux2;
            }
        }
    }

    printf("Impressao dos numeros: \n");

    // Impressao dos pares
    for (int i = 0; i < tamanho_par; i++) {
        printf("%d \n", P[i]);
    }

    // Impressao dos impares apos finalizar a impressao dos pares
    for (int i = 0; i < tamanho_impar; i++) {
        printf("%d \n", I[i]);
    }
    
}