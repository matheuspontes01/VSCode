#include <stdio.h>

int hash(int chave, int tamanho) {
    return chave % tamanho;
} 

int hash_linear(int chave, int k, int tamanho) {
    return (chave + k) % tamanho;
}

int hash_quadratica(int chave, int k, int tamanho) {
    return (chave + k*k) % tamanho;
}

int hash_2(int chave, int tamanho) {
    return 1 + (chave % (tamanho - 1));
}

int hash_dispersao_dupla(int chave, int k, int tamanho) {
    return (hash(chave, tamanho) + k*hash_2(chave, tamanho)) % tamanho;
}

void busca_aberto(int chave, int *end, int *a, int tamanho, int* V) {
    *a = 3; 
    int k = 0;
    while (k < tamanho) {
        *end = hash_dispersao_dupla(chave, k, tamanho);
        if (V[*end] == chave) {
            *a = 1;
            k = tamanho;
        } else if (V[*end] == -1) {
            *a = 2; 
            k = tamanho;
        } else {
            k++;
        }
    }
}

void insercao(int chave, int tamanho, int* V) {
    int a, end;

    busca_aberto(chave, &end, &a, tamanho, V);

    if (a == 1) {
        printf("Essa chave ja existe!\n");
    } else if (a == 2) {
        V[end] = chave;
    } else {
        printf("Nao e possivel inserir essa chave!\n");
    }
}


int main() {
    int V[10];

    for (int i = 0; i < 10; i++) {
        V[i] = -1;
    }
    
    int teste[8] = {2, 16, 10, 30, 4, 26, 22, 14};

    for (int i =0; i < 8; i++) {
        insercao(teste[i], 10, V);
    }

    for (int i = 0; i < 10; i++) {
        if (V[i] != -1)
            printf("%d index = %d\n", V[i], i);
    }
}