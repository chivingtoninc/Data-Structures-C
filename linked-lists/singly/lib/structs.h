// List Node
typedef struct Node {
  char name[256];
  float price;
  struct Node* next;
} Node;

// List
typedef struct List {
  Node* head;
} List;
