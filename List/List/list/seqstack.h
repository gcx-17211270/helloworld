#ifndef ALGORITHM_SEQSTACK_H
#define ALGORITHM_SEQSTACK_H

#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

	//����һ���µ�ջ
	ArrayList* seqstack_new(unsigned int length);

	//����һ��ջ
	void seqstack_free(ArrayList* seqstack);

	//��ջ������Ԫ��
	int seqstack_push(ArrayList* seqstack, ArrayListValue data);

	//��ջ�е���ջ��Ԫ��
	ArrayListValue seqstack_pop(ArrayList* seqstack);

	//��ȡջ��Ԫ��
	ArrayListValue seqstack_peek(ArrayList* seqstack);

	//�ж�ջ�Ƿ�Ϊ��
	int seqstack_is_empty(ArrayList* seqstack);

#ifdef __cpluscplus
}
#endif

#endif	/* #ifndef ALGORITHM_SEQSTACK_H */