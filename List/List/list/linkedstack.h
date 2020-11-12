#ifndef ALGORITHM_LINKEDSTACK_H
#define ALGORITHM_LINKEDSTACK_H

#ifdef __cplusplus
extern "C" {
#endif
#include "SList.h"

	//����һ��ջ
	void linkedstack_free(SListEntry* linkedStack);

	//��ջ������Ԫ��
	SListEntry* linkedstack_push(SListEntry** linkedStack, SListValue data);

	//��ջ��ɾ��ջ��Ԫ��
	SListValue linkedstack_pop(SListEntry** linkedStack);

	//��ȡջ��Ԫ��
	SListValue linkedstack_peek(SListEntry* linkedStack);

	//�ж�ջ�Ƿ�Ϊ��
	int linkedstack_is_empty(SListEntry* linkedStack);

#ifdef __cplusplus
}
#endif
#endif
