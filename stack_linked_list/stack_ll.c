#include <stdio.h>
#include "stack_ll.h"

int stack_init(STACK_LL *st) {
  return sll_init_list(st);
}

int stack_push(STACK_LL *st, int element) {
  return sll_insert_front(st, element);
}

int stack_pop(STACK_LL *st, int *container) {
  return sll_delete_front(st, container);
}

int stack_is_empty(STACK_LL *st) {
  return (st->head == NULL);
}

int stack_peek(STACK_LL *st, int *container) {
  if (stack_is_empty(st))
    return 1;

  *container = st->head->data;
  return 0;
}

int stack_display(STACK_LL *st) {
  return sll_display_list(st);
}

int stack_free(STACK_LL *st) {
  return sll_free_list(st);
}

int stack_size(STACK_LL *st) {
  return st->size;
}
