#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    printf("Quantas pessoas assistiram ao video? \n");
    scanf("%d", &n);

    printf("Visualizacoes alvo: \n");
    scanf("%d", &k);

    int **info = (int **)malloc(n * sizeof(int*));
    if (info == NULL) return 1;

    for (int i = 0; i < n; i++) {
        info[i] = (int*)malloc(2 * sizeof(int));

        if (info[i] == NULL) return 1;
    }

    // Preenchendo matriz

    for (int i = 0; i < n; i++) {
        printf("Momento em que pessoa[%d] assistiu ao video: \n", i + 1);
        scanf("%d", &info[i][0]);
        printf("Quanto tempo ela espera para assistir ao video novamente: \n");
        scanf("%d", &info[i][1]);
    }

    /*int *result = malloc(n * sizeof(int));
    if (result == NULL) return 1;

    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }*/

    int colecionando_momento;
    for (int i = 0; i < n; i++) {
        int n_views = 1;
        colecionando_momento = info[i][0];
        while (1) {
            if (n_views >= k) {
                printf("%d\n", colecionando_momento);
                break;
            }
            n_views++;
            colecionando_momento += info[i][1];
        }
    }

}