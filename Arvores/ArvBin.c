#include "ArvBin.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
}TNo;

struct _arvbin{
    TNo* raiz;
};

ArvBin* ArvBin_create() {
    ArvBin* raiz = malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

TNo* TNo_create(int info) {

}

void TNo_destroy(TNo* no) { // So posso remover o no se eu tiver removido os nos da direita e da esquerda dele
    if (no == NULL) return;

    TNo_destroy(no->esq);
    TNo_destroy(no->dir);

    free(no);
    no = NULL;
}

void ArvBin_destroy(ArvBin* raiz) {
    if (raiz == NULL) return;

    TNo_destroy(*raiz);
    free(raiz);
}

bool ArvBin_is_empty(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return true;
    } else {
        return false;
    }
}

int ArvBin_height(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) return 0;

    int alt_esq = ArvBin_height(&((*raiz)->esq));
    int alt_dir = ArvBin_height(&((*raiz)->dir));

    if (alt_esq > alt_dir) {
        return (alt_esq + 1);
    } else {
        return (alt_dir + 1);
    }

}

int ArvBin_TotalNo(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) return 0;

    int alt_esq = ArvBin_TotalNO(&((*raiz)->esq));
    int alt_dir = ArvBin_TotalNO(&((*raiz)->dir));

    return (alt_esq + alt_dir + 1);

}

