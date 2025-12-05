#include "algo.h"

int main(void) {
  int list[] = {1, 2, 8, 10, 11, 12, 13};
  int item = 9;
  int length = sizeof(list)/sizeof(int);
  BS_IntPair result = binary_search(list, length, item);
  print_BS_IntPair(&result);
  return 0;
}
