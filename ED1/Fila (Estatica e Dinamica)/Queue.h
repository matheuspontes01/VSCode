#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct queue Queue;

Queue* Queue_create();
void Queue_destroy(Queue*);
int Queue_enqueue(Queue*, int);
int Queue_dequeue(Queue*, int*);
int Queue_head(Queue*, int*);

int Queue_full(Queue*);
int Queue_empty(Queue*);
int Queue_qty(Queue*);

void Queue_print(Queue*);
Queue* Queue_reverse(Queue*);
int Queue_tail(Queue*, int*);
bool Queue_remove_negative_numbers(Queue*);

#endif