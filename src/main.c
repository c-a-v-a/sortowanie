#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "algorithms.h"
#include "menu.h"
#include "test.h"

void print_array(int* xs, int s) {
    int i;
    for (i = 0; i < s; i++)
        printf("%d ", xs[i]);
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp("-t", argv[1]) == 0) {
        run();

        return 0;
    }

    // menu option
    int choice;
    // helpers
    int temp;
    int scanned = 0;
    int s;      // array size
    int* xs;    // input array
    int* ys;    // output array
    bool sorted;

    FILE* dane = fopen("dane", "r");

    if (!dane) {
        printf("Could not open data file.\n");
        return 0;
    }

    printf("Array size: ");
    scanf("%d", &s);

    xs = malloc(s * sizeof(int));
    ys = malloc(s * sizeof(int));

    if (!xs || !ys) {
        printf("Memory allocation error.\n");
        fclose(dane);
        return 0;
    }

    while(fscanf(dane, "%d", &temp) == 1 && scanned < s) {
        xs[scanned] = temp;
        scanned++;
    }

    if (scanned < s - 1) {
        printf("Chosen array size is too big\n");
        free(xs);
        free(ys);
        fclose(dane);
        return 0;
    }

    fclose(dane);

    printf("Your array:\n");
    print_array(xs, s);
    printf("\n");

    // hold og array, so we read from file once
    memcpy(ys, xs, s * sizeof(int));

    do {
        sorted = false;
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case InsertSort:
                printf("\nInsert sort\n");

                insertion_sort(ys,s);

                sorted = true;
                break;
            case SelectionSort:
                printf("\nSelection sort\n");

                selection_sort(ys,s);

                sorted = true;
                break;
            case BubbleSort:
                printf("\nBubble sort\n");

                bubble_sort(ys,s);

                sorted = true;
                break;
            case Quicksort:
                printf("\nQuicksort\n");

                quicksort(ys,0,s - 1);

                sorted = true;
                break;
            case Shellsort:
                printf("\nShellsort\n");

                shellsort(ys,s);

                sorted = true;
                break;
            case Heapsort:
                printf("\nHeapsort\n");

                heapsort(ys,s);

                sorted = true;
                break;
            case End:
                break;
            default:
                printf("\nInvalid option\n");
                break;
        }

        if (sorted) {
            printf("Input:\n");
            print_array(xs,s);
            printf("Output:\n");
            print_array(ys,s);
            printf("\n");
        }

        memcpy(ys, xs, s * sizeof(int));
    } while (choice != End);

    free(xs);
    free(ys);
}
