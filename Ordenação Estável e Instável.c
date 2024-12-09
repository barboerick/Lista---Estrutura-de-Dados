/*Algoritmos de Ordenação Estáveis
Merge Sort
Bubble Sort
Insertion Sort

Algoritmos de Ordenação Instáveis
Quick Sort
Heap Sort
Selection Sort*/

/*Exemplo Merge Sort (Estável)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char value[50];
} Item;

void merge(Item arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Item L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].key <= R[j].key) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Item arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    Item arr[] = {{5, "A"}, {3, "B"}, {5, "C"}, {3, "D"}, {2, "E"}};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < arr_size; i++)
        printf("{%d, %s} ", arr[i].key, arr[i].value);
    printf("\n");

    return 0;
}

/*Exemplo Quick Sort (Instável)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char value[50];
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item arr[], int low, int high) {
    int pivot = arr[high].key;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].key < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Item arr[] = {{5, "A"}, {3, "B"}, {5, "C"}, {3, "D"}, {2, "E"}};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("{%d, %s} ", arr[i].key, arr[i].value);
    printf("\n");

    return 0;
}

