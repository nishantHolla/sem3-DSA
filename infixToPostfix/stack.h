#ifndef STACK_H_
#define STACK_H_

#define MAX_STACK_SIZE 50

typedef struct {
  int buffer[MAX_STACK_SIZE];
  int top;
} STACK;

int stack_init(STACK *st);

int stack_push(STACK *st, int element);

int stack_pop(STACK *st, int *container);

int stack_peek(STACK *st, int *container);

int stack_is_full(STACK *st);

int stack_is_empty(STACK *st);

int stack_display(STACK *st);

int stack_size(STACK *st);

#endif // !STACK_H_
