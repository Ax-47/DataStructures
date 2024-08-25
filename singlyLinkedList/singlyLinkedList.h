#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>

// Definition of the node structure
typedef struct node {
  int value;
  struct node *next;
} node;

typedef node *LinkedListiterator;
// Definition of the singly linked list structure
typedef struct {
  LinkedListiterator head;
  LinkedListiterator tail;
  int size;
} singlyLinkedList;

// Function declarations
singlyLinkedList *make_sll();
// iterator
LinkedListiterator sll_begin(const singlyLinkedList *ll);
LinkedListiterator sll_end(const singlyLinkedList *ll);
void sll_itNext(const LinkedListiterator *it);
LinkedListiterator sll_advance(LinkedListiterator it, int steps);
// monify
LinkedListiterator sll_makeNode(int value);
LinkedListiterator sll_insertAtHead(singlyLinkedList *ll, int value);
LinkedListiterator sll_insertAtTail(singlyLinkedList *ll, int value);
// print
void sll_print(const singlyLinkedList *ll);
#endif // SINGLY_LINKED_LIST_H
