#include <stdio.h>
#include "priority_queue.h"
#include "singly_linked_list.h"

int p_queue_init(P_QUEUE *q) {
  sll_init_list(q);
  return 0;
}

int p_queue_is_empty(P_QUEUE *q) {
  return q->size == 0;
}

int p_queue_dequeue(P_QUEUE *q, int *container) {
  return sll_delete_front(q, container);
}

int p_queue_enqueue(P_QUEUE *q, int element, int priority) {
  int i = 0;
  SLL_NODE *t_node = q->head;

  if (q->size == 0) {
    return sll_insert_front(q, element, priority);
  }

  while (t_node && t_node->priority < priority) {
    i++;
    t_node = t_node->next;
  }

  if (!t_node) {
    return sll_insert_back(q, element, priority);
  }

  return sll_insert_at(q, element, i, priority);
}

int p_queue_display(P_QUEUE *q) {
  return sll_display_list(q);
}
