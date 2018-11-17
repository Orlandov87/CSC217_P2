#include <stdio.h>
#include "item.c"
#define MAX_LINES 1000
#define MAX_CHARS 120


int main() {

<<<<<<< HEAD
    typedef char* String;




    struct node *myNode;

    myNode->value = 5;
    myNode->name = "\0";

    printf("%s\n", myNode->name);

    //int number = myNode.value;
    //String myName = myNode.name;

    //printf("%d %s\n", number, myName);









    //TODO: Receive data
=======
>>>>>>> 15067a03206e92d95087919a87f9fb1a43825a5f

  return 0;
}

/*
<<<<<<< HEAD
struct node *addToList(struct node *p, char *w) {

}



int getMyLine(char s[], int lim){
    int c, i;
=======
  Returns a line of chars from standard.in
*/
int myGetLine(char s[], int lim){
  int c, i;
>>>>>>> 15067a03206e92d95087919a87f9fb1a43825a5f

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
