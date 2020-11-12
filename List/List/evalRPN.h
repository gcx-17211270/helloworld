#include <stdio.h>
//#define NULL 0

typedef struct _Stack Stack;
struct _Stack
{
	int data;
	Stack* next;
};

//普通数据入栈
void push_int(Stack** s, int res);

//正的数据，字符串形式入栈
void push_char(Stack** stack, char* s);

//负的数据，字符串形式入栈
void push_minus(Stack** stack, char* s);

//出栈
int pop(Stack** s);

//回调函数
void evalRPN_callback();