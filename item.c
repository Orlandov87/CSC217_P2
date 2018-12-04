/*
 * Author: Orlando Vargas
 * Language: C
 */
#include "project2.h"

/*
 * addNode: Adds node to the list
 */
Node* addNode(Node* head, Node* newNode) {
    // TODO: Needs to fix for NULL data
    if (newNode == NULL) {
        return head;
    }
    int c;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;  //(Node*)malloc(sizeof(Node));
        // current = head;
        Node* prev = NULL;  //(Node*)malloc(sizeof(Node));
        while ((c = compareTo(current, newNode)) < 0 && current != NULL) {
            prev = current;
            current = current->next;
            // printf("##%d\n", c);
        }

        if (c == 0) {
            current->quantity = current->quantity + newNode->quantity;
            nodeUpdate(current, newNode);
            if (prev == NULL) {
                // printf("%s\n", "prev is NULL");
                head = head->next;
                current->next = NULL;
            } else {
                // printf("%s\n", "prev is notNULL");
                prev->next = current->next;
                current->next = NULL;
            }
            head = addNode(head, current);
        } else if (prev == NULL) {
            newNode->next = current;
            head = newNode;
        } else if (current == NULL) {
            prev->next = newNode;
        } else {
            newNode->next = current;
            prev->next = newNode;
        }
    }
    return head;
}

/*
 * destroyNode: This function takes in as parameter a Node and frees up the
 * memory that is being used. If the Node points to another node it will call
 * destroyNode on that node.
 */

void destroyNode(Node* node) {
    if (node != NULL) {
        if (node->sku != NULL) {
            free(node->sku);
        }
        if (node->name != NULL) {
            free(node->name);
        }
        if (node->price != NULL) {
            free(node->price);
        }
        if (node->next != NULL) {
            destroyNode(node->next);
        }
        free(node);
        node = NULL;
    }
}

/*
 * nodeUpdate: Takes in two nodes and updates the first node with the
 * information from the second node.
 */
void nodeUpdate(Node* node1, Node* node2) {
    if (node1->sku == NULL && node2->sku != NULL) {
        node1->sku = (String)malloc(sizeof(node2->sku));
        strcpy(node1->sku, node2->sku);
    }
    if (node1->name == NULL && node2->name != NULL) {
        node1->name = (String)malloc(sizeof(node2->name));
        strcpy(node1->name, node2->name);
    }
    if (node1->price == NULL && node2->price != NULL) {
        node1->price = (String)malloc(sizeof(node2->price));
        strcpy(node1->price, node2->price);
    }
}

/*
 * compareTo: Takes in two nodes checks the order based on sku or name, if one
 * node has a NULL for sku then it returns negative one.
 */
int compareTo(Node* node1, Node* node2) {
    if (node1 == NULL || node2 == NULL) {
        return -1;
    }
    if (node1->sku != NULL && node2->sku != NULL) {
        return strncmp(node1->sku, node2->sku, MAX_CHARS);
    } else if (node1->name != NULL && node2->name != NULL) {
        if (strncmp(node1->name, node2->name, MAX_CHARS) == 0) {
            return 0;
        }
    }
    if (node1->sku == NULL) {
        return -1;
    }
    return 1;
}

/*
 * createNode: Takes in a char * and parses the data to input in a node and
 * returns the newly created node.
 */
