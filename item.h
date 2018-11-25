/*
 * Type Definitions
 */
typedef char* String;

/*
 * definition: Node structure of type product
 */
typedef struct node{
  int sku;
  String name;
  float price;
  int quantaty;

  struct node *next;
}Node;

/*
 * makeNode: This function takes in a line of input and converts it and inputs
 * the data in a node. Then it returns a pointer to the node.
 */
Node* makeNode(String);

/*
 * addNode: This function takes in as parameter the head node and a new node.
 * If the head node is NULL, the new node will become the head node, otherwise
 * it will add the new node to the list.
 */
Node* addNode(Node *root, Node *node);

/*
 * removeNode: This function takes in as parameter the root node and the node
 * to be removed. If the root is null or the data is not in the tree then
 * this functions returns NULL.
 */
int removeNode(Node root, Node node);

/*
 * printTree: This funcitons prints the tree info to Standard output.
 */
void printTree(Node root);
