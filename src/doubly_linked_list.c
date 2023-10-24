#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
  int                   data;
  DoublyLinkedListNode* previous;
  DoublyLinkedListNode* next;
} DoublyLinkedListNode;

static DoublyLinkedListNode* createNewNode(int data) {
  DoublyLinkedListNode* new_node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
  printf("Reserving memory at addres\t%p\n", (void*)new_node);
  new_node->data     = data;
  new_node->previous = NULL;
  new_node->next     = NULL;
  return new_node;
}

void removeDoublyLinkedList(DoublyLinkedListNode** head) {
  while (*head != NULL) {
    DoublyLinkedListNode* next_node = (*head)->next;
    printf("Freeing up memory at addres\t%p\n", (void*)(*head));
    free(*head);
    *head = next_node;
  }
}

void insertAtEndDoubly(DoublyLinkedListNode** head, int data) {
  DoublyLinkedListNode* new_node = createNewNode(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  DoublyLinkedListNode* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next      = new_node;
  new_node->previous = current;
}

void insertAtBeginningDoubly(DoublyLinkedListNode** head, int data) {
  DoublyLinkedListNode* new_node = createNewNode(data);

  if (*head == NULL) {
    *head = new_node;
    return;
  }
  DoublyLinkedListNode* current = *head;
  if (current->previous == NULL) {
    new_node->next    = current;
    current->previous = new_node;
    current           = new_node;
  }
}

void printListDoublyFromStart(DoublyLinkedListNode* head) {
  DoublyLinkedListNode* current = head;
  printf("NULL <- ");
  while (current != NULL) {
    printf("%d ", current->data);
    if (current->next == NULL) {
      printf("-> ");
      break;
    }
    printf("<-> ");
    current = current->next;
  }
  printf("NULL\n");
}

void deleteAtGivenPosDoubly(DoublyLinkedListNode** head, int idx) {
  DoublyLinkedListNode* current  = *head;
  DoublyLinkedListNode* previous = NULL;
  // idx HAS to be not longer than the list itself !!!
  for (int i = 0; i < idx; ++i) {
    previous = current;
    current  = current->next;
  }
  DoublyLinkedListNode* next = current->next;
  if (previous == NULL) {  // deleting head node
    *head          = next;
    next->previous = NULL;
    printf("Freeing up memory at addres %p\n", (void*)current);
    free(current);
    return;
  } else if (next == NULL) {  // deleting tail node
    previous->next = NULL;
    printf("Freeing up memory at addres %p\n", (void*)current);
    free(current);
    return;
  }
  // deleting other nodes
  previous->next = next;
  next->previous = previous;
  printf("Freeing up memory at addres %p\n", (void*)current);
  free(current);
}

void deleteNodeDoubly(DoublyLinkedListNode** head, int key) {
  DoublyLinkedListNode* current  = *head;
  DoublyLinkedListNode* previous = NULL;
  while (current != NULL) {
    if (current->data == key) {
      DoublyLinkedListNode* next = current->next;
      if (current->previous == NULL) {
        *head          = next;
        next->previous = NULL;
        printf("Freeing up memory at addres %p\n", (void*)current);
        free(current);
        return;
      } else if (next == NULL) {
        previous->next = NULL;
        printf("Freeing up memory at addres %p\n", (void*)current);
        free(current);
        return;
      }

      previous->next = next;
      next->previous = previous;
      printf("Freeing up memory at addres %p\n", (void*)current);
      free(current);
    }
    previous = current;
    current  = current->next;
  }
}
int findMiddleDoubly(DoublyLinkedListNode* head) {
  DoublyLinkedListNode* fastPointer = head;
  DoublyLinkedListNode* slowPointer = head;

  while (fastPointer != NULL && fastPointer->next != NULL) {
    fastPointer = fastPointer->next->next;
    slowPointer = slowPointer->next;
  }
  return slowPointer->data;
}

int searchDoubly(DoublyLinkedListNode* head, int val) {
  DoublyLinkedListNode* current = head;

  int counter = 0;
  while (current != NULL) {
    if (current->data == val) {
      return counter;
    }
    current = current->next;
    ++counter;
  }
  return -1;
}

int reverseDoubly(DoublyLinkedListNode** head) {
  DoublyLinkedListNode* current = *head;
  DoublyLinkedListNode* temp    = NULL;
  while (current != NULL) {
    temp              = current->previous;
    current->previous = current->next;
    current->next     = temp;

    if (current->previous == NULL) {
      *head = current;
      break;
    }

    current = current->previous;
  }
}

void printListDoublyFromEnd(DoublyLinkedListNode* tail) {
  DoublyLinkedListNode* current = tail;
  printf("NULL <- ");
  while (current != NULL) {
    printf("%d ", current->data);
    if (current->next == NULL) {
      printf("-> ");
      break;
    }
    printf("<-> ");
    current = current->next;
  }
  printf("NULL\n");
}
