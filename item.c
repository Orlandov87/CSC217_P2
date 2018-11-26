#include "project2.h"


/*
 *
 */
Node* addNode(Node* root, Node* current) {
  //TODO: Needs to fix for NULL data
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

/*
 *
 */
Node* createNode(String input, int length) {
  //TODO: createNode: Not functional
  char tempData[MAX_CHARS];

  strcpy(tempData, input);
  Node* tempNode = (Node*)malloc(sizeof(Node));
  tempNode->sku = 5;
  tempNode->name = "Orlando";
  tempNode->price = 10.0;
  return tempNode;
}

/*
 *
 */
void printNode(Node* node) {
  //TODO: Align text if information is missing on the node.
  if(node->sku != 0) {
    printf("%d ", node->sku );
  }
  if(node->name != NULL) {
    printf("%s ", node->name);
  }
  if(node->price != 0.0) {
    printf("$%0.2f ", node->price);
  }
  printf(": %d in stock\n", node->quantaty);
}

/*
 *
 */
void printList(Node* head) {
  Node* current = head;
  while(current != NULL) {
    printNode(current);
    current = current->next;
  }
}
