#include <stdio.h>

void mostraTrimestre(int r[50][4][2], int totaltrimestre[2]);
void inserirPedido(int r[50][4][2], int totaltrimestre[2]);
int editarPedido(int r[50][4][2], int totaltrimestre[2]);
void precoPapel(int papel[2][2]);
float precoPedido(int r[50][4][2], int papel[2][2], int totaltrimestre[2], float precototal[2]);
int mostraPedido(int r[50][4][2], float preco, int totaltrimestre[2]);
void mostrarPapel(int prepapel[2][2]);
void faturamento(float precototal[2]);

int main(void) // Parte principal
{
    int p[50][4][2] = {0}, ttri[2] = {0}, prepapel[2][2] = {0}, relatorio;
    float precoped, pt[2] = {0};
    FILE *ptArq;

    ptArq = fopen("pedidos", "rb");
    
    if (ptArq != NULL)
    {
        printf("Lendo dados do arquivo...\n");
        fread(ttri, sizeof(int), 2, ptArq);
        fread(prepapel, sizeof(int), 2*2, ptArq);
        fread(p, sizeof(int), 50*4*2, ptArq);
        fclose(ptArq);
    }
    else
    {
        printf("O arquivo nao foi aberto.\n");
    }

    precoPapel(prepapel);
    precoped = precoPedido(p, prepapel, ttri, pt); // Atribuir o valor do pedido gerado na função 'precoPedido' para a variável precoped
    // Menu
    do
    {
        printf("Menu: \n");
        printf("[1] Mostra trimestre\n");
        printf("[2] Inserir pedido\n");
        printf("[3] Editar pedido\n");
        printf("[4] Mostrar pedido\n");
        printf("[5] Preço do papel\n");
        printf("[6] Faturamento\n");
        printf("[7] Sair do programa\n");
        scanf("%d", &relatorio);

        switch (relatorio)
        {
            case 1:
            mostraTrimestre(p, ttri);
            break;

            case 2:
            inserirPedido(p, ttri);
            precoped = precoPedido(p, prepapel, ttri, pt); // Recalcular o preço do pedido ao inserir um novo
            break;

            case 3:
            editarPedido(p, ttri);
            precoped = precoPedido(p, prepapel, ttri, pt); // Recalcular o preço do pedido ao editar um pedido
            break;

            case 4:
            mostraPedido(p, precoped, ttri);
            break;

            case 5:
            mostrarPapel(prepapel);
            break;

            case 6:
            faturamento(pt);
            break;

            case 7:
            printf("Saindo do programa.\n");
            return 0;

            default:
            printf("Opção inválida.\n");
            break;
        }
    }
    while (relatorio != 7);

    return 0;
}

void mostraTrimestre(int r[50][4][2], int totaltrimestre[2]) // Função 'mostraTrimestre' para mostrar os dados de cada pedido do trimestre escolhido
{
    int trimestre;
    printf("Qual trimestre? (1 ou 2)\n");
    scanf("%d", &trimestre);
    trimestre--;
    printf("Quantidade de pedidos do trimestre %d: %d\n", trimestre + 1, totaltrimestre[trimestre]);
    for (int pedido = 0; pedido < totaltrimestre[trimestre]; pedido++)
    {
        printf("Código do pedido: %d\n", r[pedido][0][trimestre]);
        printf("Quantidade de exemplares: %d\n", r[pedido][1][trimestre]);
        printf("Número de páginas: %d\n", r[pedido][2][trimestre]);
        printf("Tipo de papel: %d\n", r[pedido][3][trimestre]);
    }
}

