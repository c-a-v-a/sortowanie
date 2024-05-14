#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#include "algorithms.h"

int _rand_in(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int* _rand_arr(int n) {
    int* xs = malloc(n * sizeof(int));
    int i;

    for (i = 0; i < n; i++)
        xs[i] = _rand_in(VALUE_MIN, VALUE_MAX);

    return xs;
}

int* _desc_arr(int n) {
    int* xs = _rand_arr(n);
    
    qsort(xs, n, sizeof(int), _descending_cmp);

    return xs;
}

int* _asc_arr(int n) {
    int* xs = _rand_arr(n);
    
    qsort(xs, n, sizeof(int), _ascending_cmp);

    return xs;
}

int _ascending_cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int _descending_cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x < y) - (x > y);
}

void _qs_wrapper(int* xs, int s) {
    quicksort(xs, 0, s - 1);
}

void _test_rand(void (*f)(int*,int), int n) {
    int* xs;
    int i;
    clock_t start, end;
    double avg = 0;
    
    printf("\t==RANDOM %d elements==\n", n);

    for (i = 0; i < TEST_AMOUNT; i++) {
        xs = _rand_arr(n);

        start = clock();
        (*f)(xs,n);
        end = clock();

        avg += ((double)(end - start)) / CLOCKS_PER_SEC;

        free(xs);
    }

    printf("\tAVG: %lf\n", (avg / TEST_AMOUNT));
}

void _test_asc(void (*f)(int*,int), int n) {
    int* xs;
    int i;
    clock_t start, end;
    double avg = 0;
    
    printf("\t==ASCENDING %d elements==\n", n);

    for (i = 0; i < TEST_AMOUNT; i++) {
        xs = _asc_arr(n);

        start = clock();
        (*f)(xs,n);
        end = clock();

        avg += ((double)(end - start)) / CLOCKS_PER_SEC;

        free(xs);
    }


    printf("\tAVG: %lf\n", (avg / TEST_AMOUNT));
}

void _test_desc(void (*f)(int*,int), int n) {
    int* xs;
    int i;
    clock_t start, end;
    double avg = 0;
    
    printf("\t==DESCENDING %d elements==\n", n);

    for (i = 0; i < TEST_AMOUNT; i++) {
        xs = _desc_arr(n);

        start = clock();
        (*f)(xs,n);
        end = clock();

        avg += ((double)(end - start)) / CLOCKS_PER_SEC;

        free(xs);
    }


    printf("\tAVG: %lf\n", (avg / TEST_AMOUNT));
}

