#ifndef __HELLO_SLIST_QIU_
#define __HELLO_SLIST_QIU_

//定义链表中数据的空指针
#define SLIST_NULL ((void*) 0)

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

	//单向链表结构
	typedef struct _SListEntry SListEntry;
	//链表迭代器结构，用于遍历链表
	typedef struct _SListInterator SListIterator;

	//指向链表中存储的数据的指针
	typedef void* SListValue;

	//定义判断两个值是否相等的数据类型
	typedef int (*SListEqualFunc)(SListValue value1, SListValue value2);
	//在排序时比较链表两个节点数据的类型
	typedef int (*SListCompareFunc)(SListValue value1, SListValue value2);

	//单链表的节点结构
	struct _SListEntry
	{
		SListValue data;
		SListEntry* next;
	};

	//定义链表迭代器结构
	struct _SListInterator
	{
		SListEntry** prev_next;
		SListEntry* current;
	};

//判断链表是否为空，空表返回1
	int slist_is_empty(SListEntry* list);

	//判断listentry是否为表中最后一个节点，如果是则返回1
	int slist_is_last(SListEntry* listentry);

	//删除表并释放内存
	void slist_free(SListEntry* list);

	//添加新节点到头部，返回指向新节点的指针
	SListEntry* slist_prepend(SListEntry** list, SListValue data);

	//添加新节点到尾部，返回指向新节点的指针
	SListEntry* slist_append(SListEntry** list, SListValue data);

	//获得链表中该节点的下一个节点
	SListEntry* slist_next(SListEntry* listentry);

	//获得节点中存储的数据
	SListValue slist_data(SListEntry* listentry);

	//获得链表的长度
	unsigned int slist_length(SListEntry* list);

	//寻找特定节点的前驱节点，如果找到返回前驱节点，否则返回尾节点
	SListEntry* slist_find_previous(SListEntry** list, SListEntry* listentry);

	//从链表中移除一个节点，找到并移除后返回1，否则返回0
	int slist_remove_entry(SListEntry** list, SListEntry* entry);

	//向链表中插入一个节点
	SListEntry* slist_insert(SListEntry** list, SListEntry* listentry, SListValue data);

	//得到指向第n个节点的指针，返回序列号为n的节点指针，如果序号超出范围则返回NULL
	SListEntry* slist_nth_entry(SListEntry* list, unsigned int n);

	//获取第n个节点的数据，如果失败则返回SLIST_NULL;
	SListValue slist_nth_data(SListEntry* list, unsigned int n);

	//创建一个包含链表中内容的数组，返回新建的数组，内存申请失败则返回NULL，数组长度与链表相等
	SListValue* slist_to_array(SListEntry* list);

	//查找具有特定数据的节点，返回找到的第一个节点，若未找到则返回NULL
	////Callback函数用于比较表中数据与待查数据是否相等
	//SListEntry* slist_find_data(SListEntry* list, SListEqualFunc callback, SListValue data);

	//初始化一个链表迭代器，用于遍历链表，返回指向初始化的链表迭代器的指针
	void slist_interator(SListEntry** list, SListIterator* iter);

	//判断链表中是否还有更多数据待遍历，iterator为链表迭代器，没有则返回0，有则返回非零数
	int slist_iter_has_more(SListIterator* iterator);

	//用链表迭代器获取链表中的下一个节点
	SListValue slist_iter_next(SListIterator* iterator);

	//删除当前遍历到的位置的节点
	void slist_iter_remove(SListIterator* iterator);

	void slist_sort(SListEntry** list, SListCompareFunc compare_func);

	//用于内部快速排序的函数，返回排序后的尾节点
	static SListEntry* slist_sort_internal(SListEntry** list, SListCompareFunc compare_func);
	
#ifdef __cpluscplus
}
#endif

#endif