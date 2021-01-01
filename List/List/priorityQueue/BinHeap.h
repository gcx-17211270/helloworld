#pragma once
#ifndef __BINHEAP_H_HELLO_QIU__
#define __BINHEAP_H_HELLO_QIU__

//根据实际需求更改
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

	//优先队列的初始化
	PriorityQueue initialize(int maxElements);

	//销毁一个优先队列
	void destroy(PriorityQueue H);

	//在优先队列中插入一个元素
	void insert(ElementType data, PriorityQueue H);

	//删除优先队列中的最小元素
	ElementType delete_min(PriorityQueue H);

	//查找优先队列中的最小元素
	ElementType fine_min(PriorityQueue H);

	//判断优先队列是否为空
	BOOL is_empty(PriorityQueue H);

	//判断优先队列是否已满
	BOOL is_full(PriorityQueue H);

	//有限队列结构体定义
	struct HeapStruct {
		int capacity;
		int size;
		ElementType* elements;
	};
#ifdef _cpluscplus
}
#endif
#endif