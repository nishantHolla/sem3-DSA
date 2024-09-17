#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#define MAX_DEQUEUE_SIZE 5

typedef struct {
  int buffer[MAX_DEQUEUE_SIZE];
  int front;
  int rear;
} DEQUEUE;

int dq_init(DEQUEUE *d);
int dq_is_full(DEQUEUE *d);
int dq_is_empty(DEQUEUE *d);
int dq_display(DEQUEUE *d);

int dq_enqueue_rear(DEQUEUE *d, int element);
int dq_dequeue_rear(DEQUEUE *d, int *container);

int dq_enqueue_front(DEQUEUE *d, int element);
int dq_dequeue_front(DEQUEUE *d, int *container);

#endif // !DEQUEUE_H_
