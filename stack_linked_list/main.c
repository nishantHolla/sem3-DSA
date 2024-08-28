#include <stdio.h>
#include "stack_ll.h"

const char *instructions = "\
1. Push\n\
2. Pop\n\
3. Peek\n\
4. Is empty\n\
5. Display\n\
6. Exit";

int main() {
  int choice = 1;
  STACK_LL stack;

  stack_init(&stack);

  while (choice) {
    int ec, element;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &element);
        ec = stack_push(&stack, element);
        if (ec == 1) {
          printf("Stack is full\n");
        }
        break;

      case 2:
        ec = stack_pop(&stack, &element);
        if (ec == 0) {
          printf("%d popped\n", element);
        }
        else {
          printf("Stack is empty\n");
        }
        break;

      case 3:
        ec = stack_peek(&stack, &element);
        if (ec == 0) {
          printf("%d\n", element);
        }
        else {
          printf("Stack is empty\n");
        }
        break;

      case 4:
        printf("%d\n", stack_is_empty(&stack));
        break;

      case 5:
        stack_display(&stack);
        break;

      case 6:
        choice = 0;
        break;

      default:
        choice = 1;
        break;

    }

    printf("Stack size: %d\n", stack_size(&stack));
  }

  stack_free(&stack);
  return 0;
}
