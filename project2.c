#include "project2.h"

int main() {

    Node *head = NULL;

    char line[MAX_LINES];



    myGetLine(line, MAX_CHARS);
    printf("%s", line);

    Node *temp1 = createNode(line, strlen(line));
    head = addNode(head, temp1);



    //Node temp = {218, "Orlando", 0.0};
    //Node temp2 = {6, "Test"};

    //printNode(head);

    //head = addNode(head, &temp);

    //printf("The number is: %d\n", head->sku);
    //printf("%s\n", head->name);
    //printf("%d\n",head->quantaty );

    //char * test = "Testing this";
    //char str[] = "First string";

    //char * str1 = strtok(str, " ");
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
