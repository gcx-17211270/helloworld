/**
* 数据结构：顺序栈
*/

#include "seqstack.h"

ArrayList* seqstack_new(unsigned int length)
{
	ArrayList* seqstack = arraylist_new(length);		//栈就是限定了出入方式的线性表
	return seqstack;
}

void seqstack_free(ArrayList* seqstack)
{
	arraylist_free(seqstack);
}

int seqstack_push(ArrayList* seqstack, ArrayListValue data)
{
	return arraylist_append(seqstack, data);
}

ArrayListValue seqstack_pop(ArrayList* seqstack)
{
	ArrayListValue result = seqstack->data[seqstack->length - 1];
	arraylist_remove(seqstack, seqstack->length - 1);
	return result;
}

ArrayListValue seqstack_peek(ArrayList* seqstack)
{
	if (seqstack_is_empty(seqstack))
		return NULL;
	return seqstack->data[seqstack->length - 1];
}
int seqstack_is_empty(ArrayList* seqstack)
{
	return seqstack == NULL;
}