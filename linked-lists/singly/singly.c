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
#include <stdlib.h>
#include <string.h>


/* -------------------------------- Helper Functions ------------------------------- */
void help(void) {
  fprintf(stdout, "\n Options:\n");
  fprintf(stdout, "\n  - append: append item to end of list.");
  fprintf(stdout, "\n  - prepend: prepend item to beginning of list.");
  fprintf(stdout, "\n  - insert: insert item at specific location.");
  fprintf(stdout, "\n  - remove: remove item from specific location.");
  fprintf(stdout, "\n  - removeFirst: remove first item from list.");
  fprintf(stdout, "\n  - removeLast: remove last item from list.");
  exit(0);
}


/* ----------------------------------- Structures ---------------------------------- */
// Define Node structure for list items
typedef struct Node {
  struct Node* next;                    // Each node has a pointer to next node in list
  double price;                         // Each node stores price of grocery item
  char name[8];                         // Each node stores name of grocery item
} Node;


/* -------------------------------- List Functions --------------------------------- */
// Print out list
void display(Node* head) {
  Node* current = head;                 // Get the head node

  printf("\n Grocery List\n ------------\n");
  while (current != NULL) {             // Move through the list
    char* n = current->name;            // Get item name
    double p = current->price;          // Get item price
    printf("  - %s: %.2f\n", n, p);     // Print each price
    current = current->next;            // Update current node of list
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

// Insert item at specific location
void insert(Node* head, double price) {
  Node* current = head;                 // Get the head node

  while (current->next != NULL)         // Go to end of list
    current = current->next;            // Set current node to last node

  current->next = malloc(sizeof(Node)); // Allocate new node & point last node's next to it
  current->next->price = price;         // Set new node's price
  current->next->next = NULL;           // Set new node's next NULL to indicate last node
}

// Remove item from the beginning of the list.
double removeFirst(Node** head) {\
  if (*head == NULL) return -1;         // Return if list is empty

  double headPrice = (*head)->price;    // Get head node's price
  Node* nextNode = (*head)->next;       // Set next node to head node's next
  free(*head);                          // Delete head node
  *head = nextNode;                     // Set head pointer to next node

  return headPrice;                     // Return old head node's price
}

// Remove item from the end of the list.
double removeLast(Node* head) {
  if (head == NULL) return -1;         // Return if list is empty

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

// Remove item from specific location
double remove(Node* head) {
  if (head == NULL) return -1;         // Return if list is empty

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
  // Check help
  help();
  
  // // Check for "--help" flag & greet user
  // if (argv[2] == "--help") help();
  // fprintf(stdout, "\n Welcome to the Singly-Linked Grocery List app.\n");
  // fprintf(stdout, "\n Type \"help\" or run with option \"--help\" for options.\n");
  //
  // // Set initial head node
  // Node* head = malloc(sizeof(Node));
  //
  // // Prompt user
  // fprintf(stdout, "\n\n Enter items you'd like to add to the list.\n Type \"display\" to show list. Type \"exit\" when done. \n");
  //
  // // Placeholders for item names & prices
  // double price = 0.0;
  // char name[8];
  //
  // // Get list items from user
  // fprintf(stdout, "\n Item name: "); scanf("%s", name);
  // fprintf(stdout, "\n Item price: %d\n"); scanf("%d", &price);
  //
  // // Display list for testing
  // display(head);

  return 0;
}
