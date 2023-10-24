#include <stdbool.h>

#include "linked_list.c"

typedef LinkedListNode Node;

typedef struct Queue {
  Node* front;
  Node* rear;
} Queue;

void initQueue(Queue* queue) {
  queue->front = NULL;
  queue->rear  = NULL;
}

bool isEmpty(Queue* queue) {
  return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
  Node* new_element = (Node*)malloc(sizeof(Node));
  printf("Reserving memory at\t%p\n", (void*)new_element);
  new_element->next = NULL;
  new_element->data = data;

  if (queue->front == NULL) {
    queue->front = new_element;
    queue->rear  = new_element;
  } else {
    queue->rear->next = new_element;
    queue->rear       = new_element;
  }
}

void deque(Queue* queue, int n_to_deque = 1) {
  for (int i = 0; i < n_to_deque; ++i) {
    if (queue->front == NULL) {
      return;
    }
    Node* new_front = queue->front->next;
    printf("Freeing memory at\t%p\n", (void*)queue->front);
    free(queue->front);
    queue->front = new_front;
  }
}

int peekQueue(Queue queue) {
  return queue.front->data;
}

int queueLenght(Queue queue) {
  int counter = 0;
  while (queue.front != NULL) {
    queue.front = queue.front->next;
    ++counter;
  }
  return counter;
}

void removeQueue(Queue* queue) {
  Node* current = queue->front;
  while (current != NULL) {
    current = current->next;
    printf("Freeing memory at\t%p\n", (void*)queue->front);
    free(queue->front);
    queue->front = current;
  }
}

void printQueue(Queue queue) {
  Node* current = queue.front;
  while (current != NULL) {
    printf("%d, ", current->data);
    current = current->next;
  }
  printf("END\n");
}