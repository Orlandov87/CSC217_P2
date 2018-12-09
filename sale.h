/*
 * Author: Orlando Vargas
 * Language: C
 */
typedef char* String;
/*
 * Search the list for the sku, if it finds it, it returns the address
 * of the node, NULL otherwise.
 */
Node* searchSKU(Node*, String);

/*
 * Takes in the sku, the quantity, the tax, the list of nodes and the
 */
void buy(String, int, Node*);

/*
 *
 */
void total(float, float);