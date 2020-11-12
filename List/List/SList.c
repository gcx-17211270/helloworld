/**
* 数据结构：链表
*/

#include "SList.h"

SListValue slist_data(SListEntry* listentry)
{
	return listentry->data;
}

SListEntry* slist_next(SListEntry* listentry)
{
	return listentry->next;
}

int slist_is_last(SListEntry* listentry)
{
	return listentry->next == NULL;
}

int slist_is_empty(SListEntry* list)
{
	return list == NULL;
}

void slist_free(SListEntry* list)
{
	SListEntry* temp = list;
	SListEntry* next = list;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

SListEntry* slist_prepend(SListEntry** list, SListValue data)
{
	SListEntry* newEntry = (SListEntry*)malloc(sizeof(SListEntry));
	newEntry->data = data;
	newEntry->next = *list;
	*list = newEntry;
	return newEntry;
}

SListEntry* slist_append(SListEntry** list, SListValue data)
{
	SListEntry* newEntry = (SListEntry*)malloc(sizeof(SListEntry));
	newEntry->data = data;
	SListEntry* temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newEntry;
	return newEntry;
}
unsigned int slist_length(SListEntry* list)
{
	unsigned int count = 0;
	SListEntry* temp = list;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int slist_remove_entry(SListEntry** list, SListEntry* entry)
{
	if (*list == NULL || entry == NULL)
		return 0;
	SListEntry* temp = *list;
	while (temp != NULL && temp->next != entry)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return 0;
	}
	if (temp->next != entry)
	{
		free(temp->next);
		temp->next = entry->next;
		return 1;
	}
	return 0;
}
SListEntry* slist_find_previous(SListEntry** list, SListEntry* listentry)
{
	SListEntry* rover = *list;
	while (rover->next != NULL && rover->next != listentry)
	{
		rover = rover->next;
	}
	return rover;
}

SListEntry* slist_insert(SListEntry** list, SListEntry* listentry, SListValue data)
{
	SListEntry* newEntry = slist_find_previous(list, listentry);
	if (newEntry == NULL) return SLIST_NULL;
	else
	{
		newEntry = (SListEntry*)malloc(sizeof(SListEntry));
		if (newEntry == NULL) return SLIST_NULL;
		newEntry->data = data;
		newEntry->next = listentry->next;
		listentry->next = newEntry;
		return newEntry;
	}
}
SListValue slist_iter_next(SListIterator* iterator)
{
	if (iterator->current == NULL || iterator->current != *iterator->prev_next)
	{
		//第一个节点还没读入，或已遍历至表尾，或当前遍历到的地方
		iterator->current = *iterator->prev_next;
	}
	else {
		//当前遍历到的位置的节点存在，则遍历下一个节点
		iterator->prev_next = &iterator->current->next;
		iterator->current = iterator->current->next;
	}

	//判断当前遍历到的位置是否在表尾
	if (iterator->current == NULL)
		return SLIST_NULL;
	else
		return iterator->current->data;
}
SListValue slist_nth_data(SListEntry* list, unsigned int n)
{
	SListEntry* entry;

	entry = slist_nth_entry(list, n);

	if (entry == NULL) {
		return SLIST_NULL;
	}
	else {
		return entry->data;
	}
}
SListEntry* slist_nth_entry(SListEntry* list, unsigned int n) {
	SListEntry* entry;
	unsigned int i;

	/* 通过n个链表结点到达所需结点，并且确保没有达到表尾 */

	entry = list;
	for (i = 0; i < n; ++i) {
		if (entry == NULL) {
			return NULL;
		}
		entry = entry->next;
	}
	return entry;
}

void slist_sort(SListEntry** list, SListCompareFunc compare_func)
{
	slist_sort_internal(list, compare_func);
}

static SListEntry* slist_sort_internal(SListEntry** list, SListCompareFunc compare_func)
{
	SListEntry* pivot;
	SListEntry* rover;
	SListEntry* lessList, * moreList;
	SListEntry* lessListEnd, * moreListEnd;

	//如果数据少于2个，则已经完成排序
	if (*list == NULL || (*list)->next == NULL)
		return *list;

	//pivot指向头节点
	pivot = *list;

	//从第二个节点开始遍历链表，根据每个节点与头节点比较的结果，将节点归入lessList和moreList两个子链表中
	lessList = NULL;
	moreList = NULL;
	rover = (*list)->next;
	while (rover != NULL)
	{
		SListEntry* next = rover->next;
		if (compare_func(rover->data, pivot->data) < 0)
		{
			//把这个节点放入lessList中
			rover->next = lessList;
			lessList = rover;
		}
		else
		{
			//把这个节点放入moreList中
			rover->next = moreList;
			moreList = rover;
		}
		rover = next;
	}

	//对子链表递归排序
	lessListEnd = slist_sort_internal(&lessList, compare_func);
	moreListEnd = slist_sort_internal(&moreList, compare_func);

	//创建以lessList为开始部分新链表
	*list = lessList;
	
	//把pivot节点插入lessList的尾部，若lessList为空，以povit为表头
	if (lessList == NULL)
		*list = pivot;
	else
		lessListEnd->next = pivot;

	//在pivot的后面插入moreList
	pivot->next = moreList;

	//返回链表的尾节点
	if (moreList == NULL)
		return pivot;
	else return moreListEnd;
}