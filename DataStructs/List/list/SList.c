/**
* ���ݽṹ������
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
		//��һ���ڵ㻹û���룬���ѱ�������β����ǰ�������ĵط�
		iterator->current = *iterator->prev_next;
	}
	else {
		//��ǰ��������λ�õĽڵ���ڣ��������һ���ڵ�
		iterator->prev_next = &iterator->current->next;
		iterator->current = iterator->current->next;
	}

	//�жϵ�ǰ��������λ���Ƿ��ڱ�β
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

	/* ͨ��n�������㵽�������㣬����ȷ��û�дﵽ��β */

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

	//�����������2�������Ѿ��������
	if (*list == NULL || (*list)->next == NULL)
		return *list;

	//pivotָ��ͷ�ڵ�
	pivot = *list;

	//�ӵڶ����ڵ㿪ʼ������������ÿ���ڵ���ͷ�ڵ�ȽϵĽ�������ڵ����lessList��moreList������������
	lessList = NULL;
	moreList = NULL;
	rover = (*list)->next;
	while (rover != NULL)
	{
		SListEntry* next = rover->next;
		if (compare_func(rover->data, pivot->data) < 0)
		{
			//������ڵ����lessList��
			rover->next = lessList;
			lessList = rover;
		}
		else
		{
			//������ڵ����moreList��
			rover->next = moreList;
			moreList = rover;
		}
		rover = next;
	}

	//��������ݹ�����
	lessListEnd = slist_sort_internal(&lessList, compare_func);
	moreListEnd = slist_sort_internal(&moreList, compare_func);

	//������lessListΪ��ʼ����������
	*list = lessList;
	
	//��pivot�ڵ����lessList��β������lessListΪ�գ���povitΪ��ͷ
	if (lessList == NULL)
		*list = pivot;
	else
		lessListEnd->next = pivot;

	//��pivot�ĺ������moreList
	pivot->next = moreList;

	//���������β�ڵ�
	if (moreList == NULL)
		return pivot;
	else return moreListEnd;
}