#ifndef __HELLO_ARRAYLIST_QIU_
#define __HELLO_ARRAYLIST_QIU_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MIN_LENGTH 5

#ifdef _cpluscplus
extern "C"
{
#endif
	//指向数组中数据类型的指针
	typedef void* ArrayListValue;

	//定义动态数组结构
	typedef struct ArrayList ArrayList;

	struct ArrayList
	{
		//数组的访问入口
		ArrayListValue* data;
		//数组中已存储数据长度
		unsigned int length;
		//数组的最大长度
		unsigned int _alloced;
	};

	//比较数组中两个数据是否相等，相等返回非0值，否则返回0
	typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
		ArrayListValue value2);

	//比较数组中两个数据，value1>value2则返回正值，相等返回0，小于返回负值
	typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
		ArrayListValue value2);

	//动态数组结构，使用它来初始化数组，传入初始化函数是最初分配给
	//动态数组的内存大小，若length被赋予零或负值，则使用一个合理的默认大小
	ArrayList* arraylist_new(unsigned int length);

	//销毁动态数组并且释放其占用的内存
	void arraylist_free(ArrayList* arraylist);

	//在动态数组的尾部添加一个数据
	int arraylist_append(ArrayList* arraylist, ArrayListValue data);

	//在动态数组的头部添加一个数据
	int arraylist_prepend(ArrayList* arraylist, ArrayListValue data);

	//删除动态数组中指定下标的内容，index是被清除内容所在的下标
	void arraylist_remove(ArrayList* arraylist, unsigned int index);

	//清除动态数组中以index开始，长度为lengh的内容
	void arraylist_remove_range(ArrayList* arraylist, unsigned int index, unsigned int length);

	//在指定的下标位置插入一个数据，插入点的下标收动态数组的大小限制
	int arraylist_insert(ArrayList* arraylist, unsigned int index, ArrayListValue data);

	//在动态数组中找到特定数据的最小下标。callback用于比较数组中的数据与待搜索数据
	int arraylist_index_of(ArrayList* arraylist, ArrayListEqualFunc callback, ArrayListValue data);

	//清空动态数组中的内容
	void arraylist_clear(ArrayList* arraylist);

	//对动态数组进行排序。compare_func是排序过程中用来比较数据的函数
	void arraylist_sort(ArrayList* arraylist, ArrayListCompareFunc compare_func);

	//内部排序（快速排序方法实现）
	static void arraylist_sort_internal(ArrayListValue* listData, unsigned int listlength,
		ArrayListCompareFunc compare_func);

	void ArrayList_callback();
#ifdef _cpluscplus
}
#endif
#endif