#include "project2.h"

Node* addNode(Node* root, Node* current) {

  if(root == NULL) {
    root = (Node*)malloc(sizeof(Node));
    root->sku = current->sku;
    root->name = (String)malloc(sizeof(strlen(current->name)));
    strcpy(root->name, current->name);
    root->price = current->price;
    root->quantaty = 1;
    root->next = NULL;
  } else {
    Node *temp;
    while(root->next != NULL) {
      temp = root->next;
    }
  }
  return root;
}

Node* createNode(String input, int length) {
  char tempData[MAX_CHARS];
  char* token;
  strcpy(tempData, input);

  token = strtok(tempData, " ");

  Node* tempNode;

  return tempNode;
}

void printNode(Node* node) {
  if(node->sku != 0) {
    printf("%d ", node->sku );
  }
  if(node->name != NULL) {
    printf("%s ", node->name);
  }
  if(node->price != 0.0) {
    printf("$%f.2 ", node->price);
  }
  printf(": %d in stock\n", node->quantaty);
}

void printList(Node* head) {
  Node* current = head;
  while(current != NULL) {
    printNode(current);
    current = current->next;
  }
}
