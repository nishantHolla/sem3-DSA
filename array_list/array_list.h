#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#define MAX_ARRAY_SIZE 10

typedef struct ArrayList {
  int list[MAX_ARRAY_SIZE];
  int write_head;
} ArrayList;

int init_array(ArrayList *p_list);
int insert_at_end(ArrayList *p_list, int element);
int delete_at_end(ArrayList *p_list, int *element);
int display_array(ArrayList *p_list);

#endif // ARRAY_LIST_H_
