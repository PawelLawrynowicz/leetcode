#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_QUEUE_SIZE 10

typedef struct DynamicQueue {
  int* array;
  int  capacity;
  int  front;
  int  rear;
  int  size;
} DynamicQueue;

void initQueue(DynamicQueue* queue) {
  queue->array    = (int*)malloc(INIT_QUEUE_SIZE * sizeof(int));
  queue->capacity = 10;
  queue->front    = -1;
  queue->rear     = -1;
  queue->size     = 0;
  printf("ALLOC:\t%p\n", (void*)queue->array);
}

bool isEmpty(DynamicQueue queue) {
  return queue.front == -1;
}

bool isFull(DynamicQueue queue) {
  return queue.size == queue.capacity;
}

void enqueue(DynamicQueue* queue, int data) {
  if (queue->size == 0) {
    queue->array[0] = data;
    queue->size += 1;
    queue->front = 0;
    queue->rear  = 0;
  }
}

void removeDynamicQueue(DynamicQueue* queue) {
  printf("FREE:\t%p\n", (void*)queue->array);
  free(queue->array);
}

void print(DynamicQueue queue) {
  for (int i = 0; i < queue.size; ++i) {
    printf("%d, ", queue.array[i]);
  }
  printf("END\n");
}