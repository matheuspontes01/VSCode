#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_CHAVE 16 // Tamanho da chave
#define TAMANHO_TABELA_1000 1000
#define TAMANHO_TABELA_10000 10000
#define TAMANHO_TABELA_1000000 1000000

unsigned int metodo_da_dobra(const char *chave, int tamanho_tabela) {
    unsigned int hash = 0;
    size_t len = strlen(chave);
    for (size_t i = 0; i < len; i += 4) {
        unsigned int part = 0;
        memcpy(&part, &chave[i], (len - i >= 4) ? 4 : (len - i));
        hash += part;
    }
    return hash % tamanho_tabela;
}

unsigned int djb2_hash(const char *chave, int tamanho_tabela) {
    unsigned long hash = 5381;
    int c;
    while ((c = *chave++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % tamanho_tabela;
}

void gerar_chaves(const char *filename, int num_keys) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < num_keys; i++) {
        char chave[TAMANHO_CHAVE + 1];
        for (int j = 0; j < TAMANHO_CHAVE; j++) {
            int r = rand() % 62;
            if (r < 26)
                chave[j] = 'A' + r;
            else if (r < 52)
                chave[j] = 'a' + (r - 26);
            else
                chave[j] = '0' + (r - 52);
        }
        chave[TAMANHO_CHAVE] = '\0';
        fprintf(file, "%s\n", chave);
    }
    fclose(file);
}

int contar_colisoes(const char *filename, unsigned int (*hash_func)(const char *, int), int tamanho_tabela) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return -1;
    }
    
    char chave[TAMANHO_CHAVE + 1];
    int *tabela = (int *)calloc(tamanho_tabela, sizeof(int));
    int colisoes = 0;
    
    while (fscanf(file, "%16s", chave) != EOF) {
        unsigned int hash_value = hash_func(chave, tamanho_tabela);
        if (tabela[hash_value] > 0) {
            colisoes++;
        }
        tabela[hash_value]++;
    }
    fclose(file);
    free(tabela);
    return colisoes;
}

int main() {
    gerar_chaves("keys_1000.txt", 1000);
    gerar_chaves("keys_10000.txt", 10000);
    gerar_chaves("keys_1000000.txt", 1000000);
    
    printf("Dobra Hash Colisoes:\n");
    printf("1000 chaves: %d\n", contar_colisoes("keys_1000.txt", metodo_da_dobra, TAMANHO_TABELA_1000));
    printf("10000 chaves: %d\n", contar_colisoes("keys_10000.txt", metodo_da_dobra, TAMANHO_TABELA_10000));
    printf("1000000 chaves: %d\n", contar_colisoes("keys_1000000.txt", metodo_da_dobra, TAMANHO_TABELA_1000000));
    
    printf("\nDJB2 Hash Colisoes:\n");
    printf("1000 chaves: %d\n", contar_colisoes("keys_1000.txt", djb2_hash, TAMANHO_TABELA_1000));
    printf("10000 chaves: %d\n", contar_colisoes("keys_10000.txt", djb2_hash, TAMANHO_TABELA_10000));
    printf("1000000 chaves: %d\n", contar_colisoes("keys_1000000.txt", djb2_hash, TAMANHO_TABELA_1000000));
    
    return 0;
}
