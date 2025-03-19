class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)

        if self.head == None:
            self.head = new_node
            return
        
        current_node = self.head

        while current_node.next:
            current_node = current_node.next
        
        current_node.next = new_node
        return 
    
    def length(self):
        if self.head == None:
            return 0
        
        current_node = self.head
        total = 0

        while current_node:
            total += 1
            current_node = current_node.next

        return total
    
    def to_list(self):
        node_data = []
        current_node = self.head

        while current_node:
            node_data.append(current_node.data)
            current_node = current_node.next
        return node_data
    
    def get(self, index):
        if index >= self.length() or index < 0:
            print("Error: Index out of range")
            return None
        current_idx = 0
        current_node = self.head
        while current_node != None:
            if current_idx == index:
                return current_node.data
            current_node = current_node.next
            current_idx += 1
    
    def search_item(self, data):
        if self.length() != 0:
            current_node = self.head
            while current_node:
                if current_node.next == data:
                    print("Item found")
                    return True
                current_node = current_node.next
        
        print("Item not found")
        return False

    def remove_at_start(self):
        if self.head == None or self.length() == 0:
            print("The list has no elements to delete")
            return
        
        self.head = self.head.next

    def remove_at_end(self):
        if self.head == None or self.length() == 0:
            print("The list has no elements to delete")
            return
        
        current_node = self.head
        while current_node.next.next != None:
            current_node = current_node.next

        current_node.next = None

    def insert_at_start(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
    
    def insert_at_end(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return
        else:
            current_node = self.head
            while current_node.next != None:
                current_node = current_node.next
            current_node.next = new_node

    def display(self):
        contents = self.head

        if contents is None:
            print("List has no element")
        
        while contents:
            print(contents.data)
            contents = contents.next

        print("-----------")

    def reverse_LinkedList(self):
        previous_node = None
        current_node = self.head

        while current_node != None:
            next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = next
        self.head = previous_node

# Test
my_list = LinkedList()
my_list.display()

my_list.append(3)
my_list.append(7)
my_list.append(2)
my_list.append(1)
        
my_list.display()

print("The total number of elements are: " + str(my_list.length())) # 'str' converts to string
print(my_list.to_list())
print("----------")
my_list.reverse_LinkedList()
my_list.display()

my_list.insert_at_start(4)
my_list.display()