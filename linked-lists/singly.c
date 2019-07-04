/* --------------------------------------------------------------------------------- *
 * Author: Johnathan Chivington (gh|twt|fb|li -> @chivingtoninc)                     *
 * Project: Singly-Linked List (C)                                                   *
 * File: singly.c                                                                    *
 * Description: Data structure(s), methods & a driver for testing / demonstration.   *
 * License: DO_WHATEVER_YOU_WANT - use / modify / redistribute as you like.          *
 * --------------------------------------------------------------------------------- */

/* ------------------------------------- Init -------------------------------------- *
 *                  Initializatoin script for loading libs & utils.                  *
 * --------------------------------------------------------------------------------- */
#include "../init.h"

/* ---------------------------------- Structures ----------------------------------- *
 *            The data structure and it's dependent structures (if any).             *
 * --------------------------------------------------------------------------------- */
// singly-linked list
typedef struct Node {
  int data;
  struct Node* next;
} Node;

/* ------------------------------------ Methods ------------------------------------ *
 *                 Functions used to manipulate the data structure.                  *
 * --------------------------------------------------------------------------------- */
// start list -> return head node
Node* createList(int num) {
  Node* head = (Node*)malloc(sizeof(Node));
  head->data = num;
  head->next = NULL;
  return head;
};

// add node to end of list -> return head node
Node* push(Node* head, int num) {
  Node* current = head;
  while (current->next != NULL) current = current->next;

  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = num;
  new_node->next = NULL;

  current->next = new_node;
  return head;
};

// remove node from end of list -> return removed node
Node* pop(Node* list) {
  while (list->next->next != NULL) list = list->next;
  Node* last = list->next;
  list->next = NULL;
  free(last);
  return last;
};

// print list -> no return value
void print(Node* list) {
  printf("\n List Contents\n %s\n", underline("List Contents"));
  int i = 0;
  while (list->data) {
    printf(" Item %d: %d\n", i++, list->data);
    if (list->next == NULL) break;
    else list = list->next;
  }
};


/* ------------------------------------- Main -------------------------------------- *
 *          Main/driver program for testing the data structure & methods.            *
 * --------------------------------------------------------------------------------- */
int main(int argc, char const *argv[]) {
  // check args
  if (argc > 1) checkArgs(argv[1]);

  // greet user & prompt instructions
  greet();
  instructions();

  // list pointer / placeholder
  Node* list;

  // repl
  while (1) {
    // refresh screen & greet user
    greet();

    // prompt for action
    printf(" What would you like to do?\n >> ");
    char choice[128];
    scanf("%s", choice);

    // perform action
    if (!strcmp(choice, "create")) list = createList(getNum());
    else if (!strcmp(choice, "push")) push(list, getNum());
    else if (!strcmp(choice, "pop")) pop(list);
    else if (!strcmp(choice, "print")) list ? print(list): printf("\n No list created.\n");
    else if (!strcmp(choice, "help")) help("");
    else if (!strcmp(choice, "exit")) quit("", 0);
    else printf("\n Invalid option: %s\n", choice);

    // print result & pause
    pause("");
  };

  // exit
  printf("\n");
  return 0;
};
