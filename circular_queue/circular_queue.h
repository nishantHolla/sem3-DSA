#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#define MAX_CIRCULAR_QUEUE_LENGTH 5

typedef struct {
  int buffer[MAX_CIRCULAR_QUEUE_LENGTH];
  int front;
  int rear;
} C_QUEUE;

int c_queue_init(C_QUEUE *q);
int c_queue_is_full(C_QUEUE *q);
int c_queue_is_empty(C_QUEUE *q);
int c_queue_enqueue(int element, C_QUEUE *q);
int c_queue_dequeue(C_QUEUE *q, int *container);
int c_queue_display(C_QUEUE *q);

#endif // !CIRCULAR_QUEUE_H_
