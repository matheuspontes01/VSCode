#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome_do_prato[100];
    char descricao[200];
    float valor;
} Cardapio;

void mostrar_opcoes();
void cadastrar_pedido(Cardapio menu[1000], int index);

int main() {
    Cardapio menu[1000];
    int index = 0, op;
    do {
        mostrar_opcoes();
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                cadastrar_pedido(menu, index);
                index++;
                break;
            
            case -1:
                break;

            
            default:
            printf("Opcao invalida.\n");
                break;
        }
    } while (op != -1);
}

void mostrar_opcoes(){
    printf("-------- MENU --------\n");
    printf("[1] Cadastrar itens do cardápio (nome do prato, descrição, valor).\n");
    printf("[2] Registrar pedidos feitos pelos clientes, associando um ou mais itens do cardápio no pedido.\n");
    printf("[3] Calcular o total do pedido com base nos itens escolhidos.\n");
    printf("[4] Gerar um relatório com todos os pedidos feitos, mostrando o total arrecadado pelo restaurante no dia.\n");
    printf("[-1] Sair\n");
}

void cadastrar_pedido(Cardapio menu[1000], int index) {
    Cardapio prato;

    printf("Nome do prato:\n");
    scanf(" %[^\n]", prato.nome_do_prato); // Captura o nome do prato com espaços

    printf("Descricao do prato:\n");
    getchar();  // Consome o '\n' pendente
    fgets(prato.descricao, sizeof(prato.descricao), stdin);
    prato.descricao[strcspn(prato.descricao, "\n")] = 0; // Remove a quebra de linha

    printf("Valor do prato:\n");
    scanf("%f", &prato.valor);

    strcpy(menu[index].nome_do_prato, prato.nome_do_prato);
    strcpy(menu[index].descricao, prato.descricao);
    menu[index].valor = prato.valor;

    printf("Pedido registrado com sucesso!\n");
}
