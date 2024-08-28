#ifndef STACK_LL_H_
#define STACK_LL_H_

#include "singly_linked_list.h"

typedef SL_LIST STACK_LL;

int stack_init(STACK_LL *st);

int stack_push(STACK_LL *st, int element);

int stack_pop(STACK_LL *st, int *container);

int stack_peek(STACK_LL *st, int *container);

int stack_is_empty(STACK_LL *st);

int stack_display(STACK_LL *st);

int stack_size(STACK_LL *st);

int stack_free(STACK_LL *st);

#endif // !STACK_LL_H_
