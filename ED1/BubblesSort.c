#include <stdio.h>

void BubbleSort(int numeros[], int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - i - 1; j++){
            if (numeros[j] > numeros[j + 1]){ // se trocar para 'menor que', a lista fica em ordem decrescente
                int penis = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = penis;
            }
        }
    }
}

int main(){
    int numeros[] = {12, 3, 50, 69};
    int tamanho = sizeof(numeros)/sizeof(numeros[0]);
    BubbleSort(numeros, tamanho);

    for (int i = 0; i < tamanho; i++){
        printf("%d, ", numeros[i]);
    }

    return 0;
}