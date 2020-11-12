/*****************************************************************//**
 * \file   cardinal_sort.h
 * \brief  使用这个文档时，应该把main.c后缀名改为main.cpp，按C++语法来编译就能通过
 * 
 * \author 32353
 * \date   November 2020-11-11
 *********************************************************************/
#ifndef __CARDINAL_SORT_HELLO_QIU__
#define __CARDINAL_SORT_HELLO_QIU__

#define _cpluscplus

#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM_OF_KEY 3			//关键字项数的最大值
#define RADIX 10					//关键字基数，此时是十进制整数的基数
#define MAX_SPACE 10			

#define KeyType int
#define InfoType void*

	typedef struct StaticListNode
	{
		KeyType keys[MAX_NUM_OF_KEY];	//关键字
		InfoType otheritems;			//其他数据项
		int next;
	}StaticListNode;

	typedef struct StaticList
	{
		StaticListNode r[MAX_SPACE];	//静态链表的可利用空间，r[0]为头节点
		int keynum;						//记录当前的关键字个数
		int recnum;						//静态链表的当前长度
	}StaticList;

	typedef int ArrType[RADIX];			//指针数组类型

	//静态链表list的r域中记录已按(keys[0],……,key[i-1]有序，本算法按第i个关键字key[i]建立RADIX个子表，使同一子表中记录keys[i]相同
	//f[0,……, RADIX-1]和e[0,……,RADIX-1]分别指向各子表中第一个和最后一个记录
	void distribute(StaticListNode* r, int i, ArrType& f, ArrType& e);

	//本算法按keys[i]自小到大将f[0,……,RADIX-1]所指各子表依次链接成一个链表,e[0,……,RADIX]为各子表的尾指针
	void collect(StaticListNode* r, int i, ArrType& f, ArrType& e);

	//list是采用静态链表表示的顺序表
	//对list作基数排序，使得list成为按关键字自小到大的有序静态链表，list.r[0]为头节点
	void radix_sort(StaticList* list);

	void cardinal_sort_callback();

	void creat_keys(KeyType keys[MAX_NUM_OF_KEY], int val, int len);
	int get_keys(KeyType keys[], int len);

#endif