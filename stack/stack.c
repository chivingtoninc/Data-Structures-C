/* --------------------------------------------------------------------------------- *
 * Name: Johnathan Chivington (github|twitter|facebook|linkedin -> @chivingtoninc)   *
 * Project: Data Structures (C) -> Stack                                             *
 * Description: Stack implementation in C.                                           *
 * License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like.              *
 * --------------------------------------------------------------------------------- */


/* ------------------------------------ Includes ----------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "time.h"
// fprintf(stdout, "%lun", (unsigned long)time(NULL));


/* ------------------------------------ Globals ------------------------------------ */
// Determine platform
#ifdef _WIN32
  #define SYS "WIN"
#else
  #define SYS "UNIX"
#endif


/* ------------------------------------ Helpers ------------------------------------ */
// bar under title/heading
char* bar(char* str) {
  char * bar;
  for (int i = 0; i < sizeof str; i++) bar += "-";
  return bar;
}

// clear screen
void clr() {
  system(SYS == "WIN" ? "cls" : "clear");
}

// pause program
void pause(char* msg) {
  fprintf(stdout, (strlen(msg) > 0) ? "\n %s\n", msg : "\n Press enter to continue...\n");
  while (getchar() != "\n");
}

// greet user
void greet() {
  printf("\n C Stack\n %s", bar("C Stack"));
}


/* ----------------------------------- Structures ---------------------------------- */
typedef struct StackNode {
  int value;                  // the value that the node holds
  StackNode* next;            // pointer to the next node in the stack
} StackNode;

// struct StackNode {
//   int data;
//   struct StackNode* next;
// };

// typedef struct Stack {
//   size_t size;                // size of the stack
//   StackNode* top;             // pointer to top node in stack
// } Stack;


/* ------------------------------------ Methods ------------------------------------ */
Stack* push(Stack* stack, int value) {
  // in: stack pointer & value to place on stack
  // out: stack pointer with additional StackNode
  // err: (-1 = general error)
}

Stack* pop(Stack* stack) {
  // in: stack pointer
  // out: stack pointer with top StackNode removed
  // err: (-1 = general error)
}

int peek(Stack* stack) {
  // in: stack pointer
  // out: top value of stack
  // err: (-1 = general error)
}

// in: stack pointer
// out: (1 = empty | 0 = not empty)
// err: (-1 = general error)
int empty(Stack* stack) {

}


/* ------------------------------------- Main -------------------------------------- */
int main(int argc, char const *argv[]) {
  // clear console
  clr();



  // driver code
  return 0;
}










// A structure to represent a stack


struct StackNode* newNode(int data) {
  struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

int isEmpty(struct StackNode* root) {
  return !root;
}

void push(struct StackNode** root, int data) {
  struct StackNode* stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
  printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root) {
  if (isEmpty(*root)) return INT_MIN;
  struct StackNode* temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);

  return popped;
}

int peek(struct StackNode* root) {
  if (isEmpty(root)) return INT_MIN;
  return root->data;
}

int main() {
  struct StackNode* root = NULL;

  push(&root, 10);
  push(&root, 20);
  push(&root, 30);

  printf("%d popped from stack\n", pop(&root));

  printf("Top element is %d\n", peek(root));

  return 0;
}
