#include <stdio.h>
#include <time.h>

int BuscaBinaria(int *vet, int chave, int inicio, int fim);

int main(void)
{
    int vet[10000], valor;
    FILE *arquivo;

    for (int i = 0; i < 10000; i++)
    {
        vet[i] = i + 1;
    }

    printf("Digite um valor a ser buscado: \n");
    scanf("%d", &valor);

    clock_t iniciar, parar;

    iniciar = clock();
    int resultado = BuscaBinaria(vet, valor, 0, 9999);
    parar = clock();

    double tempo_de_execucao = (double)(parar - iniciar) / CLOCKS_PER_SEC;

    printf("Resultado (indice): %d\n", resultado);
    printf("Tempo de execucao: %f segundos\n", tempo_de_execucao);

    arquivo = fopen("resultado.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Resultado (indice): %d\n", resultado);
    fprintf(arquivo, "Tempo de execucao: %f segundos\n", tempo_de_execucao);

    fclose(arquivo);

    printf("Resultado e tempo gravados no arquivo resultado.txt\n");

    return 0;
}

int BuscaBinaria(int *vet, int chave, int inicio, int fim)
{
    while (inicio <= fim)
    {
        int meio = (inicio + fim)/2;
        if (chave == vet[meio])
        {
            return meio;
        }
        else
        {
            if (chave < vet[meio])
            {
                return BuscaBinaria(vet, chave, inicio, meio-1);
            }
            else
            {
                return BuscaBinaria(vet, chave, meio + 1, fim);
            }
        }
    }
    return -1; // elemento nao encontrado
}