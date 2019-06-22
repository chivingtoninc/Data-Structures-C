/* --------------------------------------------------------------------------------- *
 * Name: Johnathan Chivington (github|twitter|facebook|linkedin -> @chivingtoninc)   *
 * Project: Data Structures (C) --> Stack                                            *
 * Description: Stack implementation in C.                                           *
 * License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like.              *
 * --------------------------------------------------------------------------------- */

/* ----------------------------------- Includes ------------------------------------ *
 *                         C-language built in libs/modules.                         *
 * --------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
// #include "time.h"
// fprintf(stdout, "%lun", (unsigned long)time(NULL));


/* ------------------------------------ Globals ------------------------------------ *
 *                      Global program variables, defines, etc.                      *
 * --------------------------------------------------------------------------------- */
// define platform
#ifdef _WIN32
  #define SYS "WIN"
#else
  #define SYS "UNIX"
#endif


/* ------------------------------------- Utils ------------------------------------- *
 *  Utility functions that are not essential to the data structure being presented.  *
 * --------------------------------------------------------------------------------- */
// append char to end of string
char* append(char *s, char c) {
  int len = strlen(s);
  char buf[len+2];
  strcpy(buf, s);
  buf[len] = c;
  buf[len + 1] = 0;
  return strdup(buf);
};

// line-wrap long messages
char* wrap(char* msg, int cutoff, int space) {
  char* wrapped = "";

  for (int i = 0; i < space; i++) wrapped = append(wrapped, ' ');

  int count = 0;
  for (int i = 0; i < strlen(msg); i++) {
    if (count >= cutoff && isspace(msg[i])) {
      wrapped = append(wrapped, '\n');
      for (int i = 0; i < space; i++) wrapped = append(wrapped, ' ');
      count = 0;
    }
    else wrapped = append(wrapped, msg[i]);
    count++;
  }

  return wrapped;
};

// return underline same length as input string
char* underline(char* str) {
  char* line = "";
  for (int i = 0; i < strlen(str); i++) line = append(line, '-');
  return line;
};

// clear screen
void clr() {
  system(SYS == "WIN" ? "cls" : "clear");
};

// pause program
void pause(char* msg) {
  fprintf(stdout, (strlen(msg) > 0) ? "\n %s\n", msg : "\n %s", "Press enter to continue...");
  while (getchar() != '\n');
};

// greet user
void greet() {
  char* msg = "Stack Data Structure in C";
  printf("\n %s\n %s\n", msg, underline(msg));
};

// display a help menu (and optionally an error message)
void help(char* msg) {
  int suppress = (!strcmp(msg, "exit") || !strcmp(msg, "continue")) ? 1 : 0;
  if (strlen(msg) > 0 && !suppress) printf("\n Error:\n %s\n%s\n", underline("Error:"), msg);

  printf("\n Options:\n %s\n\
  - add: \tadd item to list at a specified position, by number.\n\
  - remove: \tremove item from list at a specified position, by number.\n\
  - show: \tshow list.\n\
  - help: \tshow this menu.\n\
  - exit: \texit the program.\n\
  ", underline("Options:"));

  if (!strcmp(msg, "exit")) exit(0);
};


/* ----------------------------------- Structures ---------------------------------- *
 *            The data structure and it's dependent structures (if any).             *
 * --------------------------------------------------------------------------------- */
 // stack structure
typedef struct Stack {
  int top;
  unsigned capacity;
  int* array;
} Stack;


/* ------------------------------------ Methods ------------------------------------ *
 *                 Functions used to manipulate the data structure.                  *
 * --------------------------------------------------------------------------------- */
// create stack with given capacity
Stack* create(unsigned capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(capacity * sizeof(int));
  return stack;
};

// check if stack is full
int isFull(Stack* stack) {
  return stack->top == stack->capacity - 1;
};

// check if stack is empty
int isEmpty(Stack* stack) {
  return stack->top == -1;
};

// push new node onto stack
void push(Stack* stack, int item) {
  if (isFull(stack)) return;
  stack->array[++stack->top] = item;
};

// remove top node of stack
int pop(Stack* stack) {
  if (isEmpty(stack)) return INT_MIN;
  return stack->array[stack->top--];
};

// see current top node of stack
int peek(Stack* stack) {
  if (isEmpty(stack)) return INT_MIN;
  return stack->array[stack->top];
};


/* ------------------------------------- Main -------------------------------------- *
 *        REPL main/driver program for testing the data structure's methods.         *
 * --------------------------------------------------------------------------------- */
int main(int argc, char const *argv[]) {
  // check args
  if (argc > 1) {
    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) help("exit");
  };

  // clear screen & greet user
  clr();
  greet();
  pause("");

  // begin event loop

  // exit
  printf("\n");
  return 0;
};
