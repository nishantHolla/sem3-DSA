#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

typedef struct SLL_NODE {
  int data;
  struct SLL_NODE *next;
} SLL_NODE;

typedef struct SL_LIST {
  SLL_NODE *head;
  int size;
} SL_LIST;

SLL_NODE *sll_create_node(int element);

int sll_init_list(SL_LIST *list);

int sll_insert_front(SL_LIST *list, int element);
int sll_insert_at(SL_LIST *list, int element, int index);
int sll_insert_back(SL_LIST *list, int element);

int sll_delete_front(SL_LIST *list, int *container);
int sll_delete_at(SL_LIST *list, int *container, int index);
int sll_delete_back(SL_LIST *list, int *container);

int sll_search_list(SL_LIST *list, int element);

int sll_display_list(SL_LIST *list);

int sll_free_list(SL_LIST *list);


#endif // SINGLY_LINKED_LIST_H_
