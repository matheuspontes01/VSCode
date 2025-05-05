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

void inicializarTabela(Registro *T, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        T[i].estado = NAO_OCUPADO;
        T[i].pont = i;
    }
}

void busca(int chave, int *end, int *a, int tamanho, Registro *T) {
    *a = 0, *end = hash(chave, tamanho);
    
    if (T[*end].estado == NAO_OCUPADO) {
        *a = 2;
        return;
    }

    int j = *end;
    do {
        if (T[j].estado == OCUPADO && T[j].chave == chave) {
            *a = 1;
            *end = j;
            return;
        }
        j = T[j].pont;
    } while (j != *end);

    *a = 2;
}

void inserir(int chave, int tamanho, Registro *T) {
    int a, end;
    busca(chave, &a, &end, tamanho, T);

    if (a != 1) {
        int j, i = 1;
        if (end != hash(chave, tamanho)) {
            j = end;
        } else {
            j = hash(chave, tamanho);
        }

        while (i <= tamanho) {
            if (T[j].estado == NAO_OCUPADO) {
                break;
            } else {
                j = (j + 1) % tamanho;
                i++;
            }
        }


        if (i == tamanho + 1) {
            printf("Insercao invalida: overflow\n");
            return;
        } 

        if (i == 1) {
            T[j].chave = chave;
            T[j].estado = OCUPADO;
        } else {
            int temp = T[j].pont;
            T[j].pont = T[hash(chave, tamanho)].pont;
            T[hash(chave, tamanho)].pont = temp;

            T[j].chave = chave;
            T[j].estado = OCUPADO;
        }

    } else {
        printf("Insercao invalida: chave existente\n");
    }
}

void print(Registro *T, int tamanho) {
    printf("Index | Chave | Estado | Pont\n");
    for (int i = 0; i < tamanho; i++) {
        if (T[i].estado == OCUPADO) {
            printf("%d   |  %d   |   %d   |   %d\n", i, T[i].chave, T[i].estado, T[i].pont);
        } else {
            printf("%d   |  ---   |   %d   |   %d\n", i, T[i].estado, T[i].pont);
        }
    }
}

    
int main() {
    Registro T[10];

    inicializarTabela(T, 10);

    int n[8] = {15, 9, 21, 18, 10, 3, 23, 29};

    for (int i = 0; i < 8; i++) {
        inserir(n[i], 10, T);
    }

    print(T, 10);
}