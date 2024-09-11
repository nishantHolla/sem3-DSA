#include <stdio.h>
#include "priority_queue.h"

const char *instructions = "\
1. Enqueue\n\
2. Dequeue\n\
3. Is empty\n\
4. Display\n\
5. Exit\n";

int main() {
  printf("%s", instructions);
  int choice = 0;
  P_QUEUE queue;
  p_queue_init(&queue);
  int element, ec, priority;

  do {
    printf("> ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &element);
        printf("Enter priority: ");
        scanf("%d", &priority);
        ec = p_queue_enqueue(&queue, element, priority);
        if (ec == 1) {
          printf("Queue is full\n");
        }
        break;

      case 2:
        ec = p_queue_dequeue(&queue, &element);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        else {
          printf("%d", element);
        }
        break;

      case 3:
        ec = p_queue_is_empty(&queue);
        if (ec == 1) {
          printf("Queue is empty\n");
        }
        break;

      case 4:
        p_queue_display(&queue);
        break;

      case 5:
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
