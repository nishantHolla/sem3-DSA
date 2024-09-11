#include <stdio.h>
#include "circular_queue.h"

const char *instructions = "\
1. Enqueue\n\
2. Dequeue\n\
3. Is full\n\
4. Is empty\n\
5. Display\n\
6. Exit\n";

int main() {
  printf("%s", instructions);
  int choice = 0;
  C_QUEUE queue;
  c_queue_init(&queue);
  int element, ec;

  do {
    printf("> ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &element);
        ec = c_queue_enqueue(element, &queue);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 2:
        ec = c_queue_dequeue(&queue, &element);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        else {
          printf("%d", element);
        }
        break;

      case 3:
        ec = c_queue_is_full(&queue);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 4:
        ec = c_queue_is_empty(&queue);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        break;

      case 5:
        c_queue_display(&queue);
        break;

      case 6:
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
