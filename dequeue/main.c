#include <stdio.h>
#include "dequeue.h"

const char *instructions = "\
1. Enqueue front\n\
2. Dequeue front\n\
3. Enqueue rear\n\
4. Dequeue rear\n\
5. Is full\n\
6. Is empty\n\
7. Display\n\
8. Exit\n";

int main() {
  printf("%s", instructions);
  int choice = 0;
  DEQUEUE queue;
  dq_init(&queue);
  int element, ec;

  do {
    printf("> ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &element);
        ec = dq_enqueue_front(&queue, element);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 2:
        ec = dq_dequeue_front(&queue, &element);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        else {
          printf("%d", element);
        }
        break;

      case 3:
        printf("Enter element: ");
        scanf("%d", &element);
        ec = dq_enqueue_rear(&queue, element);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 4:
        ec = dq_dequeue_rear(&queue, &element);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        else {
          printf("%d", element);
        }
        break;

      case 5:
        ec = dq_is_full(&queue);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 6:
        ec = dq_is_empty(&queue);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        break;

      case 7:
        dq_display(&queue);
        break;

      case 8:
        choice = 0;
        break;

      default:
        choice = 1;
        break;
    }
    printf("\n");
  } while (choice);
  return 0;
}
