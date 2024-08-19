#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct DLL_NODE {
  int data;
  struct DLL_NODE *next;
  struct DLL_NODE *prev;
} DLL_NODE;

typedef struct DL_LIST {
  DLL_NODE *head;
  int size;
} DL_LIST;

DLL_NODE *dll_create_node(int element);

int dll_init_list(&list);

#endif // DOUBLY_LINKED_LIST_H_
