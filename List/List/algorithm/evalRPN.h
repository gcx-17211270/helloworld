#include <stdio.h>
//#define NULL 0
#ifndef __EVALRPN_HELLO_QIU__
#define __EVALRPN_HELLO_QIU__

#ifdef _cpluscplus
extern "C"
{
#endif
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
#ifdef _cpluscplus
}
#endif
#endif