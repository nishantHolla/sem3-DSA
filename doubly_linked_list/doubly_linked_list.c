#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"

DLL_NODE *dll_create_node(int element) {
  DLL_NODE *new_node = (DLL_NODE *) malloc(sizeof(DLL_NODE));

  new_node->data = element;
  new_node->next = NULL;
  new_node->prev = NULL;

  return new_node;
}

int dll_init_list(DL_LIST *list) {
  list->head = NULL;
  list->size = 0;

  return 0;
}

int dll_insert_front(DL_LIST *list, int element) {
  DLL_NODE *new_node = (DLL_NODE *) malloc(sizeof(DLL_NODE));
  new_node->data = element;

  new_node->next = list->head;

  if (list->head)
    list->head->prev = new_node;

  list->head = new_node;
  ++list->size;
  return 0;
}

int dll_insert_at(DL_LIST *list, int element, int index) {
  // case 1: index is out of bound
  if (index < 0 || index > list->size)
    return 1;

  // case 2: index is zero
  if (index == 0) {
    dll_insert_front(list, element);
    return 0;
  }

  DLL_NODE *new_node = dll_create_node(element);
  int i = 0;

  DLL_NODE *t_node = list->head;
  while (i != index - 1 && t_node) {
    t_node = t_node->next;
    ++i;
  }

  // case 3: new node is not the last node
  if (t_node->next) {
    t_node->next->prev = new_node;
    new_node->next = t_node->next;
  }

  t_node->next = new_node;
  new_node->prev = t_node;

  ++list->size;
  return 0;
}

int dll_insert_back(DL_LIST *list, int element) {
  DLL_NODE *new_node = (DLL_NODE *) malloc(sizeof(DLL_NODE));
  new_node->data = element;

  // case 1: list is empty
  if (list->head == NULL) {
    list->head = new_node;
    ++list->size;
    return 0;
  }

  DLL_NODE *t_node = list->head;
  while (t_node->next)
    t_node = t_node->next;

  // case 2: list is not empty
  t_node->next = new_node;
  new_node->prev = t_node;
  ++list->size;
  return 0;
}

int dll_delete_front(DL_LIST *list, int *container) {
  DLL_NODE *t_node = list->head;

  // case 1: list is empty
  if (list->head == NULL)
    return 1;

  // case 2: list is not empty
  *container = list->head->data;

  // case 3: list has more than one node
  if (list->head->next)
    list->head->next->prev = NULL;

  list->head = list->head->next;
  --list->size;
  free(t_node);

  return 0;
}

int dll_delete_at(DL_LIST *list, int *container, int index) {

  // case 1: index is out of bound
  if (index < 0 || index > list->size)
    return 1;

  // case 2: list is empty
  if (list->head == NULL)
    return 2;

  // case 3: list has only one element
  if (!list->head->next) {
    *container = list->head->data;
    free(list->head);
    list->head = NULL;
    --list->size;
    return 0;
  }

  int i = 0;
  DLL_NODE *t_node = list->head;

  while (i != index && t_node) {
    t_node = t_node->next;
    ++i;
  }

  // case 4: list has more than one element
  if (t_node->prev)
    t_node->prev->next = t_node->next;
  else
    list->head = t_node->next;

  if (t_node->next)
    t_node->next->prev = t_node->prev;

  *container = t_node->data;
  free(t_node);
  --list->size;

  return 0;
}

int dll_delete_back(DL_LIST *list, int *container) {
  DLL_NODE *t_node = list->head;

  // case 1: list is empty
  if (list->head == NULL)
    return 1;

  // case 2: list has only one element
  if (!list->head->next) {
    *container = t_node->data;
    free(list->head);
    list->head = NULL;
    --list->size;
    return 0;
  }

  // case 3: list has more than one element
  while (t_node->next)
    t_node = t_node->next;

  *container = t_node->data;
  if (t_node->prev)
    t_node->prev->next = NULL;
  free(t_node);
  --list->size;

  return 0;
}

int dll_display_list(DL_LIST *list) {
  DLL_NODE *t_node = list->head;

  while (t_node) {
    printf("%d ", t_node->data);
    t_node = t_node->next;
  }

  printf("\n");
  return 0;
}

int dll_search_list(DL_LIST *list, int element) {
  if (!list->head)
    return 0;

  DLL_NODE *t_node = list->head;
  
  while (t_node) {
    if (t_node->data == element)
      return 1;
    t_node = t_node->next;
  }

  return 0;
}

int dll_free_list(DL_LIST *list) {
  DLL_NODE *t_node = list->head;

  while (t_node) {
    DLL_NODE *temp = t_node;
    t_node = t_node->next;
    free(temp);
  }

  list->head = NULL;
  list->size = 0;
  return 0;
}

// extra
int dll_reverse_list(DL_LIST *list) {
  // case 1: list is empty
  if (list->head == NULL)
    return 1;
  
  // case 2: list has only one element
  if (list->head->next == NULL)
    return 2;

  // case 3: list has more than one element
  DLL_NODE *l_node = NULL;
  DLL_NODE *m_node = list->head;
  DLL_NODE *r_node = list->head->right;

  while (m_node) {
    DLL_NODE *temp = r_node->next;

    m_node->next = l_node;
    m_node->prev = r_node;
  }
}
