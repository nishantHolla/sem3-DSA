#include <stdlib.h>
#include "doubly_linked_list.h"

DLL_NODE *dll_create_node(int element) {
  DLL_NODE *new_node = (DLL_NODE *) malloc(sizeof(DLL_NODE));

  DLL_NODE->data = element;
  DLL_NODE->next = NULL;
  DLL_NODE->prev = NULL;

  return new_node;
}

int dll_init_list(&list) {
  list->head = NULL;
  list->size = 0;

  return 0;
}
