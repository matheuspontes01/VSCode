#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int tipo;
    int sexo;
    int idade;
    char tutor[50];
} pet;

void lerPet(pet *x);
void registrarPet(pet x, pet Dados[60][3], int *a, int codigo, int linhaanimal[3]);
void mostrarPet(pet Dados[60][3], int linhaanimal[3]);
void buscaPet(pet Dados[60][3], int linhaanimal[3]);
void adotarPet(pet Dados[60][3], int linhaanimal[3]);
void relatorioPorAbrigo(pet Dados[60][3], int linhaanimal[3]);

int main(void)
{
    pet p, Dados[60][3] = {0};
    int relatorio, abrigo, codigoanimal = 0, linha[3] = {0};
    char op1;

    do
    {
        printf("Menu: \n");
        printf("[1] Cadastrar pet\n");
        printf("[2] Busca pet para adocao\n");
        printf("[3] Adotar\n");
        printf("[4] Relatorio por abrigo\n");
        printf("[5] Mostrar\n");
        scanf("%d", &relatorio);
        switch (relatorio)
        {
        case 1:
            printf("Qual abrigo? \n");
            scanf("%d", &abrigo);
            codigoanimal++;
            linha[abrigo - 1]++;
            if (abrigo < 1 || abrigo > 3)
            {
                printf("Abrigo invalido.\n");
                break;
            }
            if (linha[abrigo - 1] > 60)
            {
                printf("Sem espaço para registro de novos animais no abrigo %d\n", abrigo);
                break;
            }
            lerPet(&p);
            registrarPet(p, Dados, &abrigo, codigoanimal, linha);
            mostrarPet(Dados, linha);
            break;

        case 2:
            buscaPet(Dados, linha);
            break;

        case 3:
            adotarPet(Dados, linha);
            break;

        case 4:
            relatorioPorAbrigo(Dados, linha);
            break;

        case 5:
            mostrarPet(Dados, linha);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
        printf("Deseja imprimir outro item? (s ou n)\n");
        scanf(" %c", &op1);
    } while (op1 != 'n');
}

void lerPet(pet *x)
{
    char op;
    printf("Tipo do animal: (1- gato, 2- cachorro porte pequeno, 3- cachorro porte medio, 4- cachorro porte grande)\n");
    scanf("%d", &x->tipo);
    printf("Sexo do animal: (1- macho, 2- femea)\n");
    scanf("%d", &x->sexo);
    printf("Idade do animal: (1- filhote, 2- adulto)\n");
    scanf("%d", &x->idade);
    printf("Possui tutor? (s ou n)\n");
    scanf(" %c", &op);
    if (op == 's' || op == 'S')
    {
        printf("Nome do tutor: \n");
        scanf("%s", x->tutor);
    }
    else
    {
        printf("Digite 'semtutor'\n");
        scanf("%s", x->tutor);
    }
}

void registrarPet(pet x, pet Dados[60][3], int *a, int codigo, int linhaanimal[3])
{
    int c = linhaanimal[(*a) - 1] - 1;
    Dados[c][(*a) - 1].codigo = codigo;
    Dados[c][(*a) - 1].tipo = x.tipo;
    Dados[c][(*a) - 1].sexo = x.sexo;
    Dados[c][(*a) - 1].idade = x.idade;
    strcpy(Dados[c][(*a) - 1].tutor, x.tutor);
}

void mostrarPet(pet Dados[60][3], int linhaanimal[3])
{
    for (int a = 0; a < 3; a++)
    {
        printf("------------Animais do abrigo %d------------\n", a + 1);
        for (int c = 0; c < linhaanimal[a]; c++)
        {
            printf("----- Codigo do animal: %d -----\n", Dados[c][a].codigo);
            printf("Tipo de animal: %d\n", Dados[c][a].tipo);
            printf("Sexo do animal: %d\n", Dados[c][a].sexo);
            printf("Idade do animal: %d\n", Dados[c][a].idade);
            printf("Nome do tutor: %s\n", Dados[c][a].tutor);
        }
    }
}

void buscaPet(pet Dados[60][3], int linhaanimal[3])
{
    int tipo, aviso = 0;
    printf("Qual o tipo de animal? (1- gato, 2- cachorro porte pequeno, 3- cachorro porte medio, 4- cachorro porte grande)\n");
    scanf("%d", &tipo);
    if (tipo < 1 || tipo > 4)
    {
        printf("Tipo de animal invalido\n");
        return;
    }
    for (int a = 0; a < 3; a++)
    {
        for (int c = 0; c < linhaanimal[a]; c++)
        {
            if (Dados[c][a].tipo == tipo)
            {
                if (strcmp(Dados[c][a].tutor, "semtutor") == 0)
                {
                    printf("----- Codigo do animal: %d -----\n", Dados[c][a].codigo);
                    printf("Tipo de animal: %d\n", Dados[c][a].tipo);
                    printf("Sexo do animal: %d\n", Dados[c][a].sexo);
                    printf("Idade do animal: %d\n", Dados[c][a].idade);
                    printf("Nome do tutor: %s\n", Dados[c][a].tutor);
                    aviso = 1;
                }
            }
        }
    }
    if (aviso == 0)
    {
        printf("Nao ha animais disponiveis.\n");
    }
}

void adotarPet(pet Dados[60][3], int linhaanimal[3])
{
    char op;
    int cod;
    printf("Qual o codigo do animal? \n");
    scanf("%d", &cod);
    for (int a = 0; a < 3; a++)
    {
        for (int c = 0; c < linhaanimal[a]; c++)
        {
            if (Dados[c][a].codigo == cod)
            {
                if (strcmp(Dados[c][a].tutor, "semtutor") == 0)
                {
                    printf("Animal encontrado, registre o nome do tutor abaixo: \n");
                    scanf("%s", Dados[c][a].tutor);
                    printf("Registro do tutor concluido\n");
                }
                else
                {
                    printf("Esse animal ja tem um tutor. Deseja editar o nome? (s ou n)\n");
                    scanf(" %c", &op);
                    if (op == 's' || op == 'S')
                    {
                        printf("Nome do tutor: \n");
                        scanf("%s", Dados[c][a].tutor);
                        printf("Edicao de tutor concluida\n");
                    }
                }
                return; // Parar a busca
            }
        }
    }
    printf("Nao foi encontrado o animal com o codigo desejado\n");
}

void relatorioPorAbrigo(pet Dados[60][3], int linhaanimal[3])
{
    int a, cachorros = 0, gatos = 0, ca_filhotes = 0, ga_filhotes = 0;
    float semtutores = 0, comtutores = 0;
    printf("Qual abrigo? \n");
    scanf("%d", &a);
    if (a < 1 || a > 3)
    {
        printf("Abrigo invalido\n");
        return;
    }
    for (int c = 0; c < linhaanimal[a-1]; c++)
    {
        if (Dados[c][a-1].tipo == 1)
        {
            gatos++;
        }
        else
        {
            cachorros++;
        }
        if (Dados[c][a-1].idade == 1)
        {
            if (Dados[c][a-1].tipo == 1)
            {
                ga_filhotes++;
            }
            else
            {
                ca_filhotes++;
            }
        }
        if (strcmp(Dados[c][a-1].tutor, "semtutor") == 0)
        {
            semtutores++;
        }
        else
        {
            comtutores++;
        }
    }
    float totaltutores = semtutores + comtutores;
    printf("Quantidade de cachorros registrados: %d\n", cachorros);
    printf("Quantidade de gatos registrados: %d\n", gatos);
    printf("Quantidade de cachorros filhotes: %d\n", ca_filhotes);
    printf("Quantidade de gatos filhotes: %d\n", ga_filhotes);
    if (totaltutores > 0)
    {
        printf("Porcentagem de animais sem tutor: %.2f%%\n", (semtutores/totaltutores)*100);
    }
    else
    {
        printf("Porcentagem de animais sem tutor: (Nao tem animais registrados)\n");
    }
}