// imports
#include <stdlib.h>


// Clear screen
void clr(char* platform) {
  system(platform == "WIN" ? "cls" : "clear");
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
  - add: \tadd item to list at a specified position, by number.\n\
  - remove: \tremove item from list at a specified position, by number.\n\
  - show: \tshow list.\n\
  - help: \tshow this menu.\n\
  - exit: \texit the program.\n\
  ");

  if (strcmp(msg, "continue")) exit(0);
}
