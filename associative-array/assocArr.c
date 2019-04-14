/* *********************************************************************************** #
# -----            _                           _                                -----  #
# -----        ___| |__ (_)_   _(_)_ __   __ _| |_ ___  _ __ (_)_ __   ___      -----  #
# -----       / __| '_ \| \ \ / / | '_  \/  ` | __/   \| '_ \| | '_ \ / __|     -----  #
# -----      | (__| | | | |\ V /| | | | | (_) | || (_) | | | | | | | | (__      -----  #
# -----       \___|_| |_|_| \_/ |_|_| |_|\__, |\__\___/|_| |_|_|_| |_|\___|     -----  #
# -----                                  |___/                                  -----  #
# -----                                                                         -----  #
# -----                 GitHub|Twitter|Facebook|LinkedIn -> @chivingtoninc      -----  #
# -----   License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like   -----  #
# ***********************************************************************************  #
# ---------- Associative Array (hash table/dictionary) implementation in C. ---------- #
# ------------------------- Uses the "djb2" hash function. --------------------------- #
# *********************************************************************************** */

#include <stdio.h>


// List Node
typedef struct Node {
  unsigned long key;
  const char* val;
  struct Node* next;
} Node;


// Djb2 hash function.
unsigned long hash(unsigned char* str) {
  unsigned long hash = 5381;
  int c;

  while (c = *str++) hash = ((hash << 5) + hash) + c;

  return hash;
}


// Main program
int main(int argc, const char* argv[]) {
  // Check for string args
  if (argc < 2) { printf("\nPass at lease one string to store.\n\n"); return 1; }

  // Print args
  printf("\nStrings to hash:\n");
  for (int i = 1; i < argc; i++) printf(" - %s\n", argv[i]);

  // Create the associative array
  Node hashed[argc-1];

  // Hash all strings and store
  for (int i = 1; i < argc; i++) {
    Node listNode;
    listNode.key = hash((unsigned char*)argv[i]);
    listNode.val = argv[i];
    listNode.next = NULL;

    // Add code to insert at end of node list. Currently overwrites nodes.

    hashed[i-1] = listNode;
  }

  // Print stored values
  printf("\nStored Keys/Vals:\n");
  for (int i = 1; i < argc; i++) {
    // Add code to print entire node list at each index.
    printf(" - key(%lu): %s\n", hashed[i-1].key, hashed[i-1].val);
  }
  printf("\n");

  return 0;
}
