#include <stdio.h>
#include <stdlib.h>

// raw implementation
typedef struct LinkedListNode {
  int             data;
  LinkedListNode *next;
} LinkedListNode;

static LinkedListNode *createNewNode(int data);
void                   removeLinkedList(LinkedListNode **head);
void                   insertAtBeginning(LinkedListNode **head, int data);
void                   insertAtEnd(LinkedListNode **head, int data);
void                   deleteNode(LinkedListNode **head, int key);
int                    search(LinkedListNode *head, int key);
void                   reverse(LinkedListNode **head);
void                   printList(LinkedListNode *head);
int                    getLength(LinkedListNode *head);
LinkedListNode        *findMiddle(LinkedListNode *head);

static LinkedListNode *createNewNode(int data) {
  LinkedListNode *new_node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  printf("Reserving memory at addres\t%p\n", (void *)new_node);
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void removeLinkedList(LinkedListNode **head) {
  LinkedListNode *current = *head;
  LinkedListNode *next;
  while (current != NULL) {
    next = current->next;
    printf("Freeing up memory at addres\t%p\n", (void *)current);
    free(current);
    current = next;
  }
}

void insertAtEnd(LinkedListNode **head, int data) {
  LinkedListNode *new_node = createNewNode(data);
  if (*head == NULL) {  // if the list is empty
    *head = new_node;
    return;
  }
  LinkedListNode *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insertAtBeginning(LinkedListNode **head, int data) {
  LinkedListNode *new_node = createNewNode(data);
  if (*head == NULL) {  // if the list is empty
    *head = new_node;
    return;
  }
  new_node->next = *head;
  *head          = new_node;
}

void deleteNode(LinkedListNode **head, int key) {
  LinkedListNode *previous;
  LinkedListNode *current = *head;
  while (current->data != key) {
    if (current->next == NULL) {
      return;
    } else {
      previous = current;
      current  = current->next;
    }
  }
  previous->next = current->next;
  printf("Deleting node at\taddres %p\n", (void *)current);
  free(current);
}

int search(LinkedListNode *head, int key) {
  LinkedListNode *current = head;
  int             counter = 0;
  while (current != NULL) {
    if (current->data == key) {
      return counter;
    }
    current = current->next;
    ++counter;
  }
  return -1;
}

int getLength(LinkedListNode *head) {
  LinkedListNode *current = head;
  int             counter = 0;
  while (current != NULL) {
    current = current->next;
    ++counter;
  }
  return counter;
}

LinkedListNode *findMiddle(LinkedListNode *head) {
  LinkedListNode *fastPointer = head;
  LinkedListNode *slowPointer = head;
  while (fastPointer != NULL && fastPointer->next != NULL) {
    fastPointer = fastPointer->next->next;
    slowPointer = slowPointer->next;
  }
  return slowPointer;
}

void reverse(LinkedListNode **head) {
  LinkedListNode *previous = NULL;
  LinkedListNode *current  = *head;
  LinkedListNode *next     = NULL;
  while (current != NULL) {
    next          = current->next;  // save the next node
    current->next = previous;       // reverse direction of current node
    previous      = current;        // move previous to current node
    current       = next;           // change current to next
  }
  *head = previous;
}

void printList(LinkedListNode *head) {
  LinkedListNode *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}