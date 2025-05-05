#include <stdio.h>
#include <stdlib.h>

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

int parent(int i){
    return (i-1)/2;
}

void maxHeapify(int heapSize, int A[heapSize], int i) { // O(logn)
    int l = left(i);
    int r = right(i);

    int largest = i;

    if (l < heapSize && A[l] > A[i]) {
        largest = l;
    }

    if (r < heapSize && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        // swap elements
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(heapSize, A, largest);
    }
}

void BuildMaxHeap(int heapSize, int A[heapSize]) {
    for (int i = heapSize/2 - 1; i >= 0; i--) {
        maxHeapify(heapSize, A, i);
    }
}

void heapSort(int heapSize, int A[heapSize]) {
    BuildMaxHeap(heapSize, A);

    for (int i = heapSize - 1; i > 0; i--) {
        // swap elements
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapSize--;
        maxHeapify(heapSize, A, 0);
    }
}

int verifica_heap(int *heap, int n) {
    for (int i = 0; i < n; i++){
        int l = left(i);
        int r = right(i);

        if (l < n && heap[i] < heap[l]) return 0;
        if (r < n && heap[i] < heap[r]) return 0;
    }
    return 1;
}

int chave_minima(int* heap, int n) {
    int start = n/2;
    int min = heap[start]; 
    for (int i = start + 1; i < n; i++) {
        if (heap[i] < min) {
            min = heap[i];
        }
    }

    return min;
}

int chave_maxima(int *heap) {
    return heap[0];
}

void removeHeap(int *heap, int i, int *n) {
    if (i < 0 || i >= *n) {
        printf("Indice invalido!\n");
        return;
    }

    heap[i] = heap[(*n) - 1];
    (*n)--;


    if (i > 0 && heap[i] > heap[parent(i)]) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = temp;
            i = parent(i);
        }
    } else {
        maxHeapify(*n, heap, i);
    }
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    printf("verifica que se e heap ou nao: %d\n", verifica_heap(A, 10));

    BuildMaxHeap(n, A);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("chave min: %d\n", chave_minima(A, n));
    printf("verifica que se e heap ou nao: %d\n", verifica_heap(A, n));

    printf("Removendo elemento 3 da heap: \n");
    removeHeap(A, 1, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Fazendo sort na nossa heap: \n");
    heapSort(n, A);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
