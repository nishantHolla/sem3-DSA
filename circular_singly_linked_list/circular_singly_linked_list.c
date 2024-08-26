#include "circular_singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

CSLL_NODE *csll_create_node(int element) {
  CSLL_NODE *new_node = (CSLL_NODE *) malloc(sizeof(CSLL_NODE));

  // case 1: malloc failed
  if (!new_node)
    exit(1);

  new_node->data = element;
  return new_node;
}

int csll_init_list(CSL_LIST *list) {
  list->tail = NULL;
  list->size = 0;

  return 0;
}

int csll_insert_front(CSL_LIST *list, int element) {
  CSLL_NODE *new_node = csll_create_node(element);

  // case 1: list is empty
  if (list->tail == NULL) {
    list->tail = new_node;
    new_node->next = new_node;
  }

  // case 2: list is not empty
  else {
    new_node->next = list->tail->next;
    list->tail->next = new_node;
  }

  ++list->size;
  return 0;
}

int csll_insert_at(CSL_LIST *list, int element, int index) {
  // case 1: index is out of bound
  if (index < 0 || index > list->size) {
    return 1;
  }

  // case 2: inserting at front
  if (list->tail == NULL || index == 0) {
    csll_insert_front(list, element);
    return 0;
  }

  // case 3: inserting at last
  if (index == list->size) {
    csll_insert_back(list, element);
    return 0;
  }

  // case 4: inserting in between
  CSLL_NODE *new_node = csll_create_node(element);
  int i = 0;
  CSLL_NODE *t_node = list->tail;

  while (i != index && t_node->next) {
    t_node = t_node->next;
    ++i;
  }

  new_node->next = t_node->next;
  t_node->next = new_node;

  ++list->size;
  return 0;
}

int csll_insert_back(CSL_LIST *list, int element) {
  CSLL_NODE *new_node = csll_create_node(element);

  // case 1: list is empty
  if (list->tail == NULL) {
    list->tail = new_node;
    new_node->next = new_node;
  }

  // case 2: list is not empty
  else {
    new_node->next = list->tail->next;
    list->tail->next = new_node;
    list->tail = new_node;
  }

  ++list->size;
  return 0;
}

int csll_delete_front(CSL_LIST *list, int *container) {

  // case 1: list is empty
  if (!list->tail)
    return 0;

  // case 2: list has only one element
  if (list->tail == list->tail->next) {
    *container = list->tail->data;
    free(list->tail);
    list->tail = NULL;
  }

  // case 3: list has more than one element
  else {
    CSLL_NODE *temp = list->tail->next;
    *container = temp->data;
    list->tail->next = temp->next;
    free(temp);
  }

  --list->size;
  return 0;
}

int csll_delete_at(CSL_LIST *list, int *container, int index) {
  // case 1: index is out of bound
  if (index < 0 || index > list->size);

  // case 2: list is empty
  if (list->tail == NULL)
    return 1;

  // case 3: deleting first element
  if (index == 0) {
    csll_delete_front(list, container);
    return 0;
  }

  // case 4: deleting last element
  if (index == list->size-1) {
    csll_delete_back(list, container);
    return 0;
  }

  // case 5: deleting in between element
  CSLL_NODE *t_node = list->tail;
  int i = 0;
  while (i == index - 1) {
    t_node = t_node->next;
    ++i;
  }

  printf("---%d\n", t_node->data);
  *container = t_node->next->data;
  CSLL_NODE *temp = t_node->next;
  t_node->next = t_node->next->next;

  free(temp);
  --list->size;
  return 0;
}

int csll_delete_back(CSL_LIST *list, int *container) {

  // case 1: list is empty
  if (!list->tail)
    return 0;

  // case 2: list has only one element
  if (list->tail == list->tail->next) {
    *container = list->tail->data;
    free(list->tail);
    list->tail = NULL;
  }

  // case 3: list has more than one element
  else {
    CSLL_NODE *t_node = list->tail->next;

    while (t_node->next != list->tail)
      t_node = t_node->next;

    *container = list->tail->data;
    t_node->next = list->tail->next;
    free(list->tail);
    list->tail = t_node;
  }

  --list->size;
  return 0;

}

int csll_display_list(CSL_LIST *list) {
  if (list->tail) {
    CSLL_NODE *t_node = list->tail->next;

    do {
      printf("%d ", t_node->data);
      t_node = t_node->next;
    } while (t_node != list->tail->next);
  }

  printf("\n");
  return 0;
}

int csll_free_list(CSL_LIST *list) {
  // case 1: list is empty
  if (list->tail == NULL)
    return 0;

  // case 2: list is not empty
  CSLL_NODE *t_node = list->tail->next;
  list->tail->next = NULL;

  while (t_node) {
    CSLL_NODE *temp = t_node;
    t_node = t_node->next;
    free(temp);
  }

  csll_init_list(list);
  return 0;
}
