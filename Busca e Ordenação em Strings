#Marge Short

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arr[][50], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[n1][50], R[n2][50];

    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[l + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[m + 1 + j]);

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][50], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    char arr[][50] = {"banana", "Apple", "orange", "grape", "Pineapple"};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%s\n", arr[i]);
    return 0;
}

#Quick Short
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char arr[][50], int low, int high) {
    char pivot[50];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(char arr[][50], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char arr[][50] = {"banana", "Apple", "orange", "grape", "Pineapple"};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}


