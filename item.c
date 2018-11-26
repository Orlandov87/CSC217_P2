#include "project2.h"

Node* addNode(Node* head, Node* newNode) {
  //TODO: Needs to fix for NULL data
  int c;
  if(head == NULL) {
    head = newNode;
  } else {
    Node *current = head;
    Node *prev = NULL;
    while((c = compareTo(current, newNode)) < 0 && current->next != NULL) {
      prev = current;
      current = current->next;
    }
    if(c == 0) {
      current->quantity++;
      nodeUpdate(current, newNode);
    } else if (current->next == NULL) {
      current->next = newNode;
    } else {
      newNode->next = current;
      prev->next = newNode;
    }
  }
  return head;
}

void nodeUpdate(Node* node1, Node* node2) {
  if(node1->sku == NULL && node2->sku != NULL) {
    node1->sku = (String)malloc(sizeof(node2->sku));
    strcpy(node1->sku, node2->sku);
  }
  if(node1->name == NULL && node2->name != NULL) {
    node1->name = (String)malloc(sizeof(node2->name));
    strcpy(node1->name,node2->name);
  }
  if(node1->price == NULL && node2->price != NULL) {
    node1->price = (String)malloc(sizeof(node2->price));
    strcpy(node1->price, node2->price);
  }
}

int compareTo(Node* node1, Node* node2) {
  if(node1->sku != NULL && node2->sku != NULL) {
    return strcmp(node1->sku, node2->sku);
  } else if(node1->sku == NULL && node2->sku == NULL){
    return strcmp(node1->name, node2->name);
  } else if(node1->sku == NULL) {
    return -1;
  }
  return 1;
}

Node* createNode(String input, int length) {
  String sku;
  String name;
  String price;
  //TODO: Fix

  Node* tempNode = (Node*)malloc(sizeof(Node));

  int skuIndex = isNumericString(input, 0);
  printf("%d\n", skuIndex);
  if(skuIndex != 0) {
    tempNode->sku = (String)malloc(skuIndex+1);
  }

  return tempNode;
}

String ovstrncpy(String to, String from, int start, int end) {
  String str;
  int i = start;
  for(; i < end; i++) {
    to[i] = from[i];
  }
  to[i] = '\0'
  return str;
}

void printNode(Node* node) {
  if(node->sku != NULL) {
    printf("%s ", node->sku );
  }
  if(node->name != NULL) {
    printf("%s ", node->name);
  }
  if(node->price != NULL) {
    printf("$%s", node->price);
  }
  printf(": %d in stock\n", node->quantity);
}

void printList(Node* head) {
  Node* current = head;
  while(current != NULL) {
    printNode(current);
    current = current->next;
  }
}

int isNumeric(char c) {
  if(c >= 48 && c <= 57) {
    return 1;
  }
  return 0;
}

/*
 * isNumericString returns the next space as
 */
int isNumericString(String cp, int startIndex) {
  char c;
  int i = startIndex;
  while((c = *(cp + i)) != EOF && c != '\n' && c != ' ') {
    if(isNumeric(c) == 0) {
      return 0;
    } else {
      i++;
    }
  }
  return i - startIndex;
}