Node* createNode(String input) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    tempNode->sku = NULL;
    tempNode->name = NULL;
    tempNode->price = NULL;
    tempNode->quantity = 1;
    tempNode->next = NULL;

    int skuEndIndex = isNumericString(input, 0);
    int priceIndex = isPriceString(input, strlen(input) - 1);
    if (skuEndIndex != 0) {
        tempNode->sku = (String)malloc(skuEndIndex + 1);
        subString(tempNode->sku, input, 0, skuEndIndex);
    }

    if (priceIndex != 0) {
        tempNode->price = (String)malloc(priceIndex);
        int strSize = strlen(input);
        int start = strSize - priceIndex;
        subString(tempNode->price, input, start, strSize - 1);
    }

    if (hasString(input) == 1) {
        // printf("%s\n", "This has String");
        int start = getStartOfString(input);
        int end = getEndOfString(input);
        // printf("%d %d\n", start, end );
        tempNode->name = (String)malloc((end - start) + 1);
        subString(tempNode->name, input, start, end + 1);
    }
    if (tempNode->sku == NULL && tempNode->name == NULL) {
        destroyNode(tempNode);
        return NULL;
    }
    return tempNode;
}

/*
 * orderList: Orders the link list by sku numbers.
 */
Node* orderList(Node* head) {
    int test;

    return head;
}

/*
 * getStartOfString: Returns the integer location of the first char in the line.
 */
int getStartOfString(String line) {
    char c;
    int i = 0;

    while ((c = *(line + i)) != '\n' && c != '\0' && c != EOF) {
        if (isAlpha(c) == 1) {
            return i;
        }
        i++;
    }
    return 0;
}

/*
 * getEndOfString: returns the int location of the last char in the line.
 */
int getEndOfString(String line) {
    char c;
    int i = strlen(line) - 2;
    // printf("What i is: %d\n", i );

    while ((c = *(line + i)) != '\n' && c != '\0' && c != EOF && c >= 0) {
        if (isAlpha(c) == 1) {
            return i;
        }
        i--;
    }
    return 0;
}

/*
 * hasString: checks if the line has a string of chars.
 */
int hasString(String line) {
    char c;
    int i = 0;
    while ((c = *(line + i)) != '\n' && c != '\0' && c != EOF) {
        if (isAlpha(c) == 1) {
            return 1;
        }
        i++;
    }
    return 0;
}

/*
 * subString: Takes a string from start location to end location as index.
 */
int subString(String to, String from, int start, int end) {
    String str;
    int j = 0, i = 0;

    for (i = start; i < end; i++, j++) {
        to[j] = from[i];
    }
    to[j] = '\0';
    return i - start + 1;
}

/*
 * printNode: prints the contents of node to standar out
 */
void printNode(Node* node) {
    if (node != NULL) {
        if (node->sku != NULL) {
            printf("%s ", node->sku);
        }
        if (node->name != NULL) {
            printf("%s ", node->name);
        }
        if (node->price != NULL) {
            printf("$%s", node->price);
        }
        printf(": %d in stock\n", node->quantity);
    }
}

/*
 * printList: prints each item on the list
 */
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printNode(current);
        current = current->next;
    }
}

/*
 * isNumeric: returns 1 if the char is a number, 0 otherwise.
 */
int isNumeric(char c) {
    if (c >= 48 && c <= 57) {
        return 1;
    }
    return 0;
}

/*
 * isAlpha: returns 1 if the char is a alphabet letter, 0 otherwise
 */
int isAlpha(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    }
    return 0;
}

/*
 * isPriceString: starts at the end of the string and checks each chars to see
 * if it's numeric.
 */
int isPriceString(String cp, int endIndex) {
    char c;
    int hasMarker = 0;
    int i = endIndex - 1;
    while ((c = *(cp + i)) != EOF && c != '\n' && c != ' ' && i > 0) {
        if (isNumeric(c) != 0 || c == 46) {
            if (c == 46) {
                hasMarker = 1;
            }
            i--;
        } else {
            return 0;
        }
    }
    if (hasMarker != 1) {
        return 0;
    }
    return endIndex - i;
}

/*
 * isNumericString returns the next space as while each char is numeric.
 */
int isNumericString(String cp, int startIndex) {
    char c;
    int i = startIndex;
    while ((c = *(cp + i)) != EOF && c != '\n' && c != ' ') {
        if (isNumeric(c) == 0) {
            return 0;
        } else {
            i++;
        }
    }
    return i - startIndex;
}
