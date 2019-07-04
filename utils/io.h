/* --------------------------------------------------------------------------------- *
 * Author: Johnathan Chivington (gh|twt|fb|li -> @chivingtoninc)                     *
 * Project: C Test REPL                                                              *
 * File: io.h                                                                        *
 * Description: I/O utils for greeting, prompting, formatting text, etc...           *
 * License: DO_WHATEVER_YOU_WANT - use/modify/redistribute as you like.              *
 * --------------------------------------------------------------------------------- */

// define platform for clr()
#ifdef _WIN32
  #define SYS "WIN"
#else
  #define SYS "UNIX"
#endif

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
  if (cl == 1) clr();
  if (strlen(msg) > 0) printf("\n Invalid option: %s\n\n Quitting...\n\n", msg);
  exit(0);
};

// display a help menu (and optionally an error message)
void help(char* msg) {
  if (strlen(msg) > 0 && strcmp(msg, "exit") && strcmp(msg, "pause"))
    printf("\n Error:\n %s\n%s\n", underline("Error:"), wrap(msg, 70, 1));

  printf("\n Options:\n %s\n\
    - create: \tcreate list and add first node.\n\
    - push: \tadd node to end of list.\n\
    - pop: \tremove node from end of list.\n\
    - print: \tprint list contents.\n\
    - help: \tshow this menu.\n\
    - exit: \texit the program.\n\n",
    underline("Options:")
  );
  if (!strcmp(msg, "exit")) quit("", 0);
  if (!strcmp(msg, "pause")) pause("");
};

// greet user
void greet(char* title) {
  clr();
  printf("\n %s\n %s\n Enter \"exit\" anytime to quit...\n\n", title, underline(title));
};

// get integer from user
int getNum() {
  int num;
  printf("\n What number whould you like to add?\n >> ");
  scanf("%d", &num);
  printf("\n Adding number (%d) to list...\n", num);
  return num;
};

// check arguments
void checkArgs(const char* arg) {
  clr();
  if (!strcmp(arg, "--help") || !strcmp(arg, "-h")) help("exit");
  else quit((char*)("Invalid option: %s", arg), 1);
};

// prompt for instructions
void instructions() {
  printf(" Would you like to see instructions? (y/n): ");
  char chooseHelp[4];
  scanf("%s", chooseHelp);
  if (!strcmp(chooseHelp, "y") || !strcmp(chooseHelp, "yes")) help("pause");
  if (!strcmp(chooseHelp, "exit")) quit("", 1);
};
