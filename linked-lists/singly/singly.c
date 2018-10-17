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
# ----------------- Singly-linked grocery list implementation in C. ----------------- #
# ********************************************************************************** */

/* ------------------------------------ Imports ------------------------------------ */
// import libs
#include <stdio.h>


/* ----------------------------------- Structures ---------------------------------- */
// List Node
typedef struct Node {
    double price;
    struct Node* next;
} Node;


/* ----------------------------------- Functions ----------------------------------- */
// Print out list
void display(Node* head) {
  Node* current = head;

  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

// Prepend item to beginning of list
void prepend(Node** head, int price) {
  Node* newNode;                        // Get the head node
  newNode = malloc(sizeof(Node));       // Allocate new node

  newNode->price = price;               // Set new node's price
  newNode->next = *head;                // Set new node's next pointer to previous head
  *head = newNode;                      // Set head pointer to new node
}

// Append item to end of list
void append(Node* head, double price) {
  Node* current = head;                 // Get the head node

  while (current->next != NULL)         // Go to end of list
    current = current->next;            // Set current node to last node

  current->next = malloc(sizeof(Node)); // Allocate new node & point last node's next to it
  current->next->price = price;         // Set new node's price
  current->next->next = NULL;           // Set new node's next NULL to indicate last node
}

// Remove an item from the beginning of the list.
double removeFirst(Node** head) {\
  if (*head == NULL) return -1;         // Return if list is empty

  double headPrice = (*head)->price;    // Get head node's price
  Node* nextNode = (*head)->next;       // Set next node to head node's next
  free(*head);                          // Delete head node
  *head = nextNode;                     // Set head pointer to next node

  return headPrice;                     // Return old head node's price
}

// Remove an item from the end of the list.
double removeLast(Node* head) {
  if (*head == NULL) return -1;         // Return if list is empty

  Node* previous = NULL;                // Placeholder for next to last node
  Node* current = head;                 // Get head node

  while (current->next != NULL) {       // Go to end of list
    previous = current;                 // Update previous to current
    current = current->next;            // Update current to next
  }

  double lastPrice = current->price;    // Get lst node's price
  free(current);                        // Delete last node
  previous->next = NULL;                // Set 2nd to last node's next NULL to indicate last node

  return lastPrice;                     // Return last node's price
}


/* ---------------------------------- Main Program --------------------------------- */
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
