#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int value;
  struct node *next;
} node;

typedef node *LinkedListiterator;
typedef struct {
  LinkedListiterator head;
  LinkedListiterator tail;
  int size;
} singlyLinkedList;

singlyLinkedList *make_sll() {
  singlyLinkedList *newLL = malloc(sizeof(singlyLinkedList));
  if (newLL == NULL)
    return NULL;

  newLL->head = NULL;
  newLL->tail = NULL;
  newLL->size = 0;
  return newLL;
}
// iterator
LinkedListiterator sll_begin(const singlyLinkedList *ll) { return ll->head; }
LinkedListiterator sll_end(const singlyLinkedList *ll) { return ll->tail; }
void sll_itNext(LinkedListiterator *it) { *it = (*it)->next; }
LinkedListiterator sll_advance(LinkedListiterator it, int steps) {
  for (; it != NULL && steps > 0; steps--) {
    sll_itNext(&it);
  }
  return it;
}

// modify
LinkedListiterator sll_makeNode(int value) {
  node *newNode = malloc(sizeof(node));
  if (newNode == NULL)
    return NULL;

  newNode->value = value;
  return newNode;
}
LinkedListiterator sll_insertAtHead(singlyLinkedList *ll, int value) {
  LinkedListiterator newNode = sll_makeNode(value);
  if (newNode == NULL)
    return NULL;
  LinkedListiterator temp = ll->head;
  ll->head = newNode;
  ll->head->next = temp;
  if (ll->tail == NULL)
    ll->tail = ll->head;
  ll->size++;
  return ll->head;
}

LinkedListiterator sll_insertAtTail(singlyLinkedList *ll, int value) {
  LinkedListiterator newNode = sll_makeNode(value);
  if (newNode == NULL)
    return NULL;

  if (ll->tail == NULL) {
    ll->head = newNode;
    ll->tail = newNode;
  } else {
    ll->tail->next = newNode;
    ll->tail = newNode;
  }
  ll->size++;
  return ll->tail;
}
void sll_print(const singlyLinkedList *ll) {
  for (LinkedListiterator it = sll_begin(ll); it != NULL; sll_itNext(&it)) {
    printf("%d -> ", it->value);
  }
  printf("NULL\n");
}
