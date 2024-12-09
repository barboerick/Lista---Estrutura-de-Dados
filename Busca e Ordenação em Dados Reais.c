#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j;
    int buckets[MAX + 1] = {0};

    for (i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    for (i = 0, j = 0; i <= MAX; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i;
            buckets[i]--;
        }
    }
}

int interpolationSearch(int arr[], int n, int x) {
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

int main() {
    int notas[] = {85, 95, 70, 60, 90, 100, 75, 80, 65, 55};
    int n = sizeof(notas) / sizeof(notas[0]);
    int nota_procurada = 75;

    bucketSort(notas, n);

    printf("Notas ordenadas: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", notas[i]);
    }
    printf("\n");

    int index = interpolationSearch(notas, n, nota_procurada);

    if (index != -1) {
        printf("Nota %d encontrada na posição %d\n", nota_procurada, index);
    } else {
        printf("Nota %d não encontrada\n", nota_procurada);
    }

    return 0;
}
