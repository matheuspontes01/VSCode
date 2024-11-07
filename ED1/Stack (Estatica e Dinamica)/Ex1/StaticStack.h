#ifndef STATIC_STACK_H
#define STATIC_STACK_H

typedef struct stack Stack;

Stack* stack_create(); // criacao da pilha
int Stack_push(Stack*, char*); // insercao do elemento no topo da pilha
int Stack_full(Stack*);
int Stack_empty(Stack*);
int Stack_pop(Stack*, char*);

#endif