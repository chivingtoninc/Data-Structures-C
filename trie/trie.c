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
# --------------- Trie phonebook w/ autocomplete implementation in C. --------------- #
# ********************************************************************************** */

/* ------------------------------------ Imports ------------------------------------ */
// import libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* ------------------------------------- Global ------------------------------------ */
// Determine platform
#ifdef _WIN32
  char* SYS = "WIN";
#else
  char* SYS = "UNIX";
#endif

// Lengths
#define ALPHA_LEN 26
#define PHONE_LEN 14
#define PATH_LEN 256


/* ------------------------------------ Utils -------------------------------------- */
// Clear screen
void clr(void) {
  system(SYS == "WIN" ? "cls" : "clear");
}

// Pause program
void pause(char* msg) {
  fprintf(stdout, (strlen(msg) > 0) ? "\n %s\n", msg : "\n Press enter to continue...\n");
  while (getchar() != '\n');
}

// Display help menu
void help(char* msg) {
  int suppress = (strcmp(msg, "exit") || strcmp(msg, "continue")) ? 1 : 0;
  if (strlen(msg) > 0 && !suppress) fprintf(stdout, "\n %s\n", msg);

  fprintf(stdout, "\n  Options:\n ----------\n\
  - add: \tadd contact to phonebook.\n\
  - remove: \tremove contact from phonebook.\n\
  - show: \tshow phonebook (in alphabetical order).\n\
  - help: \tshow this menu.\n\
  - exit: \texit the program.\n\
  ");

  if (strcmp(msg, "continue")) exit(0);
}


/* -------------------------------- Node Structure --------------------------------- */
// Trie Node
typedef struct Node {
  char letter;
  char phone[PHONE_LEN]
  bool end;
  struct Node* children[ALPHA_LEN];
} Node;

// Create new Node
Node* createNode(char letter, char* phone, bool end, Node* children[]) {
  Node* newNode = malloc(sizeof(Node));
  newNode->letter = letter;
  strcpy(newNode->phone, phone;);
  newNode->end = end;
  newNode->children = children;
  return newNode;
}

// Destroy Node
void destroyNode(Node* node) {
  if (node) free(node);
}


/* -------------------------------- Trie Structure --------------------------------- */
// Trie
typedef struct Trie {
  Node* root;
  char alphabet[ALPHA_LEN];
} Trie;

// Create new Trie
Trie* createTrie(void) {
  Trie* newTrie = malloc(sizeof(Trie));
  newTrie->root = NULL;
  return newTrie;
}

// Destroy Trie
void destroyTrie(Trie* trie) {
  if (trie) free(trie);
}

// Map letter to index
int map(char c) {
  char alpha[26];

}

// Add contact to trie
void add(Trie* trie, char* name, int* phone) {
  Node* current = trie->root;

  while (current->children) {
    current = current->children[i];
  }


}

// Delete item from trie at specified position.
void delete(Node* head, int pos) {
  Node* current = head;
  int i;

  for (i = 1; i < pos; i++) {
    if (current->next == NULL) break;
    current = current->next;
  }

  if (i < pos) {
    fprintf(stdout, "\n Not that many items in the trie.");
    return;
  }

  if (current->next->next == NULL) current->next = NULL;
  else current->next = current->next->next;
}

// Print trie
int show(Node* head) {
  if (head->next == NULL) return 0;

  Node* current = head;
  int i = 1;

  fprintf(stdout, "\n      Editing Trie\n ----------------------\n");
  while (current->next != NULL) {
    current = current->next;
    fprintf(stdout, "  %d. %s: \t$%.2f\n", i++, current->name, current->price);
  }

  return 1;
}

// Save trie
void save(Node* head, char* loc, char* trieName) {
  FILE* fp = fopen(loc, "w");

  if (fp == NULL) {
    fprintf(stdout, "\n Can't save to that location.\n");
    return;
  }

  char underline[NAME_MX]; int i;
  for (i = 0; i < strlen(trieName); i++) underline[i] = '-';

  fprintf(fp, "%s\n%s\n", trieName, underline);

  Node* current = head;
  int pos = 1;

  while (current->next != NULL) {
    current = current->next;
    fprintf(fp, "%d. %s: \t$%.2f\n", pos++, current->name, current->price);
  }

  fclose(fp);
  fprintf(stdout, "\n Trie saved at: %s\n", loc);
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
  fprintf(stdout, "\n Welcome to the Singly-Linked Grocery Trie!\n");
  fprintf(stdout, "\n Would you like to see instructions?\n (y/n): ");

  char chooseHelp[4];
  scanf("%s", &chooseHelp);
  if (!strcmp(chooseHelp, "y")) help("continue");

  // Create Trie
  Trie* trie = createTrie();

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

      if (show(trie->head)) {
        fprintf(stdout, "\n Where would you like to insert this item?\n ");
        scanf("%d", &position);
      }
      else position = 1;

      fprintf(stdout, "\n Adding \"%s = $%.2f\" to the trie at position %d...\n", name, price, position);
      add(trie->head, name, price, position);
      continue;
    }

    if (!strcmp(cmd, "delete")) {
      if (show(trie->head)) {
        int position;

        fprintf(stdout, "\n Which item would you like to delete?\n ");
        scanf("%d", &position);

        delete(trie->head, position);
        continue;
      }

      fprintf(stdout, "\n Trie is currently empty...");
      continue;
    }

    if (!strcmp(cmd, "show")) {
      if (!show(trie->head)) fprintf(stdout, "\n Trie is currently empty...");
      continue;
    }

    if (!strcmp(cmd, "save")) {
      if (show(trie->head)) {
        char loc[PATH_LEN]; char trieName[NAME_MX];

        fprintf(stdout, "\n Enter a name for this trie.\n ");
        scanf(" %[^\n]s", &trieName);

        fprintf(stdout, "\n Enter a file path/name.\n ");
        scanf("%s", &loc);

        save(trie->head, loc, trieName);
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
