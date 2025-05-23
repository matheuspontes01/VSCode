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
bool Queue_sorted(Queue*, int);
bool Queue_fill_queue(Queue*, Queue*, Queue*);
bool Queue_concatenate(Queue*, Queue*);
void Queue_compare_size(Queue*, Queue*);
void Queue_pares_e_impares(Queue*);
void Queue_reverse_static(Queue*);
void Queue_media(Queue*);
Queue* queue_intercalar(Queue*, Queue*);
void print_octal(Queue*);

#endif