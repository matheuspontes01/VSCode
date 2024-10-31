#include <stdio.h>
#include <stdlib.h>

/*
int verificarPontoMaximo(int gols_comprados, int V[][], int partidas) {
    int pontuacao = 0; // pontuacao garantida nas vitorias (+3)
    for (int i = 0; i < partidas; i++) {
        if (V[partidas][0] > V[partidas][1]) {
            pontuacao = pontuacao + 3;
        } else if (V[partidas][0] == V[partidas][1] && gols_comprados != 0) {
            gols_comprados--;
            pontuacao = pontuacao + 3;
        } else if(V[partidas][0] < V[partidas][1] && gols_comprados != 0) {
            for (int j = V[partidas][0]; j = V[partidas][1] + 1; j++) {
                V[partidas][0]++;
                if (gols_comprados == 0) break;
                gols_comprados--;
            }
            if (V[partidas][0] == V[partidas][1]) {
                pontuacao = pontuacao + 1;
            } else if (V[partidas][0] > V[partidas][1]) {
                pontuacao = pontuacao + 3;
            }
        }
    }
    return pontuacao;
}
*/

int main() {

    int partidas, compra_gols = 0;

    printf("Digite o numero de partidas que o seu time jogou e quantos gols seu time pode comprar: \n");
    scanf("%d %d", &partidas, &compra_gols);

    int **V = malloc(partidas * sizeof(int *));

    for (int i = 0; i < partidas; i++) {
        V[i] = malloc(2*sizeof(int));
    }

    for (int i = 0; i < partidas; i++) {
        printf("numero de gols marcados pelo seu time | quantos gols seu time sofreu\n");
        scanf("%d %d", &V[i][0], &V[i][1]);
    }

    int pontuacao = 0; // pontuacao garantida nas vitorias (+3)

    for (int i = 0; i < partidas; i++) {
        if (V[i][0] > V[i][1]) {
            pontuacao = pontuacao + 3;
        } else if (V[i][0] == V[i][1]) {
            if (compra_gols > 0) {
                compra_gols--;
                pontuacao = pontuacao + 3;
            } else {
                pontuacao++;
            }
        } else if(V[i][0] < V[i][1] && compra_gols > 0) {
            while (V[i][0] < V[i][1] && compra_gols > 0) {
                V[i][0]++;
                compra_gols--;
            }
            if (V[i][0] == V[i][1]) {
                pontuacao = pontuacao + 1;
            } else if (V[i][0] > V[i][1]) {
                pontuacao = pontuacao + 3;
            }
        }
    }
    
    printf("Pontuacao maxima: %d\n", pontuacao);

}