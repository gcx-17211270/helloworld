#ifndef ALGORITHM_SEQSTACK_H
#define ALGORITHM_SEQSTACK_H

#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

	//建立一个新的栈
	ArrayList* seqstack_new(unsigned int length);

	//销毁一个栈
	void seqstack_free(ArrayList* seqstack);

	//在栈顶插入元素
	int seqstack_push(ArrayList* seqstack, ArrayListValue data);

	//在栈中弹出栈顶元素
	ArrayListValue seqstack_pop(ArrayList* seqstack);

	//读取栈顶元素
	ArrayListValue seqstack_peek(ArrayList* seqstack);

	//判断栈是否为空
	int seqstack_is_empty(ArrayList* seqstack);

#ifdef __cpluscplus
}
#endif

#endif	/* #ifndef ALGORITHM_SEQSTACK_H */