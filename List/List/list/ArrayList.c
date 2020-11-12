/*
* ���ݽṹ��˳���
**/

#include "ArrayList.h"

ArrayList* arraylist_new(unsigned int length)
{
	ArrayList* new_arraylist;
	if (length <= 0)
		length = MIN_LENGTH;
	new_arraylist = (ArrayList*)malloc(sizeof(ArrayList));
	if (new_arraylist == NULL)
		return NULL;
	new_arraylist->_alloced = length;
	new_arraylist->length = 0;
	/*��data�����ڴ��ַ*/
	new_arraylist->data = malloc(length * sizeof(ArrayListValue));
	if (new_arraylist->data == NULL)
	{
		free(new_arraylist);
		new_arraylist = NULL;
		return NULL;
	}
	return new_arraylist;
}

void arraylist_free(ArrayList* arraylist)
{
	if (arraylist != NULL)
	{
		free(arraylist->data);
		arraylist->data = NULL;
		free(arraylist);
		arraylist = NULL;
	}
}

//��̬���鳤������
static int arraylist_enlarge(ArrayList* arraylist)
{
	ArrayListValue* data;
	unsigned int newSize;
	newSize = arraylist->_alloced * 2;
	data = realloc(arraylist->data, sizeof(ArrayListValue) * newSize);
	if (data == NULL)
		return 0;
	arraylist->data = data;
	arraylist->_alloced = newSize;
	return 1;
}
//��̬���鳤����С
static int arraylist_delarge(ArrayList* arraylist)
{
	ArrayListValue* data;
	unsigned int newSize;
	newSize = arraylist->_alloced / 2;
	data = realloc(arraylist->data, sizeof(ArrayListValue) * newSize);
	if (data == NULL)
		return 0;
	arraylist->data = data;
	arraylist->_alloced = newSize;
	return 1;
}

int arraylist_insert(ArrayList* arraylist, unsigned int index, ArrayListValue data)
{
	//����±��Ƿ�Խ��
	if (index > arraylist->length)
		return 0;
	//��Ҫʱ�������鳤��
	if (arraylist->length + 1 > arraylist->_alloced)
		if (!arraylist_enlarge(arraylist))
			return 0;
	/*�Ѵ�����λ�ü�֮����������ݺ���һλ*/
	memmove(&arraylist->data[index + 1], &arraylist->data[index],
		(arraylist->length - index) * sizeof(ArrayListValue));
	arraylist->data[index] = data;
	++arraylist->length;
	return 1;
}

int arraylist_append(ArrayList* arraylist, ArrayListValue data)
{
	return arraylist_insert(arraylist, arraylist->length, data);
}

int arraylist_prepend(ArrayList* arraylist, ArrayListValue data)
{
	return arraylist_insert(arraylist, 0, data);
}

void arraylist_remove_range(ArrayList* arraylist, unsigned int index, unsigned int length)
{
	if (index > arraylist->length || index + length > arraylist->length)
		return;
	/*���Ƴ���Χ֮�����������ǰ��*/
	memmove(&arraylist->data[index], &arraylist->data[index + length],
		(arraylist->length - (index + length)) * sizeof(ArrayListValue));
	arraylist->length -= length;
	if (arraylist->_alloced > 2 * arraylist->length)
		arraylist_delarge(arraylist);
}

void arraylist_remove(ArrayList* arraylist, unsigned int index)
{
	arraylist_remove_range(arraylist, index, 1);
}

int arraylist_index_of(ArrayList* arraylist, ArrayListEqualFunc callback,
	ArrayListValue data)
{
	unsigned int i;
	for (i = 0; i < arraylist->length; ++i)
		if (callback(arraylist->data[i], data) != 0)
			return (int) i;
	return -1;
}

void arraylist_clear(ArrayList* arraylist)
{
	arraylist->length = 0;
}

void arraylist_sort(ArrayList* arraylist, ArrayListCompareFunc compare_func)
{
	arraylist_sort_internal(arraylist->data, arraylist->length, compare_func);
}

static void arraylist_sort_internal(ArrayListValue* listData, unsigned int listLength,
	ArrayListCompareFunc compare_func)
{
	ArrayListValue pivot;
	ArrayListValue tmp;
	unsigned int i;
	unsigned int list1Length;
	unsigned int list2Length;

	//�����������2���������������
	if (listLength <= 1)
		return;

	//�����һ�����ݸ�ֵ��pivot
	pivot = listData[listLength - 1];

	//�������Ϊ���飬List1����С��pivot�����飬List2��������pivot������
	//�����齨��֮��������������˳������
	list1Length = 0;
	for (i = 0; i < listLength - 1; ++i)
	{
		if (compare_func(listData[i], pivot) < 0)
		{
			//����Ӧ��list1�У������䴦�ڴ����λ�ã�����������list1���һ����л���
			tmp = listData[i];
			listData[i] = listData[list1Length];
			listData[list1Length] = tmp;
			++list1Length;
		}
		else
		{
			//����Ӧ��list2�У���������λ����ȷ��λ��
		}
		list2Length = listLength - list1Length - 1;

		//listData[0,,,list1Length-1]����������С��pivot������
		//listData[list1Length,,,listLength-2]���������д���pivot������
		//ͨ������pivot��list2�ĵ�һ�����ݣ���pivot������ȷ��λ��
		listData[listLength - 1] = listData[list1Length];
		listData[list1Length] = pivot;

		//ʹ�õݹ��������
		arraylist_sort_internal(listData, list1Length, compare_func);
		arraylist_sort_internal(listData + list1Length + 1, list2Length, compare_func);
	}
}

/*��˳���Ĳ�����������ʼ������ֵ���鿴���ͷ��ڴ�*/
void ArrayList_callback()
{
	ArrayList* arraylist;
	arraylist = arraylist_new(0);
	if (!arraylist)
	{
		printf("Failed!\n");
		exit(0);
	}
	printf("row:14\n");
	for (unsigned int i = 0; i < (arraylist->_alloced); i++)
	{
		arraylist->data[i] = i;
		arraylist->length++;
		printf("%p \n", (arraylist->data[i]));
	}

	//�Ǹ�Compare������ôʵ�ֵİ���
	//printf("%d\n", arraylist_index_of(arraylist, , 3));

	arraylist_free(arraylist);
	return;
}