#include <stdio.h>

void coletarDados_um(int r[50][4][2], int totaltrimestre[2], int n1);
void coletarDados_dois(int r[50][4][2], int totaltrimestre[2], int n2);

int main(void) // Parte principal
{ 
    int p[50][4][2] = {0}, ttri[2] = {0}, prepapel[2][2] = {0}, pedidopri, pedidoseg;
    FILE *ptArq;

    printf("Qual a quantidade de pedidos no primeiro trimestre? (Maximo de 50 pedidos)\n");
    scanf("%d", &pedidopri);

    printf("Qual a quantidade de pedidos no segundo trimestre? (Maximo de 50 pedidos)\n");
    scanf("%d", &pedidoseg);

    coletarDados_um(p, ttri, pedidopri); // Trimestre 1
    coletarDados_dois(p ,ttri, pedidoseg); // Trimestre 2

    ptArq = fopen("pedidos", "wb");

    if (ptArq != NULL)
    {
        printf("Salvando dados...\n");
        fwrite(ttri, sizeof(int), 2, ptArq);
        fwrite(prepapel, sizeof(int), 2*2, ptArq);
        fwrite(p, sizeof(int), 50*4*2, ptArq);
        fclose(ptArq);
    }
    else
    {
        printf("O arquivo nao foi salvo.\n");
    }
    
    return 0;
}

void coletarDados_um(int r[50][4][2], int totaltrimestre[2], int n1) 
{
    int pedido, trimestre = 0;
    printf("Trimestre %d\n", trimestre + 1);
    totaltrimestre[0] = n1; // Salvar o total de pedidos de cada trimestre
    for (pedido = 1; pedido <= n1; pedido++)
    {
        printf("Pedido %d\n", pedido);
        r[pedido-1][0][trimestre] = pedido; 
        printf("Codigo do pedido %d\n", pedido);
        printf("Quantidade de exemplares: \n");
        scanf("%d", &r[pedido-1][1][trimestre]);
        printf("Numero de paginas: \n");
        scanf("%d", &r[pedido-1][2][trimestre]);
        printf("Tipo de papel: (1- couche, 2- sulfite)\n");
        scanf("%d", &r[pedido-1][3][trimestre]);
    }
}

void coletarDados_dois(int r[50][4][2], int totaltrimestre[2], int n2) 
{
    int pedido, trimestre = 1;
    printf("Trimestre %d\n", trimestre + 1);
    totaltrimestre[1] = n2; // Salvar o total de pedidos de cada trimestre
    for (pedido = 1; pedido <= n2; pedido++)
    {
        printf("Pedido %d\n", pedido);
        r[pedido-1][0][trimestre] = pedido; 
        printf("COdigo do pedido %d\n", pedido);
        printf("Quantidade de exemplares: \n");
        scanf("%d", &r[pedido-1][1][trimestre]);
        printf("Numero de paginas: \n");
        scanf("%d", &r[pedido-1][2][trimestre]);
        printf("Tipo de papel: (1- couche, 2- sulfite)\n");
        scanf("%d", &r[pedido-1][3][trimestre]);
    }
}



