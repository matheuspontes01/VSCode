class Node: # no da arvore
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.data)

class BinaryTree:
    def __init__(self, data=None, node=None):
        if node:
            self.root = node
        elif data:
            node = Node(data)
            self.root = node
        else:
            self.root = None

    #percurso de forma simetrica
    def simetric_traversal(self, node=None):
        if Node is None:
            node = self.root

        if node.left:
            self.simetric_traversal(node.left)

        print(node, end='')

        if node.right:
            self.simetric_traversal(node.right)
        
    def postorder_traversal(self, node=None):
        if node is None:
            node = self.root
        
        if node.left:
            self.postorder_traversal(node.left)

        if node.right:
            self.postorder_traversal(node.right)

        print(node, end=' ')

    def height(self, node=None):
        if node is None:
            node = self.root
        hleft = 0
        hright = 0
        if node.left:
            hleft = self.height(node.left)

        if node.right:
            hright = self.height(node.right)

        if hright > hleft:
            return hright + 1
        return hleft + 1

class BinarySearchTree(BinaryTree):
    def insert(self, value):
        parent = None
        x = self.root
        while (x):
            parent = x
            if value < x.data:
                x = x.left
            else:
                x = x.right
        if parent is None:
            self.root = Node(value)
        elif value < parent.data:
            parent.left = Node(value)
        else:
            parent.right = Node(value)

    def search(self, value, node=0):
        if node == 0:
            node = self.root
        if node is None:
            return node
        if node.data == value:
            return BinarySearchTree(node)
        if value < node.data:
            self.search(value, node.left)
        else:
            self.search(value, node.right)

if __name__ == "__main__":
    tree = BinaryTree(7)
    tree.root.left = Node(18)
    tree.root.right = Node(14)

    tree.postorder_traversal()
    print()
    print("Altura:", tree.height())