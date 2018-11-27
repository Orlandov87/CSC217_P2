#include "project2.h"

int main() {

    Node *head = NULL;
    Node *temp = NULL;
    char line[MAX_LINES];


    


    myGetLine(line, MAX_CHARS);
    //printf("%s", line);

    temp = createNode(line);

    head = addNode(head, temp);


    printList(head);

    return 0;
}

/*
 * Returns a line of chars from standard.in
 */
int myGetLine(char s[], int lim){
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
