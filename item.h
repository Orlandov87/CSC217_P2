/*
 * Author: Orlando Vargas
 * Language: C
 */

/*
 * Type Definitions
 */
typedef char *String;

/*
 * definition: Node structure of type node
 */
typedef struct node {
    String sku;
    String name;
    String price;
    int quantity;

    struct node *next;
} Node;

/*
 * makeNode: This function takes in a line of input and converts it and inputs
 * the data in a node. Then it returns a pointer to the node.
 */
Node *createNode(String);

/*
 * addNode: This function takes in as parameter the head node and a new node.
 * If the head node is NULL, the new node will become the head node, otherwise
 * it will add the new node to the list.
 */
Node *addNode(Node *root, Node *node);

/*
 * removeNode: This function takes in as parameter the root node and the node
 * to be removed. If the root is null or the data is not in the tree then
 * this functions returns NULL.
 */
int removeNode(Node root, Node node);

/*
 * printTree: This funcitons prints the tree info to Standard output.
 */
int subString(String, String, int, int);

/*
 * isPriceString:
 */
int isPriceString(String, int);

/*
 * hasString: checks if the line has a string of chars.
 */
int hasString(String);

/*
 * isAlpha: returns 1 if the char is a alphabet letter, 0 otherwise
 */
int isAlpha(char);

/*
 * orderList: This function orders the list based on their sku numbers.
 */
Node *orderList(Node *);

/*
 * getStartOfString: Returns the integer location of the first char in the line.
 */
int getStartOfString(String);

/*
 * getEndOfString: returns the int location of the last char in the line.
 */
int getEndOfString(String);

/*
 * destroyNode: This function takes in as parameter a Node and frees up the
 * memory that is being used. If the Node points to another node it will call
 * destroyNode on that node.
 */
void destroyNode(Node *);

/*
 * printNode: prints the contents of node to standar out
 */
void printNode(Node *);

/*
 * printList: prints each item on the list
 */
void printList(Node *);

/*
 * compareTo: Takes in two nodes checks the order based on sku or name, if one
 * node has a NULL for sku then it returns negative one.
 */
int compareTo(Node *, Node *);

/*
 * nodeUpdate: Takes in two nodes and updates the first node with the
 * information from the second node.
 */
void nodeUpdate(Node *, Node *);
/*
 * isNumeric: returns 1 if the char is a number, 0 otherwise.
 */
int isNumeric(char);
/*
 * isNumericString returns the next space as while each char is numeric.
 */
int isNumericString(char *, int);
