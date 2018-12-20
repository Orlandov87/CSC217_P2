/*
 * Author: Orlando Vargas
 * Language: C
 */
#include "project3.h"

/*
 * Search the list for the sku, if it finds it, it returns the address
 * of the node, NULL otherwise.
 */
// TODO: Make it more efficient where it stops after it reaches a sku
// larger than itself.
Node* searchSKU(Node* list, String sku) {
    Node* temp = list;
    // Realized to put strcmp after
    while (temp != NULL && strcmp(temp->sku, sku) != 0) {
        temp = temp->next;
    }
    return temp;
}

/*
 * buy: Checks the list if the sku exist, if it does it lessens quantity of that
 * particular item.
 */

// TODO: This can be programmed more efficiently.
float buy(String sku, int quantity, Node* list) {
    Node* temp = searchSKU(list, sku);
    float sub = 0;
    if (temp == NULL || temp->quantity == 0) {
        printf("Sku %s not in stock\n", sku);
    } else if (temp->quantity < quantity) {
        float priceAsF = strtof(temp->price, NULL);
        priceAsF = priceAsF * (temp->quantity);
        printf("Requested %d %s: only %d in stock\n", quantity, temp->name,
               temp->quantity);
        printf("%d x %s @ $%s: $%0.2f\n", temp->quantity, temp->name,
               temp->price, priceAsF);
        temp->quantity = 0;
        sub = priceAsF;
    } else {
        float priceAsF = strtof(temp->price, NULL);
        priceAsF = priceAsF * quantity;
        temp->quantity = temp->quantity - quantity;
        printf("%d x %s @ $%s: $%0.2f\n", quantity, temp->name, temp->price,
               priceAsF);
        sub = priceAsF;
    }
    return sub;
}

/*
 * total: This calculates the total cost base on the tax
 * and the price of all the item.
 */
void total(float subTotal, float tax) {
    float saleTax = subTotal * (tax / 100);
    float total = saleTax + subTotal;

    printf(
        "\nTotal sale: $%0.2f\nSales tax(%0.2f%%): $%0.2f\nFinal price: "
        "$%0.2f\n",
        subTotal, tax, saleTax, total);
}