#include <stdio.h>

// https://judge.beecrowd.com/pt/problems/view/2252
// numero de digitos de senha
// nivel de oleosidade de cada numero (0 a 9)

typedef struct {
    int digito;
    float oleosidade;
} Oleosidade;

void BubbleSort(Oleosidade numeros[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i; j++) {
            if (numeros[j].oleosidade < numeros[j + 1].oleosidade) {
                Oleosidade aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}

void descobrirSenha(Oleosidade oleosidades[], int digitos) {
    BubbleSort(oleosidades, 10);

    for (int i = 0; i < digitos; i++) {
        printf("%d", oleosidades[i].digito);
    }
    printf("\n");
}


int main() { // Preciso tirar de perguntar o numero dos casos, e fazer isso funcionar infinitamente (dar um jeito de fazer uma parada)
    Oleosidade oleosidades[10];
    int digitos, casos = 1;

    for (int i = 0; i < 10; i++) {
        oleosidades[i].digito = i;
    }

    while (1) {
        printf("Digitos da senha: \n");
        scanf("%d", &digitos);
        
        if (digitos == -1) break;

        for (int i = 0; i < 10; i++) {
            scanf("%f", &oleosidades[i].oleosidade);
        }

        printf("Caso %d: ", casos);
        descobrirSenha(oleosidades, digitos);

        for (int i = 0; i < 10; i++) {
            oleosidades[i].digito = i;
            oleosidades[i].oleosidade = 0.0;
        }

        casos++;
    }
}