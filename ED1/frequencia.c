#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int vezes_info_igual(int V[], int info, int N) {
    int vezes = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] == info) {
            vezes++;
        }
    }
    return vezes;
}

bool info_igual(int V[], int info, int N) {
    for (int i = 0; i < N; i++) {
        if (V[i] == info) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;

    printf("Quantidade de valores para serem lidos: \n");
    scanf("%d", &N);

    int *V = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("Digite um valor: \n");
        scanf("%d", &V[i]);
    }
    // bubble sort
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N - i - 1; j++){
            if (V[j] > V[j + 1]){ // se trocar para 'menor que', a lista fica em ordem decrescente
                int n1 = V[j];
                V[j] = V[j + 1];
                V[j + 1] = n1;
            }
        }
    }
    

    for (int i = 0; i < N; i++) {
        if (!info_igual(V, V[i], i)) {
            printf("%d aparece %d vez(es)\n", V[i], vezes_info_igual(V, V[i], N));
        }
    }
}