void inserirPedido(int r[50][4][2], int totaltrimestre[2]) // Função 'inserirPedido' para inserir um pedido novo
{
    int trimestre, pedido;
    printf("Qual trimestre? (1 ou 2)\n");
    scanf("%d", &trimestre);
    trimestre--;
    int codigonovo = totaltrimestre[trimestre] + 1; // Número da linha nova para ser inserida na matriz
    pedido = codigonovo - 1; // Número da linha nova atribuida para a variável 'pedido'
    if (totaltrimestre[trimestre] <= 50)
    {
        r[pedido][0][trimestre] = codigonovo;
        printf("Código do pedido: %d (Digite o código do pedido para ser salvo)\n", codigonovo);
        scanf("%d", &r[pedido][0][trimestre]);
        printf("Quantidade de exemplares: \n");
        scanf("%d", &r[pedido][1][trimestre]);
        printf("Número de páginas: \n");
        scanf("%d", &r[pedido][2][trimestre]);
        printf("Tipo de papel: (1- couché, 2- sulfite)\n");
        scanf("%d", &r[pedido][3][trimestre]);
        totaltrimestre[trimestre]++; // Adicionar mais um pedido no trimestre
    }
    else
    {
        printf("Máximo de pedidos ultrapassados.\n");
    }
}

int editarPedido(int r[50][4][2], int totaltrimestre[2]) // Função 'editarPedido', escolher número do pedido, mudar cada dado do pedido e ler novamente os dados
{
    int pedido, trimestre;
    printf("Numero do pedido? \n");
    scanf("%d", &pedido);
    pedido--;
    if (pedido < totaltrimestre[0])
    {
        trimestre = 0;
        printf("Trimestre %d\n", trimestre + 1);
        printf("Quantidade de pedidos do trimestre %d: %d\n", trimestre + 1, totaltrimestre[trimestre]);
        printf("Código do pedido: %d\n", r[pedido][0][trimestre]);
        printf("Quantidade de exemplares: \n");
        scanf("%d", &r[pedido][1][trimestre]);
        printf("Número de páginas: \n");
        scanf("%d", &r[pedido][2][trimestre]);
        printf("Tipo de papel: (1- couché, 2- sulfite)\n");
        scanf("%d", &r[pedido][3][trimestre]);
        return 1;
    }
    else
    {
        if (pedido < totaltrimestre[1])
        {
            trimestre = 1;
            printf("Trimestre %d\n", trimestre + 1);
            printf("Quantidade de pedidos do trimestre %d: %d\n", trimestre + 1, totaltrimestre[trimestre]);
            printf("Código do pedido: %d\n", r[pedido][0][trimestre]);
            printf("Quantidade de exemplares: \n");
            scanf("%d", &r[pedido][1][trimestre]);
            printf("Número de páginas: \n");
            scanf("%d", &r[pedido][2][trimestre]);
            printf("Tipo de papel: (1- couché, 2- sulfite)\n");
            scanf("%d", &r[pedido][3][trimestre]);
            return 1;
        }
        else
        {
            printf("Pedido inválido.\n");
            return 0;
        }
    }
}

void precoPapel(int papel[2][2]) // Função precopapel para registrar o preço dos papeis de cada tipo e de cada trimestre
{
    for (int trimestre = 0; trimestre < 2; trimestre++)
    {
        printf("Qual será o preço do papel couché no trimestre %d? \n", trimestre + 1);
        scanf("%d", &papel[0][trimestre]);
        printf("Qual será o preço do papel sulfite no trimestre %d? \n", trimestre + 1);
        scanf("%d", &papel[1][trimestre]);
    }
}

