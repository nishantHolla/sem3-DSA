#include <stdio.h>
#include "arraylist.h"

int init_array(ArrayList *p_list) {
  p_list->write_head = 0;
  return 0;
}

int insert_at_end(ArrayList *p_list, int element) {
  if (p_list->write_head >= MAX_ARRAY_SIZE)
    return 1;

  p_list->list[p_list->write_head] = element;
  ++p_list->write_head;
  return 0;
}

int delete_at_end(ArrayList *p_list, int *element) {
  if (p_list->write_head <= 0)
    return 1;

  --p_list->write_head;
  *element = p_list->list[p_list->write_head];
  return 0;
}

int display_array(ArrayList *p_list) {
  for (int i=0; i < p_list->write_head; i++)
    printf("%d ", p_list->list[i]);

  printf("\n");
}
