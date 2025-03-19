#include <stdio.h>
#include <stdlib.h>

int main() {

    int *V = malloc(3 * sizeof(int));
    if (V == NULL) return 1;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &V[i]);
    }

    int target = 6;

    int *result = malloc(2*sizeof(int));
    if (result == NULL) {
        free(V);
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (V[i] + V[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }

    printf("[%d, %d]\n", result[0], result[1]);
}