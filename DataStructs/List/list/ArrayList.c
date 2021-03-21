/*
* 数据结构：顺序表
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
	/*给data分配内存地址*/
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

//动态数组长度扩充
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
//动态数组长度缩小
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
	//检查下标是否越界
	if (index > arraylist->length)
		return 0;
	//必要时扩充数组长度
	if (arraylist->length + 1 > arraylist->_alloced)
		if (!arraylist_enlarge(arraylist))
			return 0;
	/*把待插入位置及之后的数组内容后移一位*/
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
	/*把移除范围之后的数组内容前移*/
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

	//如果数据少于2个，则已完成排序
	if (listLength <= 1)
		return;

	//将最后一个数据赋值给pivot
	pivot = listData[listLength - 1];

	//将数组分为两组，List1包含小于pivot的数组，List2包含大于pivot的数据
	//两个组建立之后，他们在数组中顺序排列
	list1Length = 0;
	for (i = 0; i < listLength - 1; ++i)
	{
		if (compare_func(listData[i], pivot) < 0)
		{
			//数据应在list1中，所以其处于错误的位置，将此数据与list1最后一项进行互换
			tmp = listData[i];
			listData[i] = listData[list1Length];
			listData[list1Length] = tmp;
			++list1Length;
		}
		else
		{
			//数据应在list2中，所以其已位于正确的位置
		}
		list2Length = listLength - list1Length - 1;

		//listData[0,,,list1Length-1]包含了所有小于pivot的数据
		//listData[list1Length,,,listLength-2]包含了所有大于pivot的数据
		//通过互换pivot与list2的第一个数据，将pivot移至正确的位置
		listData[listLength - 1] = listData[list1Length];
		listData[list1Length] = pivot;

		//使用递归进行排序
		arraylist_sort_internal(listData, list1Length, compare_func);
		arraylist_sort_internal(listData + list1Length + 1, list2Length, compare_func);
	}
}

/*对顺序表的操作，包括初始化、赋值、查看、释放内存*/
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

	//那个Compare函数怎么实现的啊？
	//printf("%d\n", arraylist_index_of(arraylist, , 3));

	arraylist_free(arraylist);
	return;
}