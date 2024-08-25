#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h> // For using `bool`, `true`, and `false`

typedef struct {
  int *data;
  int cap;
  int vecSize;
  int front; // Index of the front element
  int rear;  // Index of the rear element
  int size;  // Number of elements in the queue
} queue;

// Function to create and initialize a new queue
queue *make_queue();

// Function to enqueue an element to the queue
void queue_enqueue(queue *q, int value);

// Function to dequeue an element from the queue
int queue_dequeue(queue *q);

// Function to peek at the front element of the queue without dequeuing it
int queue_peek(const queue *q);

// Function to check if the queue is empty
bool queue_isEmpty(const queue *q);
int queue_size(const queue *q);
int queue_cap(const queue *q);
int queue_front(const queue *q);
int queue_rear(const queue *q);
// Function to free the queue and its resources
void queue_free(queue *q);

#endif // QUEUE_H
