#include <stdio.h>

void BubbleSort(int numeros[], int tamanho){
    for (int i = 1; i < tamanho; i++){ // # N-1 iterations to sort a N-length list
        for (int j = 0; j < tamanho - i; j++){ // # after i iterations, the last i elements are sorted
            if (numeros[j] > numeros[j + 1]){ // se trocar para 'menor que', a lista fica em ordem decrescente
                int aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
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