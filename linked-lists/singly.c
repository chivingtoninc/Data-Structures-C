/* ********************************************************************************** #
# -----            _                           _                                ----- #
# -----        ___| |__ (_)_   _(_)_ __   __ _| |_ ___  _ __ (_)_ __   ___      ----- #
# -----       / __| '_ \| \ \ / / | '_  \/  ` | __/   \| '_ \| | '_ \ / __|     ----- #
# -----      | (__| | | | |\ V /| | | | | (_) | || (_) | | | | | | | | (__      ----- #
# -----       \___|_| |_|_| \_/ |_|_| |_|\__, |\__\___/|_| |_|_|_| |_|\___|     ----- #
# -----                                  |___/                                  ----- #
# -----                                                                         ----- #
# -----                 GitHub|Twitter|Facebook|LinkedIn -> @chivingtoninc      ----- #
# -----   License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like   ----- #
# *********************************************************************************** #
# --------------------- Singly-linked list implementation in C. --------------------- #
# ********************************************************************************** */

/* ------------------------------------ Imports ------------------------------------ */
// --- import libs
#include <stdio.h>

// --- import modules
// modules here


/* ------------------------------------ Imports ------------------------------------ */
/* ------------------------------------ Imports ------------------------------------ */
// List Node
typedef struct Node {
    int val;
    struct Node* next;
} Node;


// Print out list
void printList(Node* head) {
  Node* current = head;

  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

// Append item to end of list
void append(Node* head, int val) {
    Node* current = head;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;
}

// Push onto beginning of list
void push(Node** head, int val) {
    Node* new_node;
    new_node = malloc(sizeof(Node));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}


// Main program
int main(int argc, const char* argv[]) {

  Node* head = NULL;
  head = malloc(sizeof(Node));
  if (head == NULL) {
      return 1;
  }

  head->val = 1;
  head->next = NULL;



  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->val = 1;
  head->next = malloc(sizeof(Node));
  head->next->val = 2;
  head->next->next = NULL;


  return 0;
}
