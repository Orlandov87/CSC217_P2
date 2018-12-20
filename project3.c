/*
 * Author: Orlando Vargas
 * Purpose: Takes in a list of products and returns a list
 *          a combined list of products will complete information.
 * Language: C
 */
#include "project3.h"

int main(int argc, char* argv[]) {
    Node* list = NULL;
    char line[MAX_LINES];

    char seller[MAX_LINES];
    char buyer[MAX_LINES];

    float sub = 0;
    float tax = 8.25;

    while (myGetLine(line, MAX_CHARS) != 0) {
        list = addNode(list, createNode(line));
    }

    printList(list);
    printf("\n");

    // Project 3 start
    int quantity = 0;
    // FILE* fp = fopen("sale.txt", "r");

    for (int i = 1; i < argc; i++) {
        FILE* fp = fopen(argv[i], "r");

        if (fp == NULL) {
            fprintf(stderr, "Couldn't read file");
        } else {
            fscanf(fp, "%s", seller);
            fscanf(fp, "%s", buyer);

            printf("Thank you, %s, for choosing CSC Music Store\n", buyer);
            while (fscanf(fp,
                          "%s"
                          "%d",
                          line, &quantity) != EOF) {
                sub += buy(line, quantity, list);
            }
        }
        fclose(fp);
        total(sub, tax);
        sub = 0;
        printf("Your salesperson: %s\n", seller);
    }

    // printList(list);

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

int myGetLinef(char s[], int lim, FILE* fp) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getc(fp)) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}