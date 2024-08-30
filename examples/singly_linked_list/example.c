#include "../../singlyLinkedList/singlyLinkedList.h"
#include <stdio.h>

int main() {
  // Create a new singly linked list
  singlyLinkedList *myList = make_sll();

  // Insert elements at the head
  sll_pushAtHead(myList, 10);
  sll_pushAtHead(myList, 20);
  sll_pushAtHead(myList, 30);

  // Insert elements at the tail
  sll_pushAtTail(myList, 40);
  sll_pushAtTail(myList, 50);

  // Print the list
  printf("List after inserting elements at head and tail:\n");
  sll_print(myList);

  // Advance an iterator
  LinkedListiterator begin = sll_begin(myList);
  LinkedListiterator next = sll_advance(begin, 1);
  if (next != NULL) {
    printf("Value at the second node: %d\n", next->value);
  } else {
    printf("Second node is out of bounds.\n");
  }

  // Insert a new node before the second node
  sll_insert(myList, next, 25);
  printf("List after inserting 25 before the second node:\n");
  sll_print(myList);

  // Modify a node value
  sll_emplace(next, 35);
  printf("List after modifying the second node value to 35:\n");
  sll_print(myList);

  // Erase the modified node
  sll_erase(myList, next);
  printf("List after erasing the modified node:\n");
  sll_print(myList);

  // Pop at head
  int poppedValue = sll_popAtHead(myList);
  printf("Popped value at head: %d\n", poppedValue);
  printf("List after popping at head:\n");
  sll_print(myList);

  // Pop at tail
  poppedValue = sll_popAtTail(myList);
  printf("Popped value at tail: %d\n", poppedValue);
  printf("List after popping at tail:\n");
  sll_print(myList);

  // Clear the list
  sll_clear(myList);
  printf("List after clearing all elements:\n");
  sll_print(myList);

  // Free the list
  sll_free(myList);

  return 0;
}
