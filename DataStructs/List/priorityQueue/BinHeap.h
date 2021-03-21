#pragma once
#ifndef __BINHEAP_H_HELLO_QIU__
#define __BINHEAP_H_HELLO_QIU__

//����ʵ���������
#define ElementType double

#define BOOL int
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

#ifdef _cpluscplus_
extern "C" {
#endif
	struct HeapStruct;
	typedef struct HeapStruct* PriorityQueue;

	//���ȶ��еĳ�ʼ��
	PriorityQueue initialize(int maxElements);

	//����һ�����ȶ���
	void destroy(PriorityQueue H);

	//�����ȶ����в���һ��Ԫ��
	void insert(ElementType data, PriorityQueue H);

	//ɾ�����ȶ����е���СԪ��
	ElementType delete_min(PriorityQueue H);

	//�������ȶ����е���СԪ��
	ElementType fine_min(PriorityQueue H);

	//�ж����ȶ����Ƿ�Ϊ��
	BOOL is_empty(PriorityQueue H);

	//�ж����ȶ����Ƿ�����
	BOOL is_full(PriorityQueue H);

	//���޶��нṹ�嶨��
	struct HeapStruct {
		int capacity;
		int size;
		ElementType* elements;
	};
#ifdef _cpluscplus
}
#endif
#endif