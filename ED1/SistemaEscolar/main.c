#include "SistemaEscolar.h"
#include <stdio.h>

int main() {
    TCircularList* list = TCircularList_create();
    char nome[30];
    float nota;
    int matricula;
    for (int i = 0; i < 3; i++) {
        printf("Nome: \n");
        scanf("%s", &nome);
        printf("Nota: \n");
        scanf("%f", &nota);
        if (!TCircularList_insert_end(list, nome, nota, i + 1)) {
            printf("Erro ao inserir o aluno %s\n", nome);
        }
    }

    TCircularList_print(list);

    printf("Media da turma: %.2f\n", TCircularList_calcular_media(list));
}