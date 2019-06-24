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
  printf("\n Type \"c\" to continue: ");
  char cont[4];
  scanf("%s", cont);
};

// quit program
void quit(char* msg, int cl) {
  if (cl) clr();
  char* title = "Stack Data Structure in C";
  if (strlen(msg) > 0) printf("\n %s\n %s\n Invalid option: %s\n\n Quitting...\n\n", title, underline(title), msg);
  exit(0);
};

// display a help menu (and optionally an error message)
void help(char* msg) {
  if (strlen(msg) > 0 && strcmp(msg, "exit"))
    printf("\n Error:\n %s\n%s\n", underline("Error:"), wrap(msg, 70, 1));

  printf("\n Options:\n %s\n\
    - full: \tcheck if stack is full.\n\
    - empty: \tcheck if stack is empty.\n\
    - push: \tpush item onto stack.\n\
    - pop: \tshow return top item from stack.\n\
    - help: \tshow this menu.\n\
    - exit: \texit the program.\n\n",
    underline("Options:")
  );
  if (!strcmp(msg, "exit")) quit("", 0);
  else pause("");
};

// greet user
void greet() {
  char* title = "Stack Data Structure in C";
  printf("\n %s\n %s\n Enter \"exit\" anytime to quit...\n\n", title, underline(title));
  printf(" Would you like to see instructions? (y/n): ");
  char chooseHelp[4];
  scanf("%s", chooseHelp);
  if (!strcmp(chooseHelp, "y") || !strcmp(chooseHelp, "yes")) help("");
  if (!strcmp(chooseHelp, "exit")) quit("", 0);
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
int full(Stack* stack) {
  return stack->top == stack->capacity - 1;
};

// check if stack is empty
int empty(Stack* stack) {
  return stack->top == -1;
};

// push new node onto stack
void push(Stack* stack, int item) {
  if (full(stack)) return;
  stack->array[++stack->top] = item;
};

// remove top node of stack
int pop(Stack* stack) {
  if (empty(stack)) return INT_MIN;
  return stack->array[stack->top--];
};

// see current top node of stack
int peek(Stack* stack) {
  if (empty(stack)) return INT_MIN;
  return stack->array[stack->top];
};


/* ------------------------------------- Main -------------------------------------- *
 *        REPL main/driver program for testing the data structure & methods.         *
 * --------------------------------------------------------------------------------- */
int main(int argc, char const *argv[]) {
  // check args
  if (argc > 1) {
    clr();
    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) help("exit");
    else quit((char*)("Invalid option: %s", argv[1]), 1);
  };

  // create the stack
  Stack* myStack = create(10);

  // begin runtime loop
  int done = 0;
  while (!done) {
    // clear screen & greet user
    clr();
    greet();

    // accept input
    printf("\n What would you like to do?\n >> ");
    char choice[8];
    scanf("%s", choice);

    // perform action
    if (!strcmp(choice, "exit")) quit("", 0);
    else if (!strcmp(choice, "full")) printf("\n Status: %s", full(myStack) ? "full" : "not full");
    else if (!strcmp(choice, "empty")) printf("\n Status: %s", empty(myStack) ? "empty" : "not empty");
    else if (!strcmp(choice, "push")) {
      printf("\n What number would you like push onto the stack?\n >> ");
      int choice;
      scanf("%i", &choice);
      push(myStack, choice);
    }
    else if (!strcmp(choice, "pop")) pop(myStack);
    else printf("\n Invalid option: %s\n", choice);

    // print result
    printf("\n Top of stack: %d\n", peek(myStack));

    pause("");
  };

  // exit
  printf("\n");
  return 0;
};
