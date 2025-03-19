#include <stdio.h>
#include <stdlib.h>

int verificar_quantidade(int n1, int V[], int N) {
    int quantidade = 0;
    for (int i = 0; i < N; i++) {
        if (n1 == V[i]) { // Se tiver um numero igual a esse no vetor, incremento quantidade
            quantidade++;
        }
    }
    return quantidade; // retorno a quantidade de numeros iguais a n1 no vetor V
}

int main() {
    int N;
    do {
        //printf("Digite a quantidade de numeros a serem registrados: \n");
        scanf("%d", &N); // Leio a quantidade de elementos que o usuario deseja registrar
        if (N == 0) break; // Se for igual a 0, o programa encerra
        int *V = malloc(N * sizeof(int)); // Crio o vetor
        for (int i = 0; i < N; i++) {
            scanf("%d", &V[i]); // Leio cada numero dado pelo usuario e coloco no vetor
        }
        
        for (int i = 0; i < N; i++) {
            if (verificar_quantidade(V[i], V, N) % 2 != 0) { // Se a quantidade de numeros iguais nesse vetor for impar, esse numero ficara sem par formado
                printf("%d\n", V[i]); // Imprimo o numero que ficara sem o par
                break; // Interrompo porque ja achei o numero que esta sem par formado
            } // Se for par, todos os numeros terao seus pares formados
        }
    } while (1);
}