#include <stdio.h>

typedef struct _BS_IntPair {
    int pos;   // -1 or index of the value if it's found
    int iter;  // number of iterations the search took
} BS_IntPair;

BS_IntPair binary_search(int *array, int array_length, int item);

void print_BS_IntPair(BS_IntPair *res);

void test_binary_search();
