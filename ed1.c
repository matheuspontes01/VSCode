// Busca binaria
// Indices de acesso ao vetor serao inteiros

// Teste de busca binaria iterativa e recursiva (para estudar e analisar)

#include <stdio.h>

int BuscaBinaria(int *vet, int chave, int inicio, int fim); // Recursiva
int BuscaBinariaIterativa(int *vet, int chave, int fim);

int main(void)
{
    int vet[10] = {13, 14, 19, 43, 47, 52, 65, 82, 89, 91};
    int valor, valor1;

    printf("Digite um valor a ser buscado: \n");
    scanf("%d", &valor);

    printf("Resultado (Recursiva): %d\n", BuscaBinaria(vet, valor, 0, 9));

    printf("Digite um valor a ser buscado: \n");
    scanf("%d", &valor1);

    printf("Resultado (Iterativa): %d\n", BuscaBinariaIterativa(vet, valor1, 9));

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

int BuscaBinariaIterativa(int *vet, int chave, int fim)
{
    int inicio = 0;
    int meio = (inicio + fim)/2;

    while (inicio <= fim)
    {
        if (chave == vet[meio])
        {
            return meio;
        }
        else
        {
            if (chave < vet[meio])
            {
                fim = meio - 1;
            }
            else
            {
                inicio = meio + 1;
            }
        }
        meio = (inicio + fim)/2;
    }
    return -1; // elemento nao encontrado
}