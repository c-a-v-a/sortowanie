#ifndef TEST_H
#define TEST_H

#define TEST_AMOUNT 1

#define VALUE_MIN -100
#define VALUE_MAX 100

int _rand_in(int min, int max);

int* _rand_arr(int n);

int* _desc_arr(int n);

int* _asc_arr(int n);

int _ascending_cmp(const void* a, const void* b);

int _descending_cmp(const void* a, const void* b);

void _qs_wrapper(int* xs, int s);

void _test_rand(void (*f)(int*,int), int n);

void _test_asc(void (*f)(int*,int), int n);

void _test_desc(void (*f)(int*,int), int n);

void run();

#endif
