#include <stdio.h>

typedef struct {
    int chave;
    int estado;
    int pont;
} Registro;

#define NAO_OCUPADO 0
#define OCUPADO 1

int hash(int chave, int tamanho) {
    return chave % tamanho;
}

void inicializarTabela(Registro *T, int m) {
    for (int i = 0; i < m; i++) {
        T[i].pont = i;
        T[i].estado = NAO_OCUPADO;
    }
}

void busca(int x, Registro *T, int m, int *end, int *a) { // Funcao que busca a chave e informa se existe, nao existe (fala se tem espaco para inserir)
    *end = hash(x, m); // Endereco/index via hash

    if (T[*end].estado == NAO_OCUPADO) { // Caso esse espaco procurado pela funcao nao esteja ocupado
        *a = 2; // por meio da variavel 'a' informa que tem espaco para inserir 
        return; // finaliza a funcao
    }
    // Caso esteja ocupado, entao iremos percorrer nos espacos onde as chaves se apontam, que possuiram a mesma resposta hash
    int j = *end;
    do {
        if (T[j].estado == OCUPADO && T[j].chave == x) { // Caso o espaco esteja ocupado e tenha a chave que deseja busca
            *a = 1; // Informamos por meio da variavel 'a' que o espaco ja esta ocupado e ja existe a chave
            *end = j; // Passamos o endereco dessa espaco para end
            return; // Finaliza a funcao
        }
        j = T[j].pont; // Caso contrario, passa para o proximo espaco apontado por essa chave
    } while (j != *end); // Ate voltar ao inicio novamente

    *a = 2; // Caso contrario, existe espaco para inserir e nao existe a chave buscada
}

void inserir(int x, Registro *T, int m) {
    int end, a;
    busca(x, T, m, &end, &a); // Fazemos a busca pela chave, para saber se ela existe ou nao, e saber se tem espaco para inseri-la 
    // Retorna em end a posicao onde ela esta ou onde deveria estar, e 'a' diz se a chave existe

    if (a != 1) { // Caso a chave nao exista
        int j, i = 1;

        // Se posicao encontrada na funcao de busca nao for a mesma posicao hash,
        // Entao, utilizamos a posicao a qual foi encontrada na funcao
        if (end != hash(x, m))
            j = end;
        else
            j = hash(x, m);

        // Procura a posicao livre para insercao
        while (i <= m) {
            if (T[j].estado == NAO_OCUPADO) {
                break; // Tem posicao livre, para a busca
            } else { 
                // Senao, vamos avancando circularmente na tabela
                j = (j + 1) % m;
                i++;
            }
        }

        // Se percorremos toda a tabela, nao achamos posicao livre para inserir, aviso de overflow
        if (i == m + 1) {
            printf("Insercao invalida: overflow\n");
            return;
        }

        // Achamos posicao livre
        if (i == 1) { // Nessa caso, inserimos na posicao do hash diretamente 
            T[end].chave = x;
            T[end].estado = OCUPADO;
        } else { // Insercao com encadeamento interno: atualiza ponteiros da lista encadeada
            int temp = T[j].pont; // Salva o ponteiro atual da posicao livre encontrada
            T[j].pont = T[hash(x, m)].pont; // O novo no aponta para o proximo da lista
            T[hash(x, m)].pont = temp; // A cabeca da lista aponta para o novo no

            T[j].chave = x; // Insere a chave na posicao livre
            T[j].estado = OCUPADO; // Marca como ocupado
        }
    } else { // Caso a == 1, entao a chave existe
        printf("Insercao invalida: chave ja existente\n");
    }
}

void remover(int x, Registro *T, int m) {
    int a, end;
    busca(x, T, m, &end, &a); // Procuramos a chave para saber se ela existe para remover

    if (a == 1) // Caso a chave exista
        T[end].estado == NAO_OCUPADO; // Mudamos o estado dela para NAO_OCUPADO
    else
        printf("Exclusao invalida: chave nao existente"); // Avisa que a chave nao existe
} 

void print(Registro *T, int m) {
    printf("Index | Chave | Estado | Pont\n");
    printf("-------------------------------\n");
    for (int i = 0; i < m; i++) {
        if (T[i].estado == OCUPADO)
            printf("  %2d   |  %4d |   %d    |  %2d\n", i, T[i].chave, T[i].estado, T[i].pont);
        else
            printf("  %2d   |  ---- |   %d    |  %2d\n", i, T[i].estado, T[i].pont);
    }
}

int main() {
    Registro T[10];

    inicializarTabela(T, 7);

    int n[7] = {2341, 4234, 2839, 430, 22, 397, 3920};

    for (int i = 0; i < 7; i++) {
        inserir(n[i], T, 7);
    }

    print(T, 7);
}