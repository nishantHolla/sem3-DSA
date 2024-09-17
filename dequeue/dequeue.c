#include <stdio.h>
#include "dequeue.h"

int dq_init(DEQUEUE *d) {
  d->front = -1;
  d->rear = -1;
  
  return 0;
}

int dq_is_full(DEQUEUE *d) {
  return (d->rear + 1) % MAX_DEQUEUE_SIZE == d->front;
}

int dq_is_empty(DEQUEUE *d) {
  return d->rear == -1;
}

int dq_enqueue_rear(DEQUEUE *d, int element) {
  if (dq_is_full(d)) {
    return 1;
  }
  
  if (dq_is_empty(d)) {
    d->rear = 0;
    d->front = 0;
  }
  else {
    d->rear = (d->rear + 1) % MAX_DEQUEUE_SIZE;
  }

  d->buffer[d->rear] = element;
  return 0;
}

int dq_dequeue_front(DEQUEUE *d, int *container) {
  if (dq_is_empty(d)) {
    return 1;
  }

  *container = d->buffer[d->front];
  if (d->front == d->rear) {
    dq_init(d);
  }
  else {
    d->front = (d->front + 1) % MAX_DEQUEUE_SIZE;
  }

  return 0;
}

int dq_enqueue_front(DEQUEUE *d, int element) {
  if (dq_is_full(d)) {
    return 1;
  }

  if (dq_is_empty(d)) {
    d->front = 0;
    d->rear = 0;
  }
  else {
    d->front = (d->front - 1 + MAX_DEQUEUE_SIZE) % MAX_DEQUEUE_SIZE;
  }

  d->buffer[d->front] = element;
  return 0;
}

int dq_dequeue_rear(DEQUEUE *d, int *container) {
  if (dq_is_empty(d)) {
    return 1;
  }

  *container = d->buffer[d->rear];

  if (d->front == d->rear) {
    dq_init(d);
  }
  else {
    d->rear = (d->rear - 1 + MAX_DEQUEUE_SIZE) % MAX_DEQUEUE_SIZE;
  }

  return 0;
}

int dq_display(DEQUEUE *d) {
  if (dq_is_empty(d)) {
    printf("Queue is empty\n");
  }

  for (int i=d->front; i != d->rear; i = (i+1)%MAX_DEQUEUE_SIZE) {
    printf("%d ", d->buffer[i]);
  }
  printf("%d\n", d->buffer[d->rear]);

  return 0;
}
