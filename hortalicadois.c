#include <stdio.h>

void relatorioPorSemana(int m[50][2][15], int numProd[15]);
void relatorioPorProdutor(int m[50][2][15]);
void relatorioAnalisedeAbastecimento(int m[50][2][15], int* a, int* r, int* horta, int numProd[15]);

int main(void)
{
    int m[50][2][15] = {0}, numProd[15] = {0}, relatorio, totalalface = 0, totalrepolho = 0, total = 0;
    char op1;
    FILE *ptArq;

    ptArq = fopen("hortalicas", "rb");
    if (ptArq != NULL)
    {
        printf("\nLendo dados do arquivo...\n");
        fread(numProd, sizeof(int), 15, ptArq);
        fread(m, sizeof(int), 2*15*50, ptArq);
        fclose(ptArq);
    }
    else
    {
        printf("\nErro: O arquivo nao foi aberto\n");
    }

    do
    {
        printf("Quais desses relatorios que voce deseja verificar? \n");
        printf("[1] Relatorio por semana\n");
        printf("[2] Relatorio por produtor\n");
        printf("[3] Relatorio de analise de abastecimento\n");
        scanf("%d", &relatorio);
        switch (relatorio)
        {
            case 1:
                relatorioPorSemana(m, numProd);
                break;

            case 2:
                relatorioPorProdutor(m);
                break;

            case 3:
                relatorioAnalisedeAbastecimento(m, &totalalface, &totalrepolho, &total, numProd);
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
        printf("Deseja imprimir mais um relatorio? (s ou n)\n");
        scanf(" %c", &op1);
    }
    while (op1 != 'n');

    return 0;
}

void relatorioPorSemana(int m[50][2][15], int numProd[15])
{
    int s;
    printf("Qual semana? (1 a 15)\n");
    scanf("%d", &s);
    for (int produtor = 0; produtor < numProd[s - 1]; produtor++)
    {
        printf("Produtor %d\n", produtor + 1);
        printf("Quantidade de alfaces entregues nessa semana: %d\n", m[produtor][0][s - 1]);
        printf("Quantidade de repolhos entregues nessa semana: %d\n", m[produtor][1][s - 1]);
    }
}

void relatorioPorProdutor(int m[50][2][15])
{
    int pro;
    printf("De qual produtor voce deseja verificar? \n");
    scanf("%i", &pro);
    for (int semana = 0; semana < 15; semana++)
    {
        printf("Semana %i\n", semana + 1);
        printf("Quantidade de alfaces entregues por esse produtor: %d\n", m[pro - 1][0][semana]);
        printf("Quantidade de repolhos entregues por esse produtor: %d\n", m[pro - 1][1][semana]);
    }
}

void relatorioAnalisedeAbastecimento(int m[50][2][15], int* a, int* r, int* horta, int numProd[15])
{
    *a = 0;
    *r = 0;
    *horta = 0;

    for (int semana = 0; semana < 15; semana++)
    {
        for (int produtor = 0; produtor < numProd[semana]; produtor++)
        {
            *a += m[produtor][0][semana];
            *r += m[produtor][1][semana];
            if (m[produtor][0][semana] == 0 && m[produtor][1][semana] == 0)
            {
                printf("Semana %d, produtor %d, sem entrega\n", semana + 1, produtor + 1);
            }
        }
    }
    *horta = *a + *r;
    printf("Total de alfaces entregues no periodo: %d\n", *a);
    printf("Total de repolhos entregues no periodo: %d\n", *r);
    if (*horta < 500)
    {
        printf("Risco de abastecimento.\n");
    }
    if (*a > 1300 || *r > 1200)
    {
        printf("Superproducao.\n");
    }
}
