typedef char* String;

typedef struct node{
  int sku;
  String name;
  float price;

  struct node *next;
}Node;

/*
 * makeNode: This function takes in a line of input and converts it and inputs
 * the data in a node. Then it returns a pointer to the node.
 */
Node makeNode(String);

/*
 * addNode: This funciton takes in as perameter the root node and a node of data
 * to be added to the tree. If root is NULL it will make a new node and return
 * the new node as the root.
 */
Node addNode(Node root, Node node);

/*
 * removeNode: This fucntion takes in as parameter the root node and the node
 * to be removed. If the root is null or the data is not in the tree then
 * this functions returns NULL.
 */
Node removeNode(Node root, Node node);

/*
 * printTree: This funcitons prints the tree info to Standard output.
 */
void printTree(Node root);
