#include <stdio.h>

int fibo1(int n) {
    int atual;
    if (n == 0) {
        return 0;
    } else if (n == 1)
    {
        return 1;
    } else {
        int penultimo = 0;
        int ultimo = 1;
        for (int i = 2; i <= n; i++) {
            atual = penultimo+ultimo;
            penultimo = ultimo;
            ultimo = atual;
        }
        return atual;
    }
}

int main() {
    printf("%d", fibo1(9));
}