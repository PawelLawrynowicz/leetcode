#include <stdio.h>
#include <stdlib.h>

#include <list>

// raw implementation
typedef struct Node {
  int   data;
  Node *next;
} Node;

static Node *createNewNode(int data);
void         removeLinkedList(Node **head);
void         insertAtBeginning(Node **head, int data);
void         insertAtEnd(Node **head, int data);
void         deleteNode(Node **head, int key);
int          search(Node *head, int key);
void         reverse(Node **head);
void         printList(Node *head);
int          getLength(Node *head);
Node        *findMiddle(Node *head);

static Node *createNewNode(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  printf("Reserving memory at addres\t%p\n", (void *)new_node);
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void removeLinkedList(Node **head) {
  Node *current = *head;
  Node *next;
  while (current != NULL) {
    next = current->next;
    printf("Freeing up memory at addres\t%p\n", (void *)current);
    free(current);
    current = next;
  }
}

void insertAtEnd(Node **head, int data) {
  Node *new_node = createNewNode(data);
  if (*head == NULL) {  // if the list is empty
    *head = new_node;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insertAtBeginning(Node **head, int data) {
  Node *new_node = createNewNode(data);
  if (*head == NULL) {  // if the list is empty
    *head = new_node;
    return;
  }
  new_node->next = *head;
  *head          = new_node;
}

void deleteNode(Node **head, int key) {
  Node *previous;
  Node *current = *head;
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

int search(Node *head, int key) {
  Node *current = head;
  int   counter = 0;
  while (current != NULL) {
    if (current->data == key) {
      return counter;
    }
    current = current->next;
    ++counter;
  }
  return -1;
}

int getLength(Node *head) {
  Node *current = head;
  int   counter = 0;
  while (current != NULL) {
    current = current->next;
    ++counter;
  }
  return counter;
}

Node *findMiddle(Node *head) {
  Node *fastPointer = head;
  Node *slowPointer = head;
  while (fastPointer != NULL && fastPointer->next != NULL) {
    fastPointer = fastPointer->next->next;
    slowPointer = slowPointer->next;
  }
  return slowPointer;
}

void reverse(Node **head) {
  Node *previous = NULL;
  Node *current  = *head;
  Node *next     = NULL;
  while (current != NULL) {
    next          = current->next;  // save the next node
    current->next = previous;       // reverse direction of current node
    previous      = current;        // move previous to current node
    current       = next;           // change current to next
  }
  *head = previous;
}

void printList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// stl
std::list<int> stl_list = {1, 2, 3, 4, 5};
