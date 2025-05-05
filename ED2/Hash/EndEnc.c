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

void busca(int x, Registro *T, int m, int *end, int *a) {
    *end = hash(x, m);

    if (T[*end].estado == NAO_OCUPADO) {
        *a = 2;
        return;
    }

    int j = *end;
    do {
        if (T[j].estado == OCUPADO && T[j].chave == x) {
            *a = 1;
            *end = j;
            return;
        }
        j = T[j].pont;
    } while (j != *end);

    *a = 2;
}

void inserir(int x, Registro *T, int m) {
    int end, a;
    busca(x, T, m, &end, &a);

    if (a != 1) {
        int j, i = 1;
        if (end != hash(x, m))
            j = end;
        else
            j = hash(x, m);

        while (i <= m) {
            if (T[j].estado == NAO_OCUPADO) {
                break;
            } else {
                j = (j + 1) % m;
                i++;
            }
        }

        if (i == m + 1) {
            printf("Insercao invalida: overflow\n");
            return;
        }

        if (i == 1) {
            T[end].chave = x;
            T[end].estado = OCUPADO;
        } else {
            int temp = T[j].pont;
            T[j].pont = T[hash(x, m)].pont;
            T[hash(x, m)].pont = temp;

            T[j].chave = x;
            T[j].estado = OCUPADO;
        }
    } else {
        printf("Insercao invalida: chave ja existente\n");
    }
}

void remover(int x, Registro *T, int m) {
    int a, end;
    busca(x, T, m, &end, &a);

    if (a == 1)
        T[end].estado == NAO_OCUPADO;
    else
        printf("Exclusao invalida: chave nao existente");
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

    inicializarTabela(T, 10);

    int n[8] = {2, 7, 10, 26, 34, 5, 8, 16};

    for (int i = 0; i < 8; i++) {
        inserir(n[i], T, 10);
    }

    print(T, 10);
}