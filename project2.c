#include "test.h"
#include <stdlib.h>


int main() {

    Node *root;

    Node temp = {5, "Orlando"};
    Node temp2 = {6, "Test"};

    addNode(root, &temp);

    printf("%s\n", root->name);

    return 0;
}


void addNode(Node *head, int num) {
    if(head == NULL) {
        head = malloc(sizeof(Node));

    }
}

/*
struct node *addToList(struct node *p, char *w) {

}



int getMyLine(char s[], int lim){
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if(c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
*/
