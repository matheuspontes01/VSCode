#ifndef QUEUEPIX_H
#define QUEUEPIX_H
#include <stdbool.h>

typedef struct queue Queue;

Queue* Queue_create(int);
void Queue_destroy(Queue*);
int Queue_enqueue(Queue*, int, int, float);
int Queue_dequeue(Queue*, int*, int*, float*);
int Queue_empty(Queue*);
int Queue_full(Queue*);

#endif