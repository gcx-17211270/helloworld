#ifndef __SORT_H_HELLO_QIU__
#define __SORT_H_HELLO_QIU__

#ifdef _cpluscplus
extern "C"
{
#endif
#include "../list/ArrayList.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0
	typedef ArrayList StaticTable;

	//插入排序
	//传入函数compare_func用来比较ArrayList中两个数据的大小关系,
	//如果value1>= value2则返回1，否则返回-1
	void insert_sort(StaticTable* p, ArrayListCompareFunc compare_func);

	//希尔排序，《算法4》上Java代码，用C描述
	void shell_sort(StaticTable* p, int len);

	//希尔排序,《数据结构（C语言版）》董树锋、郭创新书上代码
	void shell_sort_(StaticTable* p, int dlta[], int t);

	//一趟增量为dk的插入排序，dk为步长因子
	void shell_insert(StaticTable* p, int dk, ArrayListCompareFunc compare_func);

	//交换排序
	//冒泡排序
	void bubble_sort(StaticTable* p, ArrayListCompareFunc compare_func);

	//快速排序
	void quickSort(int* st, int lo, int hi);
	//快速排序的划分
	int partition(int* st, int lo, int hi);

	//快速排序
	//递归形式的快速排序，对顺序表中tbl->data[low…high]做快速排列
	void quick_sort(StaticTable* tbl, int low, int high, ArrayListCompareFunc compare_func);
	//一趟快排序，交换顺序表tbl中子表tbl->data[low, low+1, …, high]的记录使支点记录到位，并返回其所在的位置，此时在它之前（后）的记录均不大（小）于它
	int arraylist_partition(ArrayList* arraylist, int low, int hi, ArrayListCompareFunc compare_func);

	//选择排序
	void select_sort(StaticTable* s, ArrayListCompareFunc compare_func);

	//归并排序（p是待排序数组，q是它内容的拷贝（是独立的数组））
	void mergeSort(int* p, int* q, int lo, int hi, int length);
	void merge(int* p, int* q, int lo, int mid, int hi, int length);

	//归并排序(rf是一个与p等长的数组)
	void merge_sort(StaticTable* p, ArrayListValue* rf, ArrayListCompareFunc compare_func);
	void merge_(ArrayListValue* r, ArrayListValue* rf, int u, int v, int t, 
		ArrayListCompareFunc compare_func);


	void sort_callback();
#ifdef _cpluscplus
}
#endif

#endif