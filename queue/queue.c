#include <stdlib.h>
#include "queue.h"

int queue_init(QUEUE *q) {
  q->front = 0;
  q->rear = -1;
  
  return 0;
}

int queue_enqueue(int element, QUEUE *q) {
  if (q == NULL) {
    return 1;
  }

  if (queue_is_full(q)) {
    return 1;
  }

  q->rear++;
  q->buffer[q->rear] = element;

  return 0;
}


int queue_dequeue(QUEUE *q, int *container) {
  if (q == NULL) {
    return 1;
  }

  if (queue_is_empty(q)) {
    return 1;
  }

  *container = q->buffer[q->front];
  q->front++;

  return 0;
}

int queue_is_full(QUEUE *q) {
  if (q == NULL) {
    return 0;
  }

  return (q->rear == MAX_QUEUE_LENGTH - 1);
}

int queue_is_empty(QUEUE *q) {
  if (q == NULL) {
    return 1;
  }

  return (q->rear == -1 || q->front == MAX_QUEUE_LENGTH);
}

