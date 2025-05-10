#include <stdio.h>

int hash(int chave, int tamanho) { // Hash
    return chave % tamanho;
} 

int hash_linear(int chave, int k, int tamanho) { // Tentativa Linear
    return (chave + k) % tamanho;
}

int hash_quadratica(int chave, int k, int tamanho) { // Tentativa Quadratica
    return (chave + k*k) % tamanho;
}

int hash_2(int chave, int tamanho) { // Hash 2
    return 1 + (chave % (tamanho - 1));
}

int hash_dispersao_dupla(int chave, int k, int tamanho) { // Dispersao Dupla
    return (hash(chave, tamanho) + k*hash_2(chave, tamanho)) % tamanho;
}

void busca_aberto(int chave, int *end, int *a, int tamanho, int* V) {
    *a = 3; // a == 3 indica que nao ha espaco para inserir a chave
    int k = 0; // k vai ser o numero de tentativas, que e necessario para retornar o endereco da tabela de acordo com o numero de tentativas
    while (k < tamanho) {
        *end = hash_dispersao_dupla(chave, k, tamanho); // Retorna o endereco na tabela de acordo com o numero de tentativas
        if (V[*end] == chave) { // Se a chave existe
            *a = 1; // indica que a chave existe
            k = tamanho; // para a busca
        } else if (V[*end] == -1) { // indica se o espaco esta vazio
            *a = 2; 
            k = tamanho; // para a busca
        } else {
            k++; // Se nao contou um desses casos, conta mais uma tentativa para buscar o novo endereco
        }
    }
}

void insercao(int chave, int tamanho, int* V) {
    int a, end;

    busca_aberto(chave, &end, &a, tamanho, V); // Verifica se a chave existe ou nao na tabela

    if (a == 1) { // Indica se a chave existe
        printf("Essa chave ja existe!\n");
    } else if (a == 2) { // Indica que a chave nao existe, e existe espaco para inseri-lo
        V[end] = chave;
    } else { // Indica que nao ha espaco para inserir a chave
        printf("Nao e possivel inserir essa chave!\n");
    }
}


int main() {
    int V[7];

    for (int i = 0; i < 7; i++) {
        V[i] = -1; // Indicar que o espaco esta vazio
    }
    
    int teste[7] = {2341, 4234, 2839, 430, 22, 397, 3920};

    for (int i =0; i < 7; i++) {
        insercao(teste[i], 7, V);
    }

    for (int i = 0; i < 7; i++) {
        if (V[i] != -1)
            printf("%d index = %d\n", V[i], i);
    }
}