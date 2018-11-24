#include <stdio.h>


typedef struct product {
  int sku;
  char *name;

  struct product *next;
} Node;

void addNode(Node *to, Node *from);
