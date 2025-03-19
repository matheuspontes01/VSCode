#include <stdio.h>
#include <stdlib.h>

int quantoTempo(int funcionarios, int clientes, int tempo_de_itens, int itensCesta) {
    int tempo = 0;
    for (int i = 0; i < funcionarios; i++) {
        for (int j = 0; j < clientes; j++) {
            tempo += tempo_de_itens*itensCesta;
        }
    }
    return tempo;
}

int main(void) {
    int N, M, tempo = 0;

    printf("Digite o numero de funcionarios no caixa e o numero de clientes: \n");
    scanf("%d %d", &N, &M);

    int *F = malloc(N * sizeof(int));
    int *C = malloc(M * sizeof(int));

    if (F == NULL || C == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int tempo_de_itens = 0, itensCesta = 0;

    for (int i = 0; i < N; i++) {
        printf("Quanto tempo leva para o funcionario %d para processar um item: \n", i);
        scanf("%d", &F[i]);
        tempo_de_itens += F[i]; 
    }

    for (int j = 0; j < M; j++) {
        printf("Quantos itens o cliente %d tem em sua cesta: \n", j);
        scanf("%d", &C[j]);
        itensCesta += C[j];
    }
    
    tempo = tempo_de_itens*itensCesta;

    printf("Tempo: %d\n", tempo);

    return 0;
}
