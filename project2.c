#include <stdio.h>
#include "item.c"
#define MAX_LINES 1000
#define MAX_CHARS 120


int main() {

    typedef char* String;




    struct node *myNode;

    myNode->value = 5;
    myNode->name = "\0";

    printf("%s\n", myNode->name);

    //int number = myNode.value;
    //String myName = myNode.name;

    //printf("%d %s\n", number, myName);









    //TODO: Receive data

    //TODO: Send data.

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
