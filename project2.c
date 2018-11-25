#include <stdio.h>
#include "item.h"

int main() {

Point root = NULL;


  return 0;
}

/*
  Returns a line of chars from standard.in
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
