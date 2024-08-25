#include "../../queue/queue.h"
#include <stdio.h>

int main() {
  // Create and initialize a new queue
  queue *q = make_queue();

  // Enqueue elements to the queue
  queue_enqueue(q, 10);
  queue_enqueue(q, 20);
  queue_enqueue(q, 30);
  queue_enqueue(q, 40);

  // Display the current size and capacity of the queue
  printf("Queue size: %d\n", queue_size(q));
  printf("Queue capacity: %d\n", queue_cap(q));

  // Peek at the front element
  printf("Front element is: %d\n", queue_peek(q));

  // Dequeue elements from the queue
  printf("Dequeued: %d\n", queue_dequeue(q));
  printf("Dequeued: %d\n", queue_dequeue(q));

  // Display the front and rear indexes
  printf("Front index: %d\n", queue_front(q));
  printf("Rear index: %d\n", queue_rear(q));

  // Check if the queue is empty
  if (queue_isEmpty(q)) {
    printf("The queue is empty.\n");
  } else {
    printf("The queue is not empty.\n");
  }

  // Enqueue more elements
  queue_enqueue(q, 50);
  queue_enqueue(q, 60);

  // Dequeue the remaining elements
  while (!queue_isEmpty(q)) {
    printf("Dequeued: %d\n", queue_dequeue(q));
  }

  // Check again if the queue is empty
  if (queue_isEmpty(q)) {
    printf("The queue is now empty.\n");
  }

  // Free the queue
  queue_free(q);

  return 0;
}
