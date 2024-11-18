#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct stack Stack;

Stack* stack_create(); // criacao da pilha
int Stack_push(Stack*, int); // insercao do elemento no topo da pilha
int Stack_pop(Stack*, int*); // remocao do elemento no topo da pilha
int Stack_head(Stack*, int*); // acesso ao elemento no topo da pilha
void Stack_destroy(Stack*); // destruicao da pilha
int Stack_full(Stack*); // verificar se a pilha esta cheia
int Stack_empty(Stack*); // verificar se a pilha esta vazia
int Stack_qty(Stack*); // quantidade de elementos na pilha
void Stack_print(Stack*);
bool Stack_element_equals(Stack*, int);
int Stack_equals(Stack*, Stack*);
Stack* Stack_reversed_dynamic(Stack*); // para pilha dinamica
void Stack_reversed(Stack*); // para pilha estatica
Stack* Stack_transfer(Stack*);
bool Stack_info_igual(Stack*, int);
Stack* Stack_intersecao(Stack*, Stack*);
Stack* Stack_concatenar(Stack*, Stack*);

#endif