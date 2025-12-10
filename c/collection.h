#include <stdint.h>

typedef struct _SLL_Node SLL_Node;

typedef struct _SinglyLinkedList {
  SLL_Node *head;
  uint32_t size;
} SLL;

struct _SLL_Node {
  int value;
  SLL_Node *next;
};

SLL *sll_create();
SLL_Node *sll_push_back(SLL *list, int value);
void sll_destroy(SLL *list);

void sll_print(SLL *list);


void test_collection();
