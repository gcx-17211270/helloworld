#include <stdio.h>
//#define NULL 0

typedef struct _Stack Stack;
struct _Stack
{
	int data;
	Stack* next;
};

//��ͨ������ջ
void push_int(Stack** s, int res);

//�������ݣ��ַ�����ʽ��ջ
void push_char(Stack** stack, char* s);

//�������ݣ��ַ�����ʽ��ջ
void push_minus(Stack** stack, char* s);

//��ջ
int pop(Stack** s);

//�ص�����
void evalRPN_callback();