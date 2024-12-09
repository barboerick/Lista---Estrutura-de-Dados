#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int binary_search(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int interpolation_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));

        if (arr[pos] == x) return pos;

        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, search_choice, n, x;
    int arr[MAX];

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    printf("Digite os elementos: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Escolha um algoritmo de ordenação:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Selection Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            mergeSort(arr, 0, n - 1);
            printf("Array ordenado usando Merge Sort: ");
            printArray(arr, n);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            printf("Array ordenado usando Quick Sort: ");
            printArray(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            printf("Array ordenado usando Selection Sort: ");
            printArray(arr, n);
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    printf("Escolha um algoritmo de busca:\n");
    printf("1. Binary Search\n");
    printf("2. Interpolation Search\n");
    scanf("%d", &search_choice);

    printf("Digite o elemento a ser procurado: ");
    scanf("%d", &x);

    int result;
    switch (search_choice) {
        case 1:
            result = binary_search(arr, n, x);
            if (result != -1)
                printf("Elemento encontrado na posição %d usando Binary Search\n", result);
            else
                printf("Elemento não encontrado usando Binary Search\n");
            break;
        case 2:
            result = interpolation_search(arr, n, x);
            if (result != -1)
                printf("Elemento encontrado na posição %d usando Interpolation Search\n", result);
            else
                printf("Elemento não encontrado usando Interpolation Search\n");
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    return 0;
}
