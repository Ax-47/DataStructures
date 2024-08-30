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
LinkedListiterator sll_insert(singlyLinkedList *ll, LinkedListiterator it,
                              int value);
void sll_emplace(LinkedListiterator it, int value);
LinkedListiterator sll_erase(singlyLinkedList *ll, LinkedListiterator it);

LinkedListiterator sll_pushAtHead(singlyLinkedList *ll, int value);
LinkedListiterator sll_pushAtTail(singlyLinkedList *ll, int value);
int sll_popAtTail(singlyLinkedList *ll);
int sll_popAtHead(singlyLinkedList *ll);
void sll_clear(singlyLinkedList *ll);

// print
void sll_print(const singlyLinkedList *ll);
void sll_free(singlyLinkedList *ll);
#endif // SINGLY_LINKED_LIST_H
