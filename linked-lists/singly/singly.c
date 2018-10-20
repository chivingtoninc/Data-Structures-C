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


/* ------------------------------------- Global ------------------------------------ */
#ifdef _WIN32
  char* SYS = "WIN";
#else
  char* SYS = "UNIX";
#endif


/* ------------------------------------- Utils ------------------------------------- */
// Clear screen Win/Unix
void clr(void) {
  system(SYS == "WIN" ? "cls" : "clear");
}

// Display help menu
void help(char* msg) {
  clr();
  if (strlen(msg) > 0) fprintf(stdout, "\n %s\n", msg);

  fprintf(stdout, "\n  Options:\n ----------\n\
  - add: \tadd item to list at a specified position.\n\
  - remove: \tremove item from list at a specified position.\n\
  - display: \tdisplay list.\n\
  ");
  exit(0);
}

/* ----------------------------------- Structures ---------------------------------- */
// Define Node structure for list items
typedef struct Node {
  char* name;                           // Each node stores name of grocery item
  float price;                          // Each node stores price of grocery item
  struct Node* next;                    // Each node has a pointer to next node in list
} Node;


/* -------------------------------- List Functions --------------------------------- */
// Add an item to list at a specified position.
void add(Node* head, char* name, float price, int pos) {
  Node* current = head;
  Node* newNode = malloc(sizeof(Node));
  newNode->name = name;
  newNode->price = price;

  for (int i = 1; i < pos; i++) {
    if (current->next == NULL) break;
    current = current->next;
  }

  if (current->next == NULL) {
    newNode->next = NULL;
    current->next = newNode;
  }
  else {
    newNode->next = current->next;
    current->next = newNode;
  }
}

// Delete an item from list at a specified position.
void delete(Node* head, int pos) {
  Node* current = head;
  int i;

  for (i = 1; i < pos; i++) {
    if (current->next == NULL) break;
    current = current->next;
  }

  if (i < pos) {
    fprintf(stdout, "\n Not that many items in the list.");
    return;
  }

  if (current->next->next == NULL) current->next = NULL;
  else current->next = current->next->next;
}

// Print list
void display(Node* head) {
  Node* current = head;
  int i = 1;

  printf("\n      Grocery List\n ----------------------\n");
  while (current->next != NULL) {
    current = current->next;
    printf("  %d. %s: \t$%.2f\n", i++, current->name, current->price);
  }
}


/* ---------------------------------- Main Program --------------------------------- */
int main(int argc, char* argv[]) {
  // Check args
  if (argc > 1) {
    if (!strcmp(argv[1], "--help")) help("");
    else help("Invalid argument(s).");
  }

  // Clear screen
  clr();

  // Greet user
  fprintf(stdout, "\n\n Enter items you'd like to add to the list.\n Type \"display\" to show list. Type \"exit\" when done. \n");

  // Set initial head node
  // Node* head = malloc(sizeof(Node));
  // head->next = NULL;


  // Placeholders for item names & prices
  // double price = 0.0;
  // char name[8];

  // Get list items from user
  // fprintf(stdout, "\n Item name: "); scanf("%s", name);
  // fprintf(stdout, "\n Item price: %d\n"); scanf("%d", &price);

  // Display list for testing
  // display(head);

  return 0;
}
