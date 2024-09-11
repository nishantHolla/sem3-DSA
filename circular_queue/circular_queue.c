#include <stdio.h>
#include "circular_queue.h"

int c_queue_init(C_QUEUE *q) {
  q->front = -1;
  q->rear = -1;

  return 0;
}

int c_queue_is_full(C_QUEUE *q) {
  return (q->rear + 1) % MAX_CIRCULAR_QUEUE_LENGTH == q->front;
}

int c_queue_is_empty(C_QUEUE *q) {
  return q->rear == -1;
}

int c_queue_enqueue(int element, C_QUEUE *q) {
  if (c_queue_is_full(q)) {
    return 1;
  }

  if (c_queue_is_empty(q)) {
    q->front = 0;
    q->rear = 0;
    q->buffer[q->rear] = element;
  }
  else {
    q->rear = (q->rear + 1) % MAX_CIRCULAR_QUEUE_LENGTH;
    q->buffer[q->rear] = element;
  }

  return 0;
}

int c_queue_dequeue(C_QUEUE *q, int *container) {
  if (c_queue_is_empty(q)) {
    return 1;
  }

  *container = q->buffer[q->front];
  if (q->front == q->rear) {
    c_queue_init(q);
    return 0;
  }

  q->front = (q->front + 1) % MAX_CIRCULAR_QUEUE_LENGTH;
}

int c_queue_display(C_QUEUE *q) {
  for (int i=q->front; i!=q->rear; i=(i+1)%MAX_CIRCULAR_QUEUE_LENGTH) {
    printf("%d ", q->buffer[i]);
  }
  printf("%d", q->buffer[q->rear]);

  printf("\n");
  return 0;
}
