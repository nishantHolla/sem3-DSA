#include <stdlib.h>
#include <stdio.h>
#include "circular_doubly_linked_list.h"

CDLL_NODE *cdll_create_node(int element) {
  CDLL_NODE *new_node = (CDLL_NODE *) malloc(sizeof(CDLL_NODE));

  if (new_node == NULL)
    return NULL;

  new_node->data = element;
  return new_node;
}

int cdll_init_list(CDL_LIST *list) {
  list->head = NULL;
  list->size = 0;

  return 0;
}

int cdll_insert_front(CDL_LIST *list, int element) {
  CDLL_NODE *new_node = cdll_create_node(element);

  // case 1: list is empty
  if (list->head == NULL) {
    list->head = new_node;
    list->head->next = new_node;
    list->head->prev = new_node;
    ++list->size;
    return 0;
  }

  // case 2: list is not empty
  CDLL_NODE *last = list->head->prev;
  new_node->next = list->head;
  new_node->prev = last;
  last->next = new_node;
  list->head->prev = new_node;
  list->head = new_node;

  ++list->size;
  return 0;
}

int cdll_insert_at(CDL_LIST *list, int element, int index) {
  // case 1: index is out of bound
  if (index < 0 | index > list->size)
    return 1;

  // case 2: insert at front
  if (index == 0) {
    cdll_insert_front(list, element);
    return 0;
  }

  // case 3: insert at last
  if (index == list->size) {
    cdll_insert_back(list, element);
    return 0;
  }

  CDLL_NODE *new_node = cdll_create_node(element);

  int i = 0;
  CDLL_NODE *t_node = list->head;
  while (i != index) {
    t_node = t_node->next;
    ++i;
  }

  new_node->prev = t_node->prev;
  t_node->prev->next = new_node;
  new_node->next = t_node;
  t_node->prev = new_node;
  ++list->size;
  return 0;
}

int cdll_insert_back(CDL_LIST *list, int element) {
  CDLL_NODE *new_node = cdll_create_node(element);

  // case 1: list is empty
  if (list->head == NULL) {
    list->head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    ++list->size;
    return 0;
  }

  // case 2: list is not empty
  CDLL_NODE *last = list->head->prev;
  last->next = new_node;
  list->head->prev = new_node;
  new_node->next = list->head;
  new_node->prev = last;
  ++list->size;
  return 0;
}

int cdll_delete_front(CDL_LIST *list, int *container) {

  // case 1: list is empty
  if (list->head == NULL)
    return 1;

  CDLL_NODE *last = list->head->prev;

  // case 2: list contains only one element
  if (list->head == last) {
    *container = list->head->data;
    free(list->head);
    list->head = NULL;
    --list->size;
    return 0;
  }

  // case 3: list contains more than one element
  *container = list->head->data;
  last->next = list->head->next;
  list->head->next->prev = last;
  free(list->head);
  --list->size;
  list->head = last->next;

  return 0;
}

int cdll_delete_at(CDL_LIST *list, int *container, int index) {
  // case 1: index is outbound
  if (index < 0 || index > list->size - 1)
    return 1;

  // case 2: deleting first node
  if (index == 0) {
    cdll_delete_front(list, container);
    return 0;
  }

  // case 3: deleting last node
  if (index == list->size - 1) {
    cdll_delete_back(list, container);
    return 0;
  }

  // case 4: deleting middle node
  int i = 0;
  CDLL_NODE *t_node;

  while (i != index) {
    t_node = t_node->next;
    ++i;
  }

  *container = t_node->data;
  t_node->prev->next = t_node->next;
  t_node->next->prev = t_node->prev;
  free(t_node);
  --list->size;
  return 0;
}

int cdll_delete_back(CDL_LIST *list, int *container) {
  // case 1: list is empty
  if (list->head == NULL)
    return 1;

  CDLL_NODE *last = list->head->prev;

  // case 2: list contains only one element
  if (list->head == last) {
    *container = list->head->data;
    free(list->head);
    list->head = NULL;
    --list->size;
    return 0;
  }

  // case 3: list contains more than one element
  last->prev->next = list->head;
  list->head->prev = last->prev;
  *container = last->data;
  free(last);
  --list->size;
  return 0;
}

int cdll_search_list(CDL_LIST *list, int element) {
  CDLL_NODE *t_node = list->head;

  // case 1: list is empty
  if (!t_node)
    return 0;

  // case 2: list exists
  do {
    if (t_node->data == element)
      return 1;
    t_node = t_node->next;
  } while (t_node != list->head);

  return 0;
}

int cdll_display_list(CDL_LIST *list) {
  if (!list->head) {
    printf("\n");
    return 0;
  }

  CDLL_NODE *t_node = list->head;

  do {
    printf("%d ", t_node->data);
    t_node = t_node->next;
  } while (t_node != list->head);
  
  printf("\n");
  return 0;
}

int cdll_free_list(CDL_LIST *list) {
  CDLL_NODE *t_node = list->head;

  if (list->head)
    list->head->prev->next = NULL;

  while (t_node) {
    CDLL_NODE *temp = t_node;
    t_node = t_node->next;
    free(temp);
  }


  list->head = NULL;
  list->size = 0;
  return 0;
}
