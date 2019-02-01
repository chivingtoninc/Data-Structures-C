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
// Determine platform
#ifdef _WIN32
  char* SYS = "WIN";
#else
  char* SYS = "UNIX";
#endif

// Max length for List / Node names
#define NAME_MX 64
#define PATH_MX 256


/* ------------------------------------ Utils -------------------------------------- */
// Clear screen
void clr(void) {
  system(SYS == "WIN" ? "cls" : "clear");
}

// Pause program
void pause(char* msg) {
  fprintf(stdout, (strlen(msg) > 0) ? "\n %s\n", msg : "\n Press enter to continue...\n");
  while (getchar() != "\n");
}

// Display help menu
void help(char* msg) {
  int suppress = (strcmp(msg, "exit") || strcmp(msg, "continue")) ? 1 : 0;
  if (strlen(msg) > 0 && !suppress) fprintf(stdout, "\n %s\n", msg);

  fprintf(stdout, "\n  Options:\n ----------\n\
  - add: \tadd item to list at a specified position, by number.\n\
  - remove: \tremove item from list at a specified position, by number.\n\
  - show: \tshow list.\n\
  - help: \tshow this menu.\n\
  - exit: \texit the program.\n\
  ");

  if (strcmp(msg, "continue")) exit(0);
}


/* -------------------------------- Node Structure --------------------------------- */
// List Node
typedef struct Node {
  char name[NAME_MX];
  float price;
  struct Node* next;
} Node;

// Create new Node
Node* createNode(char* name, float price, Node* next) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->price = price;
  newNode->next = next;
  return newNode;
}

// Destroy Node
void destroyNode(Node* node) {
  if (node) free(node);
}


/* -------------------------------- List Structure --------------------------------- */
// List
typedef struct List {
  Node* head;
} List;

// Create new List
List* createList(void) {
  List* newList = malloc(sizeof(List));
  newList->head->next = NULL;
  return newList;
}

// Destroy List
void destroyList(List* list) {
  if (list) free(list);
}

// Add item to list at specified position.
void add(Node* head, char* name, float price, int pos) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->price = price;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node* current = head;

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

// Delete item from list at specified position.
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
int show(Node* head) {
  if (head->next == NULL) return 0;

  Node* current = head;
  int i = 1;

  fprintf(stdout, "\n      Editing List\n ----------------------\n");
  while (current->next != NULL) {
    current = current->next;
    fprintf(stdout, "  %d. %s: \t$%.2f\n", i++, current->name, current->price);
  }

  return 1;
}

// Save list
void save(Node* head, char* loc, char* listName) {
  FILE* fp = fopen(loc, "w");

  if (fp == NULL) {
    fprintf(stdout, "\n Can't save to that location.\n");
    return;
  }

  char underline[NAME_MX]; int i;
  for (i = 0; i < strlen(listName); i++) underline[i] = '-';

  fprintf(fp, "%s\n%s\n", listName, underline);

  Node* current = head;
  int pos = 1;

  while (current->next != NULL) {
    current = current->next;
    fprintf(fp, "%d. %s: \t$%.2f\n", pos++, current->name, current->price);
  }

  fclose(fp);
  fprintf(stdout, "\n List saved at: %s\n", loc);
}


/* ---------------------------------- Main Program --------------------------------- */
int main(int argc, char* argv[]) {
  // Check args
  if (argc > 1) {
    if (!strcmp(argv[1], "--help")) help("exit");
    else help("Invalid argument(s).");
  }

  // Clear screen & greet user
  clr();
  fprintf(stdout, "\n Welcome to the Singly-Linked Grocery List!\n");
  fprintf(stdout, "\n Would you like to see instructions?\n (y/n): ");

  char chooseHelp[4];
  scanf("%s", &chooseHelp);
  if (!strcmp(chooseHelp, "y")) help("continue");

  // Create List
  List* list = createList();

  // Enter event loop
  while (1) {
    fprintf(stdout, "\n\n What would you like to do?\n ");

    // Check for commands
    char cmd[32];
    scanf("%s", &cmd);

    if (!strcmp(cmd, "add")) {
      char name[NAME_MX]; float price; int position;

      fprintf(stdout, "\n Item name: "); scanf(" %[^\n]s", name);
      fprintf(stdout, " Item price: "); scanf("%f", &price);

      if (show(list->head)) {
        fprintf(stdout, "\n Where would you like to insert this item?\n ");
        scanf("%d", &position);
      }
      else position = 1;

      fprintf(stdout, "\n Adding \"%s = $%.2f\" to the list at position %d...\n", name, price, position);
      add(list->head, name, price, position);
      continue;
    }

    if (!strcmp(cmd, "delete")) {
      if (show(list->head)) {
        int position;

        fprintf(stdout, "\n Which item would you like to delete?\n ");
        scanf("%d", &position);

        delete(list->head, position);
        continue;
      }

      fprintf(stdout, "\n List is currently empty...");
      continue;
    }

    if (!strcmp(cmd, "show")) {
      if (!show(list->head)) fprintf(stdout, "\n List is currently empty...");
      continue;
    }

    if (!strcmp(cmd, "save")) {
      if (show(list->head)) {
        char loc[PATH_MX]; char listName[NAME_MX];

        fprintf(stdout, "\n Enter a name for this list.\n ");
        scanf(" %[^\n]s", &listName);

        fprintf(stdout, "\n Enter a file path/name.\n ");
        scanf("%s", &loc);

        save(list->head, loc, listName);
      }
      continue;
    }

    if (!strcmp(cmd, "help")) {
      help("continue");
      continue;
    }

    if (!strcmp(cmd, "exit")) break;

    fprintf(stdout, "\n Invalid command.\n");
  }

  return 0;
}
