class HashMap:
    def __init__(self):
        self.size = 1000
        self.map = [[] for _ in range(self.size)]

    def _hash(self, key):
        return hash(key) % self.size
    
    def insert(self, key, value):
        index = self._hash(key)
        for pair in self.map[index]:
            if pair[0] == key:
                pair[1] = value
                return
        self.map[index].append([key, value])

    def get(self, key):
        index = self._hash(key)
        for pair in self.map[index]:
            if pair[0] == key:
                return pair[1]
        return None
    
    def remove(self, key):
        index = self._hash(key)
        for i, pair  in enumerate(self.map[index]):
            if pair[0] == key:
                del self.map[index][i]
                return
            

hash_map = HashMap()
hash_map.insert("nome", "Joao")
hash_map.insert("idade", 25)
print(hash_map.get("nome"))
print(hash_map.get("idade"))
hash_map.remove("nome")
print(hash_map.get("nome"))