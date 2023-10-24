#include <stdio.h>

#include "dynamic_queue.c"

int main() {
  DynamicQueue queue;
  initQueue(&queue);
  enqueue(&queue, 1);
  enqueue(&queue, 2);
  // enqueue(&queue, 3);
  // enqueue(&queue, 4);
  // enqueue(&queue, 5);

  print(queue);
  removeDynamicQueue(&queue);
}
