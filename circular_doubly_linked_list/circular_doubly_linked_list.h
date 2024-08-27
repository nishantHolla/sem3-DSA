#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H_
#define CIRCULAR_DOUBLY_LINKED_LIST_H_

typedef struct CDLL_NODE {
  int data;
  struct CDLL_NODE *next;
  struct CDLL_NODE *prev;
} CDLL_NODE;

typedef struct CDL_LIST {
  CDLL_NODE *head;
  int size;
} CDL_LIST;

CDLL_NODE *cdll_create_node(int element);

int cdll_init_list(CDL_LIST *list);

int cdll_insert_front(CDL_LIST *list, int element);
int cdll_insert_at(CDL_LIST *list, int element, int index);
int cdll_insert_back(CDL_LIST *list, int element);

int cdll_delete_front(CDL_LIST *list, int *container);
int cdll_delete_at(CDL_LIST *list, int *container, int index);
int cdll_delete_back(CDL_LIST *list, int *container);

int cdll_search_list(CDL_LIST *list, int element);

int cdll_display_list(CDL_LIST *list);

int cdll_free_list(CDL_LIST *list);

#endif // CIRCULAR_DOUBLY_LINKED_LIST_H_
