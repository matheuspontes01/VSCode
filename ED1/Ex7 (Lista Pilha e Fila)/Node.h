#ifndef NODE_H
#define NODE_H

typedef struct _no {
    int info;
    struct _no *prox;
} TNo;

TNo* TNo_createNFill(int);

#endif