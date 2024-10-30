#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool qtd_par_correto(int numero, char pe, int V[], char T[], int n) {
    for (int i = 0; i < n; i++) {
        if (V[i] == numero && T[i] != pe) {
            return true;
        }
    }
    return false;
}


int main() {
    int n = 0;

    //printf("Digite a quantidade de botas individuais: \n");
    scanf("%d", &n);

    int *B = malloc(n * sizeof(int));
    char *T = malloc(n * sizeof(char));

    for (int i = 0; i < n; i++) {
        //printf("Digite o numero da bota e o pe (L ou D): \n");
        scanf("%d %c", &B[i], &T[i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        if (qtd_par_correto(B[i], T[i], B, T, i)) {
            total++;
        }
    }

    //printf("Quantidade de pares: %d\n", total);
    printf("%d", &total);
}