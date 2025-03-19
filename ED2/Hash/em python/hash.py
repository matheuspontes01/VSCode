import random
import string

def generate_random_strings(n, length=10):
    """Gera uma lista de n strings aleatórias com tamanho definido."""
    return [''.join(random.choices(string.ascii_letters + string.digits, k=length)) for _ in range(n)]

def folding_method(key, table_size):
    """Implementa o método da dobra para dispersão."""
    key_bytes = key.encode('utf-8')
    parts = [int.from_bytes(key_bytes[i:i+4], 'little', signed=False) for i in range(0, len(key_bytes), 4)]
    return sum(parts) % table_size

def djb2_hash(key, table_size):
    """Implementa a função DJB2 Hash."""
    hash_value = 5381
    for char in key:
        hash_value = ((hash_value << 5) + hash_value) + ord(char)  # hash * 33 + char
    return hash_value % table_size

def count_collisions(keys, hash_function, table_size):
    """Conta o número de colisões usando uma determinada função de hash."""
    hash_table = {}
    collisions = 0
    
    for key in keys:
        index = hash_function(key, table_size)
        if index in hash_table:
            collisions += 1
        else:
            hash_table[index] = key
    
    return collisions

def main():
    sizes = [1000, 10000, 1000000]
    table_size = 2**20  # Tamanho grande para reduzir colisões
    
    for size in sizes:
        keys = generate_random_strings(size)
        
        collisions_folding = count_collisions(keys, folding_method, table_size)
        collisions_djb2 = count_collisions(keys, djb2_hash, table_size)
        
        print(f"Tamanho da entrada: {size}")
        print(f"Colisões (Método da Dobra): {collisions_folding}")
        print(f"Colisões (DJB2 Hash): {collisions_djb2}")
        print("-" * 40)

if __name__ == "__main__":
    main()