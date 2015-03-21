/*
 * Write the program expr, which evaluates a reverse Polish expression
 * from the command line, where each operator or operand is a separate
 * argument.
 *
 * For example:
 *   expr 2 3 4 + *
 *
 * evaluates 2 * (3 + 4)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "my_utils.h"

#define STACKSIZE 32

int stack[STACKSIZE];
int *stackptr = stack;

void push(int val);
int pop();

int main(int argc, char **argv)
{
	char ch;
	char *cur;
	int op; 
	if(argc < 2)
	{
		printf("There is no calculation possible\n");
		exit(EXIT_FAILURE);
	}
	if(argc > 32)
	{
		printf("Too many arguments, this is just a small application\n");
		exit(0);
	}

	while(--argc > 0)
	{
		ch=*(++argv)[0];
		switch(ch)
		{
		case '-':
			if((cur = *(argv))[1])
			{
				push(atoi(cur));
			}
			else
			{
				op = pop();
				push(op - pop());
			}
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op = pop();
			push(op / pop());
			break;
		default:
			push(atoi(*argv));
		}
	}

	printf("Result: %d\n", pop());	
	return EXIT_SUCCESS;
}


void push(int val)
{
	if(stackptr < stack + STACKSIZE + 1)
		*(++stackptr) = val;
	else
		printf("Stack size exceeded\n");
}

int pop()
{
	if(stackptr > stack)
		return *(stackptr--);
	else
		printf("stack empty\n");
	return -1;
}

