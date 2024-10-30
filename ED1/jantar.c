#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Dar o numero de alunos(as) que participaram dos jantares e o numero de jantares

    int alumnis, jantares;
    while (1) {
        printf("Numero de alumnis e numero de jantares: \n");
        scanf("%d %d", &alumnis, &jantares);

        if (alumnis == 0 && jantares == 0) {
            break;
        }

        int **A = malloc(alumnis * sizeof(int *));
        
        for (int i = 0; i < alumnis; i++) {
            A[i] = malloc(jantares * sizeof(int));
        }

        for (int j = 0; j < jantares; j++) {
            printf("Digite os participantes do jantar %d: \n", j + 1);
            for (int i = 0; i < alumnis; i++) {
                scanf("%d", &A[j][i]);
            }
        }

        char resposta[50];
        strcpy(resposta, "no");

        for (int i = 0; i < alumnis; i++) {
            int soma = 0;
            for (int j = 0; j < jantares; j++) {
                if (A[i][j] == 1) {
                    soma++;
                }
            }
            if (soma == jantares) {
                strcpy(resposta, "yes");
                break;
            }
        }

        printf("%s\n", resposta);
    }
}