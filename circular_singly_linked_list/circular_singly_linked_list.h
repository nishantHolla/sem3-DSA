#ifndef CIRCULAR_SINGLY_LINKED_LIST_H_
#define CIRCULAR_SINGLY_LINKED_LIST_H_

typedef struct CSLL_NODE {
  int data;
  struct CSLL_NODE *next;
} CSLL_NODE;

typedef struct CSL_LIST {
  CSLL_NODE *tail;
  int size;
} CSL_LIST;

CSLL_NODE *csll_create_node(int element);

int csll_init_list(CSL_LIST *list);

int csll_insert_front(CSL_LIST *list, int element);
int csll_insert_at(CSL_LIST *list, int element, int index);
int csll_insert_back(CSL_LIST *list, int element);

int csll_delete_front(CSL_LIST *list, int *container);
int csll_delete_at(CSL_LIST *list, int *container, int index);
int csll_delete_back(CSL_LIST *list, int *container);

int csll_display_list(CSL_LIST *list);

int csll_free_list(CSL_LIST *list);

#endif // CIRCULAR_SINGLY_LINKED_LIST
