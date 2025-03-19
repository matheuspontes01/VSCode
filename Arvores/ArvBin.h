#ifndef ARVBIN
#define ARVBIN
#include <stdbool.h>

typedef struct _arvbin ArvBin;

ArvBin* ArvBin_create();

void ArvBin_destroy(ArvBin*);

bool ArvBin_is_empty(ArvBin*);

int ArvBin_height(ArvBin*);

int ArvBin_TotalNo(ArvBin*);