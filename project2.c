#include "project2.h"


int main() {

    Node *head = NULL;

    int five = -1;

    Node temp = {5, "Orlando"};
    Node temp2 = {6, "Test"};

    head = addNode(head, &temp);

    //addNode(root, &temp);

    printf("The number is: %d\n", head->sku);
    printf("%s\n", head->name);
    printf("%d\n",head->quantaty );

    char * test = "Testing this";

    char *token = strtok(test, " ");


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
