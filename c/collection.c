#include "collection.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

SLL_Node *node_create(int value) {
  SLL_Node *new_node;
  new_node = malloc(sizeof(*new_node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void sll_node_destroy(SLL_Node *node) {
  if (node == NULL) {
    return;
  }

  free(node);
  node = NULL;
}

SLL *sll_create() {
  SLL *list;
  list = malloc(sizeof(*list));
  list->head = NULL;
  list->size = 0;
  return list;
}

SLL_Node *sll_push_back(SLL *list, int value) {
  if (list == NULL) {
    return NULL;
  }

  SLL_Node *curr_node = list->head;
  if (curr_node == NULL) { // set as a head node
    SLL_Node *head_node = node_create(value);
    if (head_node == NULL) {
      return NULL;
    }
    list->head = head_node;
    list->size += 1;
    return head_node;
  } else {
    SLL_Node *new_node = NULL;
    while (curr_node != NULL) {
      if (curr_node->next == NULL) {
        curr_node->next = node_create(value);
        new_node = curr_node->next;
        list->size += 1;
        break;
      } else {
        curr_node = curr_node->next;
      }
    }
    return new_node;
  }
}

void sll_destroy(SLL *list) {
  if (list == NULL) {
    return;
  }
  // traverse all the nodes and free them all
  SLL_Node *curr_node = list->head;
  while (curr_node != NULL) {
    SLL_Node *next_node = curr_node->next;
    free(curr_node);
    curr_node = NULL;
    if (next_node != NULL) {
      curr_node = next_node;
    }
  }

  free(list);
  list = NULL;
}

void sll_print(SLL *list) {
  if (list == NULL) {
    return;
  }

  // 2: [value] -> [value] -> NULL
  printf("%d:", list->size);
  SLL_Node *curr_node = list->head;
  if (curr_node == NULL) {
    printf(" NULL \n");
  } else {
    while (curr_node != NULL) {
      printf(" [%d]", curr_node->value);
      SLL_Node *next_node = curr_node->next;
      printf(" ->");
      if (next_node != NULL) {
        curr_node = next_node;
      } else {
        printf(" NULL \n");
        break;
      }
    }
  }
}

void test_collection() {
  SLL *list = sll_create();

  sll_push_back(list, 3);  // 0
  sll_push_back(list, 4);  // 1
  sll_push_back(list, 0);  // 2
  sll_push_back(list, 4);  // 3
  sll_push_back(list, 9);  // 4
  sll_push_back(list, 26); // 5
  sll_push_back(list, -8); // 6

  assert(list->size == 7);  

  sll_print(list);
  sll_destroy(list);
}
