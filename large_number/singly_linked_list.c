#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_list.h"

SLL_NODE *sll_create_node(int element) {
  SLL_NODE *new_node = (SLL_NODE *) malloc(sizeof(SLL_NODE));

  // case 1: malloc failed
  if (!new_node)
    exit(1);

  new_node->data = element;
  new_node->next = NULL;

  return new_node;
}

int sll_init_list(SL_LIST *list) {
  list->head = NULL;
  list->size = 0;

  return 0;
}

int sll_insert_front(SL_LIST *list, int element) {
  SLL_NODE *new_node = sll_create_node(element);

  new_node->next = list->head;
  list->head = new_node;
  ++list->size;

  return 0;
}

int sll_insert_at(SL_LIST *list, int element, int index) {
  // case 1: index out of bound
  if (index < 0 || index >= list->size)
    return 1;

  SLL_NODE *new_node = sll_create_node(element);

  // case 2: insert node at start
  if (index == 0) {
    new_node->next = list->head;
    list->head = new_node;
    ++list->size;
    return 0;
  }

  // case 3: insert node at end or in between
  SLL_NODE *t_node = list->head;
  int i = 0;

  while (i != index - 1 && t_node) {
    t_node = t_node->next;
    i++;
  }

  new_node->next = t_node->next;
  t_node->next = new_node;
  ++list->size;

  return 0;
}

int sll_insert_back(SL_LIST *list, int element) {
  SLL_NODE *new_node = sll_create_node(element);

  SLL_NODE *t_node = list->head;

  while (t_node->next)
    t_node = t_node->next;

  // case 1: list is empty
  if (list->head == NULL)
    list->head = new_node;

  // case 2: list is not empty
  else
    t_node->next = new_node;

  ++list->size;
  return 0;
}

int sll_delete_front(SL_LIST *list, int *container) {
  SLL_NODE *top_node = list->head;

  // case 1: list is empty
  if (top_node == NULL)
    return 1;

  // case 2: list is not empty
  *container = top_node->data;
  list->head = list->head->next;
  --list->size;
  free(top_node);

  return 0;
}

int sll_delete_at(SL_LIST *list, int *container, int index) {
  // case 1: index out of bound
  if (index < 0 || index >= list->size)
    return 1;

  // case 2: list is empty
  if (!list->head)
    return 2;

  // case 3: delete first node
  if (index == 0) {
    *container = list->head->data;
    free(list->head);
    list->head = NULL;
    --list->size;
    return 0;
  }

  // case 4: delete last or in between node
  SLL_NODE *t_node = list->head;
  int i = 0;

  while (i != index - 1 && t_node) {
    t_node = t_node->next;
    ++i;
  }

  SLL_NODE *temp = t_node->next;
  t_node->next = temp ? temp->next : NULL;
  *container = temp->data;
  free(temp);
  --list->size;

  return 0;
}

int sll_delete_back(SL_LIST *list, int *container) {
  SLL_NODE *t_node = list->head;

  // case 1: list is empty
  if (t_node == NULL)
    return 1;

  // case 2: list has only 1 element
  if (!t_node->next) {
    *container = t_node->data;
    free(t_node);
    list->head = NULL;
    list->size = 0;

    return 0;
  }

  // case 3: list has more than 1 element
  while (t_node->next && t_node->next->next)
    t_node = t_node->next;

  *container = t_node->next->data;
  --list->size;
  free(t_node->next);
  t_node->next = NULL;

  return 0;
}

int sll_display_list(SL_LIST *list) {
  SLL_NODE *t_node = list->head;

  while (t_node) {
    printf("%d ", t_node->data);
    t_node = t_node->next;
  }

  printf("\n");
  return 0;
}

int sll_search_list(SL_LIST *list, int element) {
  SLL_NODE *t_node = list->head;

  while (t_node) {
    // case 1: element is found
    if (t_node->data == element)
      return 1;
    t_node = t_node->next;
  }

  // case 2: element is not found
  return 0;
}

int sll_free_list(SL_LIST *list) {
  SLL_NODE *t_node = list->head;

  while (t_node) {
    SLL_NODE *temp = t_node;
    t_node = t_node->next;
    free(temp);
  }

  list->size = 0;
  return 0;
}

// extra
int sll_reverse_list(SL_LIST *list) {
  // case 1: list is empty
  if (list->head == NULL)
    return 1;

  // case 2: list has only one element
  if (list->head->next == NULL)
    return 2;

  // case 3: list has more than one element
  SLL_NODE *tl_node = NULL;
  SLL_NODE *tm_node = list->head;
  SLL_NODE *tr_node = list->head->next;

  while (tm_node) {
    SLL_NODE *temp;
    tm_node->next = tl_node;

    if (tr_node) {
      temp = tr_node->next;
      tr_node->next = tm_node;
    }

    tl_node = tm_node;
    tm_node = tr_node;
    tr_node = temp;
  }

  list->head = tl_node;
  return 0;
}
