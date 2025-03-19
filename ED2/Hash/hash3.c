#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definir tamanhos da tabela hash próximos a números primos
#define TABLE_SIZE_1000 1009
#define TABLE_SIZE_10000 10007
#define TABLE_SIZE_1000000 100003

// Gera uma string aleatória de tamanho fixo
void generate_random_string(char *str, size_t length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < length - 1; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length - 1] = '\0';
}

// Método da Dobra para dispersão
unsigned int folding_method(const char *key, unsigned int table_size) {
    unsigned int hash = 0;
    size_t len = strlen(key);
    for (size_t i = 0; i < len; i += 4) {
        unsigned int part = 0;
        memcpy(&part, key + i, (i + 4 <= len) ? 4 : len - i);
        hash += part;
    }
    return hash % table_size;
}

// DJB2 Hash
unsigned int djb2_hash(const char *key, unsigned int table_size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % table_size;
}

// Conta o número de colisões
int count_collisions(unsigned int (*hash_function)(const char *, unsigned int), char keys[][11], int size, unsigned int table_size) {
    int *hash_table = calloc(table_size, sizeof(int));
    int collisions = 0;
    
    for (int i = 0; i < size; i++) {
        unsigned int index = hash_function(keys[i], table_size);
        if (hash_table[index] > 0) {
            collisions++;
        }
        hash_table[index]++;
    }
    
    free(hash_table);
    return collisions;
}

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 10000, 1000000};
    unsigned int table_sizes[] = {TABLE_SIZE_1000, TABLE_SIZE_10000, TABLE_SIZE_1000000};
    
    for (int i = 0; i < 3; i++) {
        int size = sizes[i];
        unsigned int table_size = table_sizes[i];
        char (*keys)[11] = malloc(size * sizeof(*keys));
        
        for (int j = 0; j < size; j++) {
            generate_random_string(keys[j], 11);
        }
        
        int collisions_folding = count_collisions(folding_method, keys, size, table_size);
        int collisions_djb2 = count_collisions(djb2_hash, keys, size, table_size);
        
        printf("Tamanho da entrada: %d\n", size);
        printf("Tamanho da tabela hash: %u\n", table_size);
        printf("Colisoes (Metodo da Dobra): %d\n", collisions_folding);
        printf("Colisoes (DJB2 Hash): %d\n", collisions_djb2);
        printf("----------------------------------------\n");
        
        free(keys);
    }
    return 0;
}
