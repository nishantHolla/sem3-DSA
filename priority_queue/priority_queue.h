#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_
#include "singly_linked_list.h"

typedef SL_LIST P_QUEUE;

int p_queue_init(P_QUEUE *q);
int p_queue_is_empty(P_QUEUE *q);
int p_queue_dequeue(P_QUEUE *q, int *container);
int p_queue_enqueue(P_QUEUE *q, int data, int priority);
int p_queue_display(P_QUEUE *q);

#endif //!PRIORITY_QUEUE_H_
