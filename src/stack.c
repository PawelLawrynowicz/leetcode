#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack* stack) {
  stack->top = -1;
}

bool isEmpty(Stack* stack) {
  return stack->top == -1;
}

bool isFull(Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int data) {
  if (isFull(stack)) {
    return;
  }

  stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->arr[--stack->top];
}

int peek(Stack* stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->arr[stack->top];
}