float precoPedido(int r[50][4][2], int papel[2][2], int totaltrimestre[2], float precototal[2]) // Função precoPedido para calcular o preço do pedido
{
    float tpedido = 0;
    for (int trimestre = 0; trimestre < 2; trimestre++)
    {
        precototal[trimestre] = 0;
        for (int pedido = 0; pedido < totaltrimestre[trimestre]; pedido++)
        {
            int tipo = r[pedido][3][trimestre] - 1; // Tipo de papel (Se for lido como 1 na matriz do trimestre, ficará 1-1 = 0; Se for lido como 2, ficará 2-1 = 1)

            if (papel[tipo][trimestre] == 0)
            {
                printf("O preço dos papéis não foram registrados. Registre-os.\n"); // Aviso por não ter registrado os preços dos papéis
                precoPapel(papel); // Rodar a função de colocar o preço dos papéis caso não tenha perguntado
            }

            int numero_de_paginas = r[pedido][2][trimestre]; // Número de páginas lido ou editado nas funções passadas
            int preco_papel = papel[tipo][trimestre]; // Preço do papel registrado para cada trimestre

            if (r[pedido][1][trimestre] < 100) // Pedidos com menos de 100 exemplares
            {
                tpedido = (numero_de_paginas*preco_papel)/1000;
            }
            else
            {
                if (r[pedido][1][trimestre] < 500) // Pedidos entre 100 a 500 exemplares
                {
                    tpedido = ((numero_de_paginas*preco_papel)/1000)*0.9;
                }
                else
                {
                    tpedido = ((numero_de_paginas*preco_papel)/1000)*0.8; // Pedido com mais de 500 exemplares
                }
            }

            precototal[trimestre] += tpedido; // Somar o total de valores dos pedidos de cada trimestre
        }
    }
    return tpedido; // Retornar o valor do pedido
}

int mostraPedido(int r[50][4][2], float preco, int totaltrimestre[2])
{
    int pedido;
    printf("Qual número do pedido? \n");
    scanf("%d", &pedido);
    pedido--;
    int trimestre;
    if (pedido < totaltrimestre[0])
    {
        trimestre = 0;
        printf("Trimestre %d\n", trimestre + 1); // Mostrar os dados do pedido escolhido
        printf("Código do pedido: %d\n", r[pedido][0][trimestre]);
        printf("Quantidade de exemplares: %d\n", r[pedido][1][trimestre]);
        printf("Número de paginas: %d\n", r[pedido][2][trimestre]);
        printf("Tipo de papel: %d\n", r[pedido][3][trimestre]);
        printf("Valor do pedido: %.2f\n", preco);
        return 1;
    }
    else
    {
        if (pedido < totaltrimestre[1])
        {
            trimestre = 1;
            printf("Trimestre %d\n", trimestre + 1); // Mostrar os dados do pedido escolhido
            printf("Código do pedido: %d\n", r[pedido][0][trimestre]);
            printf("Quantidade de exemplares: %d\n", r[pedido][1][trimestre]);
            printf("Número de paginas: %d\n", r[pedido][2][trimestre]);
            printf("Tipo de papel: %d\n", r[pedido][3][trimestre]);
            printf("Valor do pedido: %.2f\n", preco);
            return 1;
        }
        else
        {
            printf("O pedido que você escolheu não foi encontrado.\n");
            return 0;
        }
    }
}

void mostrarPapel(int papel[2][2]) //  Função para mostrar o preço dos papéis e opção de editá-las
{
    char editar;
    for (int trimestre = 0; trimestre < 2; trimestre++)
    {
        // Mostrar o preço dos papéis na tela
        printf("Preço dos papéis no trimestre %d\n", trimestre + 1);
        printf("Preço do papel couché: %d\n", papel[0][trimestre]);
        printf("Preço do papel sulfite: %d\n", papel[1][trimestre]);
    }
    printf("Deseja editar o preço dos papéis? (s ou n)\n");
    scanf(" %c", &editar);
    if (editar == 's')
    {
        // Edição dos preços dos papéis
        int tri;
        printf("De qual trimestre? (1 ou 2)\n");
        scanf("%d", &tri);
        tri--;
        printf("Preço do papel couché: \n");
        scanf("%d", &papel[0][tri]);
        printf("Preço do papel sulfite: \n");
        scanf("%d", &papel[1][tri]);
    }
}

void faturamento(float precototal[2]) // Função para mostrar o valor total dos pedidos de cada trimestre
{
    for (int trimestre = 0; trimestre < 2; trimestre++)
    {
        printf("Valor total dos pedidos no trimestre %d: %.2f\n", trimestre + 1, precototal[trimestre]);
    }
}
