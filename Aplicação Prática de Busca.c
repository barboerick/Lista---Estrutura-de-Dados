#include <stdio.h>
#include <string.h>

typedef struct {
    char ISBN[20];
    char title[100];
} Book;

int binary_search(Book arr[], int n, char* x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int cmp = strcmp(arr[mid].ISBN, x);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    Book library_records[] = {
        {"0001", "Livro A"},
        {"0002", "Livro B"},
        {"0003", "Livro C"},
        {"0004", "Livro D"},
        {"0005", "Livro E"}
    };
    int n = sizeof(library_records) / sizeof(library_records[0]);

    char isbn_to_find[] = "0003";

    int index = binary_search(library_records, n, isbn_to_find);

    if (index != -1) {
        printf("Livro encontrado: %s\n", library_records[index].title);
    } else {
        printf("Livro não encontrado\n");
    }

    return 0;
}
