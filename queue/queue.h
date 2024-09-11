#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_QUEUE_LENGTH 5

typedef  struct {
  int buffer[MAX_QUEUE_LENGTH];
  int front;
  int rear;
} QUEUE;

int queue_init(QUEUE *q);
int queue_enqueue(int element, QUEUE *q);
int queue_dequeue(QUEUE *q, int *container);
int queue_is_full(QUEUE *q);
int queue_is_empty(QUEUE *q);
int queue_display(QUEUE *q);


#endif // QUEUE_H_
