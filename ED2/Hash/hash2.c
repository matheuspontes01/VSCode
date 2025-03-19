#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_TABELA 1048576 // 2^20

// Gera uma string aleatória de tamanho fixo
void gerar_strings_aleatorias(char *str, size_t length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < length - 1; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length - 1] = '\0';
}

// Método da Dobra para dispersão
unsigned int metodo_da_dobra(const char *chave) {
    unsigned int hash = 0;
    size_t len = strlen(chave);
    for (size_t i = 0; i < len; i += 4) {
        unsigned int part = 0;
        memcpy(&part, chave + i, (i + 4 <= len) ? 4 : len - i);
        hash += part;
    }
    return hash % TAMANHO_TABELA;
}

// DJB2 Hash
unsigned int djb2_hash(const char *chave) {
    unsigned long hash = 5381;
    int c;
    while ((c = *chave++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TAMANHO_TABELA;
}

// Conta o número de colisões
int contar_colisoes(unsigned int (*hash_function)(const char *), char keys[][11], int size) {
    int *hash_table = calloc(TAMANHO_TABELA, sizeof(int));
    int colisoes = 0;
    
    for (int i = 0; i < size; i++) {
        unsigned int index = hash_function(keys[i]);
        if (hash_table[index] > 0) {
            colisoes++;
        }
        hash_table[index]++;
    }
    
    free(hash_table);
    return colisoes;
}

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 10000, 1000000};
    
    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        char (*chaves)[11] = malloc(size * sizeof(*chaves));
        
        for (int j = 0; j < size; j++) {
            gerar_strings_aleatorias(chaves[j], 11);
        }
        
        int colisoes_dobra = contar_colisoes(metodo_da_dobra, chaves, size);
        int colisoes_djb2 = contar_colisoes(djb2_hash, chaves, size);
        
        printf("Tamanho da entrada: %d\n", size);
        printf("Colisões (Método da Dobra): %d\n", colisoes_dobra);
        printf("Colisões (DJB2 Hash): %d\n", colisoes_djb2);
        printf("----------------------------------------\n");
        
        free(chaves);
    }
    return 0;
}
