class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_recursive(self.root, key)

    def _insert_recursive(self, node, key):
        if key < node.key:
            if node.left is None:
                node.left = Node(key)
            else:
                self._insert_recursive(node.left, key)
        else:
            if node.right is None:
                node.right = Node(key)
            else:
                self._insert_recursive(node.right, key)
        
    def search(self, key):
        return self._search_recursive(self.root, key)
    
    def _search_recursive(self, node, key):
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search_recursive(node.left, key)
        return self._search_recursive(node.right, key)
    
    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(node.key, end=" ")
            self.inorder_traversal(node.right)
        
    def preorder_traversal(self, node):
        if node:
            print(node.key, end=" ")
            self.inorder_traversal(node.left)
            self.inorder_traversal(node.right)

    def postorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            self.inorder_traversal(node.right)
            print(node.key, end=" ")

#Main

by = BinaryTree()
by.insert(10)
by.insert(5)
by.insert(15)
by.insert(2)
by.insert(7)

print("\nEm ordem:")
by.inorder_traversal(by.root)

print("\nPre ordem:")
by.preorder_traversal(by.root)

print("\nPos ordem:")
by.postorder_traversal(by.root)

#Busca
print("\nBusca por 7:")
if by.search(7):
    print("Encontrado")
else:
    print("Nao encontrado")
