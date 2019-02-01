/* --------------------------------------------------------------------------------- *
 * Name: Johnathan Chivington (github|twitter|facebook|linkedin -> @chivingtoninc)   *
 * Project: Stack implementation in C.                                               *
 * Description: Classify handwritten digits 0-9 from MNIST database.                 *
 * License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like.              *
 * --------------------------------------------------------------------------------- */


/* ------------------------------------ Includes ----------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ----------------------------------- Structures ---------------------------------- */
typedef struct StackNode {
  int value;                  // the value that the node holds
  StackNode* next;            // pointer to the next node in the stack
} StackNode;

typedef struct Stack {
  size_t size;                // size of the stack
  StackNode* top;             // pointer to top node in stack
} Stack;


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

int empty(Stack* stack) {
  // in: stack pointer
  // out: (1 = empty | 0 = not empty)
  // err: (-1 = general error)
}


/* ------------------------------------- Main -------------------------------------- */
int main(int argc, char const *argv[]) {
  // driver code
  return 0;
}
