#include "../../singlyLinkedList/singlyLinkedList.h"
#include <stdio.h>

int main() {
  singlyLinkedList *myList = make_sll();

  // Insert elements at the head
  sll_insertAtHead(myList, 10);
  sll_insertAtHead(myList, 20);
  sll_insertAtHead(myList, 30);

  // Insert elements at the tail
  sll_insertAtTail(myList, 40);
  sll_insertAtTail(myList, 50);

  // Iterate through the list and print the elements
  sll_print(myList);

  LinkedListiterator begin = sll_begin(myList);
  LinkedListiterator next = sll_advance(begin, 1);

  if (next != NULL) {
    printf("The value at the next node is: %d\n", next->value);
  } else {
    printf("Next node is out of bounds.\n");
  }
  // Clean up memory (not implemented in your code, but important to add)

  return 0;
}
