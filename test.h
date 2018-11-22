#include <stdio.h>


typedef struct product {
  int sku;
  char *name;

  struct product *next;
} Node;

void createNode(char* name, int sku);
void addNode(Node *to, Node *from);
