#include "Node.h"
#include <stdlib.h>

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}