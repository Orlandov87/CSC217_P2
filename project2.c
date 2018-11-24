#include "project2.h"


int main() {

    Node *root = NULL;

    Node temp = {5, "Orlando"};
    Node temp2 = {6, "Test"};

    root = addNode(root, &temp);

    //addNode(root, &temp);

    printf("The number is: %d\n", root->sku);
    printf("%s\n", root->name);
    printf("%d\n",root->quantaty );

    return 0;
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
