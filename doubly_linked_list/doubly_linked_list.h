#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct DLL_NODE {
  int data;
  int size;
  struct DLL_NODE *next;
  struct DLL_NODE *prev;
} DLL_NODE;

typedef struct DL_LIST {
  DLL_NODE *head;
  int size;
} DL_LIST;

DLL_NODE *dll_create_node(int element);

int dll_init_list(DL_LIST *list);

int dll_insert_front(DL_LIST *list, int element);
int dll_insert_back(DL_LIST *list, int element);
int dll_insert_at(DL_LIST *list, int element, int index);

int dll_delete_front(DL_LIST *list, int *container);
int dll_delete_back(DL_LIST *list, int *container);
int dll_delete_at(DL_LIST *list, int *container, int index);

int dll_display_list(DL_LIST *list);

int dll_search_list(DL_LIST *list, int element);

int dll_free_list(DL_LIST *list);

// extra
int dll_reverse_list(DL_LIST *list);

#endif // DOUBLY_LINKED_LIST_H_
