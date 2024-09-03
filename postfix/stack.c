#include "stack.h"
#include <stdio.h>

int stack_init(STACK *st) {
  st->top = -1;
  return 0;
}

int stack_push(STACK *st, int element) {
  if (stack_is_full(st))
    return 1;

  // increment top and then assign element in buffer
  st->buffer[++st->top] = element;
  return 0;
}

int stack_pop(STACK *st, int *container) {
  if (stack_is_empty(st))
    return 1;

  // get element from buffer and then decrement top
  *container = st->buffer[st->top--];
  return 0;
}

int stack_peek(STACK *st, int *container) {
  if (st->top <= -1)
    return 1;

  *container = st->buffer[st->top];
  return 0;
}

int stack_is_full(STACK *st) {
  return (st->top == MAX_STACK_SIZE - 1);
}

int stack_display(STACK *st) {
  if (stack_is_empty(st))
    return 1;

  for (int i=0; i<=st->top; i++) {
    printf("%d ", st->buffer[i]);
  }
  printf("\n");

  return 0;
}

int stack_is_empty(STACK *st) {
  return (st->top <= -1);
}

int stack_size(STACK *st) {
  return st->top + 1;
}
