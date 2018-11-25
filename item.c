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
