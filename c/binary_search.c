#include "algo.h"
#include <stddef.h>
#include <stdio.h>

BS_IntPair binary_search(int *array, int array_length, int item) {
  int iterations = 0;

  if (array == NULL) {
    return (BS_IntPair){.iter = 0, .pos = -1};
  }

  int low = 0;
  int high = array_length - 1;
  while (low < high) {
    iterations += 1;

    int mid = (low + high) / 2;
    printf("mid: %d\n", mid);
    int item_at_mid = array[mid];
    if (item_at_mid > item) {
      high = mid - 1;
    } else if (item_at_mid < item) {
      low = mid + 1;
    } else {
      return (BS_IntPair){.iter = iterations, .pos = mid};
    }
  }

  if (array[low] == item) {
    return (BS_IntPair){.iter = iterations, .pos = low};
  }

  return (BS_IntPair){.iter = iterations, .pos = -1};
}

void print_BS_IntPair(BS_IntPair *res) {
  if (res == NULL) {
    return;
  }

  printf("BS_IntPair { iter: %d, pos: %d }\n", res->iter, res->pos);
}
