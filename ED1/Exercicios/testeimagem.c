#include <stdio.h>

int main(void)
{
    char v[3]; // Um array de caracteres para armazenar 3 caracteres.
    
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &v[i]); // O espaço antes de %c ignora qualquer espaço em branco anterior.
    }

    for (int i = 0; i < 3; i++) {
        printf("%c", v[i]); // Usando v[i] para acessar o caractere armazenado.
    }

    printf("\n"); // Para imprimir uma nova linha após os caracteres.
    return 0;
}
