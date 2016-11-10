#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef double element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;