#include "evalRPN.h"
#include <stdlib.h>
void push_int(Stack** s, int res)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->data = res;
	temp->next = *s;
	*s = temp;
}
void push_char(Stack** stack, char* s)
{
	int res = 0;
	char* c = s;
	while (*c != '\0')
	{
		res = res * 10 + (int)(*c - '0');
		c++;
	}
	push_int(stack, res);
}
void push_minus(Stack** stack, char* s)
{
	int res = 0;
	char* c = s + 1;
	while (*c != '\0')
	{
		res = res * 10 + (int)(*c - '0');
		c++;
	}
	res *= -1;
	push_int(stack, res);
}
int pop(Stack** s)
{
	int temp = (*s)->data;
	Stack* tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return temp;
}

int evalRPN(char** tokens, int tokensSize) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->data = 0;
	stack->next = NULL;
	for (int i = 0; i < tokensSize; i++)
	{
		if (tokens[i][0] <= '9' && tokens[i][0] >= '0')
		{
			push_char(&stack, tokens[i]);
		}
		else if (tokens[i][0] == '-' && tokens[i][1] != '\0')
		{
			push_minus(&stack, tokens[i]);
		}
		else
		{
			int value1 = pop(&stack);
			int value2 = pop(&stack);
			if (tokens[i][0] == '+')
				push_int(&stack, value2 + value1);
			if (tokens[i][0] == '-')
				push_int(&stack, value2 - value1);
			if (tokens[i][0] == '*')
				push_int(&stack, value2 * value1);
			if (tokens[i][0] == '/')
				push_int(&stack, value2 / value1);
		}
	}
	return pop(&stack);
}

void evalRPN_callback()
{
	char* s[13] = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	printf("%d\n", evalRPN(s, 13));
}