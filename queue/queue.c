#include <stdbool.h>
#include <stdlib.h>
typedef struct {
  int *data;
  int cap;
  int front; // Index of the front element
  int rear;  // Index of the rear element
  int size;  // Number of elements in the queue
} queue;
queue *make_queue() {
  queue *newQueue = malloc(sizeof(queue));
  newQueue->data = malloc(sizeof(int) * 4);
  newQueue->cap = 4;
  newQueue->front = 0;
  newQueue->rear = 0;
  newQueue->size = 0;

  return newQueue;
}
bool queue_isEmpty(const queue *q) { return q->size == 0; }
int queue_size(const queue *q) { return q->size; }
int queue_cap(const queue *q) { return q->cap; }
int queue_front(const queue *q) { return q->front; }
int queue_rear(const queue *q) { return q->rear; }
void recap(queue *q) {
  int *arr = malloc((q->cap * 2) * sizeof(int));
  int j = 0;

  for (int i = q->front; i < q->cap; j++, i++)
    arr[j] = q->data[i];
  for (int i = 0; i < q->rear; i++, j++)
    arr[j] = q->data[i];
  free(q->data);
  q->data = arr;
  q->rear = j;
  q->front = 0;
  q->cap *= 2;
}
void queue_enqueue(queue *q, int value) {
  if (q->size >= q->cap) {
    recap(q);
  }
  q->data[q->rear] = value;
  q->rear = (q->rear + 1) % q->cap;
  q->size++;
}

int queue_dequeue(queue *q) {
  if (queue_isEmpty(q))
    return 0;
  int value = q->data[q->front];
  q->front = (q->front + 1) % q->cap;
  q->size--;
  return value;
}
int queue_peek(queue *q) {
  if (queue_isEmpty(q))
    return 0;
  int value = q->data[q->front];
  return value;
}
void queue_free(queue *q) {
  free(q->data);
  free(q);
}
