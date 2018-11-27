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

/*
 *
 */
Node* createNode(String input) {
  //TODO: Fix

  Node* tempNode = (Node*)malloc(sizeof(Node));
  tempNode->sku = NULL;
  tempNode->name = NULL;
  tempNode->price = NULL;
  tempNode->quantity = 1;
  tempNode->next = NULL;

  int skuEndIndex = isNumericString(input, 0);
  int priceIndex = isPriceString(input, strlen(input)-1);
  if(skuEndIndex != 0) {
    tempNode->sku = (String)malloc(skuEndIndex+1);
    subString(tempNode->sku, input, 0, skuEndIndex);
  }

  if(priceIndex != 0) {
    tempNode->price = (String)malloc(priceIndex);
    int strSize = strlen(input);
    int start = strSize-priceIndex;
    subString(tempNode->price, input, start, strSize-1);
  }

  if(hasString(input) == 1) {
    //printf("%s\n", "This has String");
    int start = getStartOfString(input);
    int end = getEndString(input);
    tempNode->name = (String)malloc(end-start);
  }

  //char c;
  //int end = strlen(input) - 1;
  //int i = end;
  //while((c=*(input+i) != ' ') || c == '\n' || c == '\0') {
    //i--;
  //}
  //if(*(input+i) == ' ') {
    //i++;
  //}

  //int start = i;

  //int priceIndex = isPriceString(input, start);

  //if(priceIndex != 0) {
    //tempNode->price = (String)malloc(sizeof(char) * (priceIndex+1));
    //int chars = subString(tempNode->price, input, start, start + priceIndex);
  //}
  return tempNode;
}

int hasString(String line) {
  char c;
  int i = 0;
  while((c = *(line+i)) != '\n' && c != '\0' && c != EOF) {
    if(isAlpha(c) == 1) {
      return 1;
    }
    i++;
  }
  return 0;
}

int subString(String to, String from, int start, int end) {
  String str;
  int j = 0, i = 0;

  for(i = start; i < end; i++,j++) {
    to[j] = from[i];
    //j++;
  }
  to[j] = '\0';
  return i - start + 1;
}

void printNode(Node* node) {
  if(node->sku != NULL) {
    printf("%s", node->sku );
  }
  if(node->name != NULL) {
    printf(" %s", node->name);
  }
  if(node->price != NULL) {
    printf(" $%s", node->price);
  }
  printf(": %d in stock\n", node->quantity);
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

int isNumeric(char c) {
  if(c >= 48 && c <= 57) {
    return 1;
  }
  return 0;
}

int isAlpha(char c) {
  if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return 1;
  }
  return 0;
}

int isPriceString(String cp, int endIndex) {
  char c;
  int hasMarker = 0;
  int i = endIndex-1;
  while((c = *(cp + i)) != EOF && c != '\n' && c != ' ' && i > 0) {
    if(isNumeric(c) != 0 || c == 46) {
      if(c == 46) {
        hasMarker = 1;
      }
      i--;
    } else {
      return 0;
    }
  }
  if(hasMarker != 1) {
    return 0;
  }
  return endIndex - i;
}
/*
int isPriceString(String cp, int startIndex) {
  char c;
  int i = startIndex;
  int foundPoint = 0;
  while((c = *(cp + i)) != EOF && c != '\n' && c != ' ') {
    if (isNumeric(c) == 0) {
      if(foundPoint == 0 && c == '.') {
        foundPoint = 1;
      } else {
        return 0;
      }
    }
    i++;
  }
  return i - startIndex;
}
*/
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
