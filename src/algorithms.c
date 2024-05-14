#include "algorithms.h"

#include <stdbool.h>

void _swap(int* x, int* y) {
    int tmp = *x;

    *x = *y;
    *y = tmp;
}

void _heapify(int* xs, int s, int i) {
    int max = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;

    if (left < s && xs[left] > xs[max])
        max = left;

    if (right < s && xs[right] > xs[max])
        max = right;

    if (max != i) {
        _swap(&xs[i], &xs[max]);
        _heapify(xs, s, max);
    }
}

void insertion_sort(int* xs, int s) {
    int i, j;

    for (i = 0; i < s; i++) {
        j = i;
        for (; j > 0 && xs[j] < xs[j - 1]; j--) {
            _swap(&xs[j], &xs[j - 1]);
        }
    }
}

void selection_sort(int* xs, int s) {
    int i, j;
    int min;

    for (i = 0; i < s; i++) {
        min = i;

        for (j = i + 1; j < s; j++) {
            if (xs[j] < xs[min])
                min = j;
        }

        if (min != i) {
            _swap(&xs[i], &xs[min]);
        }
    }
}

void bubble_sort(int* xs, int s) {
    int i;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (i = 1; i < s; i++) {
            if (xs[i - 1] > xs[i]) {
                _swap(&xs[i - 1], &xs[i]);
                swapped = true;
            }
        }
    }
}

void quicksort(int* xs, int first, int last) {
    int i = first;
    int j = last;
    int s = xs[(i+j) / 2];
    int temp;

    do {
        while (xs[i] < s) i++;
        while (xs[j] > s) j--;

        if (i <= j) {
            _swap(&xs[i], &xs[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > first) quicksort(xs, first, j);
    if (i < last) quicksort(xs, i, last);
}

void shellsort(int* xs, int s) {
    int i, j;
    int tmp;
    int gap = s / 2;

    for (; gap > 0; gap /= 2) {
        for (i = gap; i < s; i++) {
            tmp = xs[i];

            for (j = i; j >= gap && xs[j - gap] > tmp; j -= gap) {
                xs[j] = xs[j - gap];
            }

            xs[j] = tmp;
        }
    }
}

void heapsort(int* xs, int s) {
    int i;

    for (i = s / 2 - 1; i >= 0; i--)
        _heapify(xs, s, i);

    for (i = s - 1; i > 0; i--) {
        _swap(&xs[0], &xs[i]);
        _heapify(xs, i, 0);
    }
}
