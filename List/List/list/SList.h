#ifndef __HELLO_SLIST_QIU_
#define __HELLO_SLIST_QIU_

//�������������ݵĿ�ָ��
#define SLIST_NULL ((void*) 0)

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

	//��������ṹ
	typedef struct _SListEntry SListEntry;
	//����������ṹ�����ڱ�������
	typedef struct _SListInterator SListIterator;

	//ָ�������д洢�����ݵ�ָ��
	typedef void* SListValue;

	//�����ж�����ֵ�Ƿ���ȵ���������
	typedef int (*SListEqualFunc)(SListValue value1, SListValue value2);
	//������ʱ�Ƚ����������ڵ����ݵ�����
	typedef int (*SListCompareFunc)(SListValue value1, SListValue value2);

	//������Ľڵ�ṹ
	struct _SListEntry
	{
		SListValue data;
		SListEntry* next;
	};

	//��������������ṹ
	struct _SListInterator
	{
		SListEntry** prev_next;
		SListEntry* current;
	};

//�ж������Ƿ�Ϊ�գ��ձ���1
	int slist_is_empty(SListEntry* list);

	//�ж�listentry�Ƿ�Ϊ�������һ���ڵ㣬������򷵻�1
	int slist_is_last(SListEntry* listentry);

	//ɾ�����ͷ��ڴ�
	void slist_free(SListEntry* list);

	//����½ڵ㵽ͷ��������ָ���½ڵ��ָ��
	SListEntry* slist_prepend(SListEntry** list, SListValue data);

	//����½ڵ㵽β��������ָ���½ڵ��ָ��
	SListEntry* slist_append(SListEntry** list, SListValue data);

	//��������иýڵ����һ���ڵ�
	SListEntry* slist_next(SListEntry* listentry);

	//��ýڵ��д洢������
	SListValue slist_data(SListEntry* listentry);

	//�������ĳ���
	unsigned int slist_length(SListEntry* list);

	//Ѱ���ض��ڵ��ǰ���ڵ㣬����ҵ�����ǰ���ڵ㣬���򷵻�β�ڵ�
	SListEntry* slist_find_previous(SListEntry** list, SListEntry* listentry);

	//���������Ƴ�һ���ڵ㣬�ҵ����Ƴ��󷵻�1�����򷵻�0
	int slist_remove_entry(SListEntry** list, SListEntry* entry);

	//�������в���һ���ڵ�
	SListEntry* slist_insert(SListEntry** list, SListEntry* listentry, SListValue data);

	//�õ�ָ���n���ڵ��ָ�룬�������к�Ϊn�Ľڵ�ָ�룬�����ų�����Χ�򷵻�NULL
	SListEntry* slist_nth_entry(SListEntry* list, unsigned int n);

	//��ȡ��n���ڵ�����ݣ����ʧ���򷵻�SLIST_NULL;
	SListValue slist_nth_data(SListEntry* list, unsigned int n);

	//����һ���������������ݵ����飬�����½������飬�ڴ�����ʧ���򷵻�NULL�����鳤�����������
	SListValue* slist_to_array(SListEntry* list);

	//���Ҿ����ض����ݵĽڵ㣬�����ҵ��ĵ�һ���ڵ㣬��δ�ҵ��򷵻�NULL
	////Callback�������ڱȽϱ�����������������Ƿ����
	//SListEntry* slist_find_data(SListEntry* list, SListEqualFunc callback, SListValue data);

	//��ʼ��һ����������������ڱ�����������ָ���ʼ���������������ָ��
	void slist_interator(SListEntry** list, SListIterator* iter);

	//�ж��������Ƿ��и������ݴ�������iteratorΪ�����������û���򷵻�0�����򷵻ط�����
	int slist_iter_has_more(SListIterator* iterator);

	//�������������ȡ�����е���һ���ڵ�
	SListValue slist_iter_next(SListIterator* iterator);

	//ɾ����ǰ��������λ�õĽڵ�
	void slist_iter_remove(SListIterator* iterator);

	void slist_sort(SListEntry** list, SListCompareFunc compare_func);

	//�����ڲ���������ĺ���������������β�ڵ�
	static SListEntry* slist_sort_internal(SListEntry** list, SListCompareFunc compare_func);
	
#ifdef __cpluscplus
}
#endif

#endif