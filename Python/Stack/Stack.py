class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def size(self):
        return len(self.items)

    def pop(self):
        if self.size() == 0:
            return None
        else:
            return self.items.pop()
        
myStack = Stack()

myStack.push("Page 1")
myStack.push("Page 2")
myStack.push("Page 3")
myStack.push("Page 4")

print(myStack.items)

myStack.pop()
myStack.pop()

print(myStack.items)

myStack.pop()
myStack.pop()

print(myStack.items)