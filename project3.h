/*
 * Author: Orlando Vargas
 * Language: C
 */
/*
 * Libaries used
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * User Defined libaries.
 */
#include "item.h"
#include "sale.h"

/*
 * Definitions
 */
#define MAX_CHARS 120
#define MAX_LINES 1000

/*
 * Type Definitions
 */
typedef char* String;

int myGetLine(char[], int);
int myGetLinef(char[], int, FILE*);
