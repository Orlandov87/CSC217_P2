/*
 * Author: Orlando Vargas
 * Purpose: Takes in a list of products and returns a list
 *          a combined list of products will complete information.
 * Language: C
 */
#include "project2.h"

int main() {
    Node* list = NULL;
    char line[MAX_LINES];

    while (myGetLine(line, MAX_CHARS) != 0) {
        list = addNode(list, createNode(line));
    }

    printList(list);
    printf("\n");
    // Project 3

    int quantity = 0;
    FILE* fp = fopen("sale.txt", "r");
    while (fp != NULL || fp != EOF) {
        fscanf(fp,
               "%s"
               "%d",
               line, &quantity);

        buy(line, quantity, list);
    }

    printf("\n");
    printList(list);

    float sub = 36.96;
    float tax = 8.25;
    total(sub, tax);

    fclose(fp);
    destroyNode(list);
    list = NULL;
    return 0;
}

/*
 * Returns a line of chars from standard.in
 */
int myGetLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
