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
  for (; it != NULL && steps > 0; steps--)
    sll_itNext(&it);

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
LinkedListiterator sll_insert(singlyLinkedList *ll, LinkedListiterator it,
                              int value) {
  LinkedListiterator newNode = sll_makeNode(value);
  if (newNode == NULL)
    return NULL;
  LinkedListiterator temp = ll->head;
  while (temp->next != it)
    sll_itNext(&temp);
  temp->next = newNode;
  newNode->next = it;
  return temp;
}
void sll_emplace(LinkedListiterator it, int value) { it->value = value; };
LinkedListiterator sll_erase(singlyLinkedList *ll, LinkedListiterator it) {
  LinkedListiterator temp = ll->head;
  while (temp->next != it)
    sll_itNext(&temp);
  temp->next = temp->next->next;
  free(it);
  return temp;
}

LinkedListiterator sll_pushAtHead(singlyLinkedList *ll, int value) {
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

LinkedListiterator sll_pushAtTail(singlyLinkedList *ll, int value) {
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
int sll_popAtHead(singlyLinkedList *ll) {
  if (ll->head == NULL)
    return -1;
  LinkedListiterator temp = ll->head->next;
  int tempValue = ll->head->value;
  free(ll->head);
  ll->head = temp;
  ll->size--;
  if (ll->size == 0)
    ll->tail = NULL;

  return tempValue;
}

int sll_popAtTail(singlyLinkedList *ll) {
  if (ll->tail == NULL)
    return -1;
  int tempValue = ll->tail->value;
  LinkedListiterator tempIt = sll_advance(ll->head, ll->size - 2);
  free(ll->tail);
  ll->tail = tempIt;
  ll->tail->next = NULL;
  ll->size--;
  return tempValue;
}
void sll_clear(singlyLinkedList *ll) {
  while (ll->head != NULL) {
    sll_popAtHead(ll);
  }
}
// print
void sll_print(const singlyLinkedList *ll) {
  LinkedListiterator it = sll_begin(ll);
  for (; it != NULL; sll_itNext(&it))
    printf("%d -> ", it->value);

  printf("NULL\n");
}
// free
void sll_free(singlyLinkedList *ll) {
  sll_clear(ll);
  free(ll);
}