void run() {
    printf("Insertion sort\n");
    _test_rand(&insertion_sort, 10000);
    _test_rand(&insertion_sort, 25000);
    _test_rand(&insertion_sort, 50000);
    _test_rand(&insertion_sort, 100000);
    _test_rand(&insertion_sort, 250000);
    _test_rand(&insertion_sort, 500000);
    _test_rand(&insertion_sort, 1000000);

    _test_desc(&insertion_sort, 10000);
    _test_desc(&insertion_sort, 25000);
    _test_desc(&insertion_sort, 50000);
    _test_desc(&insertion_sort, 100000);
    _test_desc(&insertion_sort, 250000);
    _test_desc(&insertion_sort, 500000);
    _test_desc(&insertion_sort, 1000000);

    _test_asc(&insertion_sort, 10000);
    _test_asc(&insertion_sort, 25000);
    _test_asc(&insertion_sort, 50000);
    _test_asc(&insertion_sort, 100000);
    _test_asc(&insertion_sort, 250000);
    _test_asc(&insertion_sort, 500000);
    _test_asc(&insertion_sort, 1000000);

    printf("Selection sort\n");
    _test_rand(&selection_sort, 10000);
    _test_rand(&selection_sort, 25000);
    _test_rand(&selection_sort, 50000);
    _test_rand(&selection_sort, 100000);
    _test_rand(&selection_sort, 250000);
    _test_rand(&selection_sort, 500000);

    _test_desc(&selection_sort, 10000);
    _test_desc(&selection_sort, 25000);
    _test_desc(&selection_sort, 50000);
    _test_desc(&selection_sort, 100000);
    _test_desc(&selection_sort, 250000);
    _test_desc(&selection_sort, 500000);

    _test_asc(&selection_sort, 10000);
    _test_asc(&selection_sort, 25000);
    _test_asc(&selection_sort, 50000);
    _test_asc(&selection_sort, 100000);
    _test_asc(&selection_sort, 250000);
    _test_asc(&selection_sort, 500000);

    printf("Bubble sort\n");
    _test_rand(&bubble_sort, 10000);
    _test_rand(&bubble_sort, 25000);
    _test_rand(&bubble_sort, 50000);
    _test_rand(&bubble_sort, 100000);
    _test_rand(&bubble_sort, 250000);
    _test_rand(&bubble_sort, 500000);

    _test_desc(&bubble_sort, 10000);
    _test_desc(&bubble_sort, 25000);
    _test_desc(&bubble_sort, 50000);
    _test_desc(&bubble_sort, 100000);
    _test_desc(&bubble_sort, 250000);
    _test_desc(&bubble_sort, 500000);

    _test_asc(&bubble_sort, 10000);
    _test_asc(&bubble_sort, 25000);
    _test_asc(&bubble_sort, 50000);
    _test_asc(&bubble_sort, 100000);
    _test_asc(&bubble_sort, 250000);
    _test_asc(&bubble_sort, 500000);

    printf("Quicksort\n");
    _test_rand(&_qs_wrapper, 10000);
    _test_rand(&_qs_wrapper, 25000);
    _test_rand(&_qs_wrapper, 50000);
    _test_rand(&_qs_wrapper, 100000);
    _test_rand(&_qs_wrapper, 250000);
    _test_rand(&_qs_wrapper, 500000);
    _test_rand(&_qs_wrapper, 1000000);
    _test_rand(&_qs_wrapper, 2500000);
    _test_rand(&_qs_wrapper, 5000000);
    _test_rand(&_qs_wrapper, 10000000);
    _test_rand(&_qs_wrapper, 25000000);
    _test_rand(&_qs_wrapper, 50000000);
    _test_rand(&_qs_wrapper, 100000000);
    _test_rand(&_qs_wrapper, 250000000);
    _test_rand(&_qs_wrapper, 500000000);
    _test_rand(&_qs_wrapper, 1000000000);

    _test_desc(&_qs_wrapper, 10000);
    _test_desc(&_qs_wrapper, 25000);
    _test_desc(&_qs_wrapper, 50000);
    _test_desc(&_qs_wrapper, 100000);
    _test_desc(&_qs_wrapper, 250000);
    _test_desc(&_qs_wrapper, 500000);
    _test_desc(&_qs_wrapper, 1000000);
    _test_desc(&_qs_wrapper, 2500000);
    _test_desc(&_qs_wrapper, 5000000);
    _test_desc(&_qs_wrapper, 10000000);
    _test_desc(&_qs_wrapper, 25000000);
    _test_desc(&_qs_wrapper, 50000000);
    _test_desc(&_qs_wrapper, 100000000);
    _test_desc(&_qs_wrapper, 250000000);
    _test_desc(&_qs_wrapper, 500000000);
    _test_desc(&_qs_wrapper, 1000000000);

    _test_asc(&_qs_wrapper, 10000);
    _test_asc(&_qs_wrapper, 25000);
    _test_asc(&_qs_wrapper, 50000);
    _test_asc(&_qs_wrapper, 100000);
    _test_asc(&_qs_wrapper, 250000);
    _test_asc(&_qs_wrapper, 500000);
    _test_asc(&_qs_wrapper, 1000000);
    _test_asc(&_qs_wrapper, 1000000);
    _test_asc(&_qs_wrapper, 2500000);
    _test_asc(&_qs_wrapper, 5000000);
    _test_asc(&_qs_wrapper, 10000000);
    _test_asc(&_qs_wrapper, 25000000);
    _test_asc(&_qs_wrapper, 50000000);
    _test_asc(&_qs_wrapper, 100000000);
    _test_asc(&_qs_wrapper, 250000000);
    _test_asc(&_qs_wrapper, 500000000);
    _test_asc(&_qs_wrapper, 1000000000);

    printf("Shellsort\n");
    _test_rand(&shellsort, 10000);
    _test_rand(&shellsort, 25000);
    _test_rand(&shellsort, 50000);
    _test_rand(&shellsort, 100000);
    _test_rand(&shellsort, 250000);
    _test_rand(&shellsort, 500000);
    _test_rand(&shellsort, 1000000);
    _test_rand(&shellsort, 2500000);
    _test_rand(&shellsort, 5000000);
    _test_rand(&shellsort, 10000000);
    _test_rand(&shellsort, 25000000);
    _test_rand(&shellsort, 50000000);
    _test_rand(&shellsort, 100000000);
    _test_rand(&shellsort, 250000000);
    _test_rand(&shellsort, 500000000);
    _test_rand(&shellsort, 1000000000);

    _test_desc(&shellsort, 10000);
    _test_desc(&shellsort, 25000);
    _test_desc(&shellsort, 50000);
    _test_desc(&shellsort, 100000);
    _test_desc(&shellsort, 250000);
    _test_desc(&shellsort, 500000);
    _test_desc(&shellsort, 1000000);
    _test_desc(&shellsort, 2500000);
    _test_desc(&shellsort, 5000000);
    _test_desc(&shellsort, 10000000);
    _test_desc(&shellsort, 25000000);
    _test_desc(&shellsort, 50000000);
    _test_desc(&shellsort, 100000000);
    _test_desc(&shellsort, 250000000);
    _test_desc(&shellsort, 500000000);
    _test_desc(&shellsort, 1000000000);

    _test_asc(&shellsort, 10000);
    _test_asc(&shellsort, 25000);
    _test_asc(&shellsort, 50000);
    _test_asc(&shellsort, 100000);
    _test_asc(&shellsort, 250000);
    _test_asc(&shellsort, 500000);
    _test_asc(&shellsort, 1000000);
    _test_asc(&shellsort, 1000000);
    _test_asc(&shellsort, 2500000);
    _test_asc(&shellsort, 5000000);
    _test_asc(&shellsort, 10000000);
    _test_asc(&shellsort, 25000000);
    _test_asc(&shellsort, 50000000);
    _test_asc(&shellsort, 100000000);
    _test_asc(&shellsort, 250000000);
    _test_asc(&shellsort, 500000000);
    _test_asc(&shellsort, 1000000000);

    printf("Heapsort\n");
    _test_rand(&heapsort, 10000);
    _test_rand(&heapsort, 25000);
    _test_rand(&heapsort, 50000);
    _test_rand(&heapsort, 100000);
    _test_rand(&heapsort, 250000);
    _test_rand(&heapsort, 500000);
    _test_rand(&heapsort, 1000000);
    _test_rand(&heapsort, 2500000);
    _test_rand(&heapsort, 5000000);
    _test_rand(&heapsort, 10000000);
    _test_rand(&heapsort, 25000000);
    _test_rand(&heapsort, 50000000);
    _test_rand(&heapsort, 100000000);
    _test_rand(&heapsort, 250000000);
    _test_rand(&heapsort, 500000000);
    _test_rand(&heapsort, 1000000000);

    _test_desc(&heapsort, 10000);
    _test_desc(&heapsort, 25000);
    _test_desc(&heapsort, 50000);
    _test_desc(&heapsort, 100000);
    _test_desc(&heapsort, 250000);
    _test_desc(&heapsort, 500000);
    _test_desc(&heapsort, 1000000);
    _test_desc(&heapsort, 2500000);
    _test_desc(&heapsort, 5000000);
    _test_desc(&heapsort, 10000000);
    _test_desc(&heapsort, 25000000);
    _test_desc(&heapsort, 50000000);
    _test_desc(&heapsort, 100000000);
    _test_desc(&heapsort, 250000000);
    _test_desc(&heapsort, 500000000);
    _test_desc(&heapsort, 1000000000);

    _test_asc(&heapsort, 10000);
    _test_asc(&heapsort, 25000);
    _test_asc(&heapsort, 50000);
    _test_asc(&heapsort, 100000);
    _test_asc(&heapsort, 250000);
    _test_asc(&heapsort, 500000);
    _test_asc(&heapsort, 1000000);
    _test_asc(&heapsort, 1000000);
    _test_asc(&heapsort, 2500000);
    _test_asc(&heapsort, 5000000);
    _test_asc(&heapsort, 10000000);
    _test_asc(&heapsort, 25000000);
    _test_asc(&heapsort, 50000000);
    _test_asc(&heapsort, 100000000);
    _test_asc(&heapsort, 250000000);
    _test_asc(&heapsort, 500000000);
    _test_asc(&heapsort, 1000000000);
}

