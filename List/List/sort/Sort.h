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

	//��������
	//���뺯��compare_func�����Ƚ�ArrayList���������ݵĴ�С��ϵ,
	//���value1>= value2�򷵻�1�����򷵻�-1
	void insert_sort(StaticTable* p, ArrayListCompareFunc compare_func);

	//ϣ�����򣬡��㷨4����Java���룬��C����
	void shell_sort(StaticTable* p, int len);

	//ϣ������,�����ݽṹ��C���԰棩�������桢���������ϴ���
	void shell_sort_(StaticTable* p, int dlta[], int t);

	//һ������Ϊdk�Ĳ�������dkΪ��������
	void shell_insert(StaticTable* p, int dk, ArrayListCompareFunc compare_func);

	//��������
	//ð������
	void bubble_sort(StaticTable* p, ArrayListCompareFunc compare_func);

	//��������
	void quickSort(int* st, int lo, int hi);
	//��������Ļ���
	int partition(int* st, int lo, int hi);

	//��������
	//�ݹ���ʽ�Ŀ������򣬶�˳�����tbl->data[low��high]����������
	void quick_sort(StaticTable* tbl, int low, int high, ArrayListCompareFunc compare_func);
	//һ�˿����򣬽���˳���tbl���ӱ�tbl->data[low, low+1, ��, high]�ļ�¼ʹ֧���¼��λ�������������ڵ�λ�ã���ʱ����֮ǰ���󣩵ļ�¼������С������
	int arraylist_partition(ArrayList* arraylist, int low, int hi, ArrayListCompareFunc compare_func);

	//ѡ������
	void select_sort(StaticTable* s, ArrayListCompareFunc compare_func);

	//�鲢����p�Ǵ��������飬q�������ݵĿ������Ƕ��������飩��
	void mergeSort(int* p, int* q, int lo, int hi, int length);
	void merge(int* p, int* q, int lo, int mid, int hi, int length);

	//�鲢����(rf��һ����p�ȳ�������)
	void merge_sort(StaticTable* p, ArrayListValue* rf, ArrayListCompareFunc compare_func);
	void merge_(ArrayListValue* r, ArrayListValue* rf, int u, int v, int t, 
		ArrayListCompareFunc compare_func);


	void sort_callback();
#ifdef _cpluscplus
}
#endif

#endif