#include "project2.h"

/*
 * Search the list for the sku, if it finds it, it returns the address
 * of the node, NULL otherwise.
 */
// TODO: Make it more efficient where it stops after it reaches a sku
// larger than itself.
Node* searchSKU(Node* list, String sku) {
    Node* temp = list;
    while (strncmp(temp->sku, sku, MAX_CHARS) != 0 && temp != NULL) {
        temp = temp->next;
    }
    return temp;
}
