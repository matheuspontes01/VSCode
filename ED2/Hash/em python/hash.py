import random
import string
import hashlib

def fold_hash(key, table_size):
    """ Método da dobra para calcular hash """
    key_str = str(key)
    chunk_size = 4  # Divisão da chave em partes de 4 caracteres
    chunks = [key_str[i:i+chunk_size] for i in range(0, len(key_str), chunk_size)]
    hash_value = sum(int(chunk) for chunk in chunks if chunk.isdigit())
    return hash_value % table_size

def djb2_hash(key, table_size):
    """ Algoritmo DJB2 """
    hash_value = 5381
    for char in str(key):
        hash_value = ((hash_value << 5) + hash_value) + ord(char)
    return hash_value % table_size

def generate_keys(filename, num_keys):
    """ Gera um arquivo com chaves aleatórias """
    with open(filename, 'w') as f:
        for _ in range(num_keys):
            key = ''.join(random.choices(string.digits, k=10))  # Chave de 10 dígitos
            f.write(key + '\n')

def count_collisions(filename, hash_function, table_size):
    """ Conta colisões utilizando uma função hash """
    hash_table = {}
    with open(filename, 'r') as f:
        for line in f:
            key = line.strip()
            hash_value = hash_function(key, table_size)
            if hash_value in hash_table:
                hash_table[hash_value] += 1
            else:
                hash_table[hash_value] = 1
    
    collisions = sum(count - 1 for count in hash_table.values() if count > 1)
    return collisions

# Gera arquivos de chaves
generate_keys("keys_1000.txt", 1000)
generate_keys("keys_10000.txt", 10000)
generate_keys("keys_1000000.txt", 1000000)

# Contabiliza colisões
sizes = [1000, 10000, 1000000]
for size in sizes:
    filename = f"keys_{size}.txt"
    table_size = size  # Ajusta o tamanho da tabela para o número de chaves
    fold_collisions = count_collisions(filename, fold_hash, table_size)
    djb2_collisions = count_collisions(filename, djb2_hash, table_size)
    print(f"{size} chaves:")
    print(f" - Método da dobra: {fold_collisions} colisões")
    print(f" - DJB2 Hash: {djb2_collisions} colisões")