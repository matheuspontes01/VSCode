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

    if (l < heapSize & A[l] > A[i]) {
        largest = l;
    }

    if (r < heapSize & A[r] > A[largest]) {
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

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    BuildMaxHeap(10, A);

    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    heapSort(10, A);

    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
