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
	//ָ���������������͵�ָ��
	typedef void* ArrayListValue;

	//���嶯̬����ṹ
	typedef struct ArrayList ArrayList;

	struct ArrayList
	{
		//����ķ������
		ArrayListValue* data;
		//�������Ѵ洢���ݳ���
		unsigned int length;
		//�������󳤶�
		unsigned int _alloced;
	};

	//�Ƚ����������������Ƿ���ȣ���ȷ��ط�0ֵ�����򷵻�0
	typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
		ArrayListValue value2);

	//�Ƚ��������������ݣ�value1>value2�򷵻���ֵ����ȷ���0��С�ڷ��ظ�ֵ
	typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
		ArrayListValue value2);

	//��̬����ṹ��ʹ��������ʼ�����飬�����ʼ����������������
	//��̬������ڴ��С����length���������ֵ����ʹ��һ�������Ĭ�ϴ�С
	ArrayList* arraylist_new(unsigned int length);

	//���ٶ�̬���鲢���ͷ���ռ�õ��ڴ�
	void arraylist_free(ArrayList* arraylist);

	//�ڶ�̬�����β�����һ������
	int arraylist_append(ArrayList* arraylist, ArrayListValue data);

	//�ڶ�̬�����ͷ�����һ������
	int arraylist_prepend(ArrayList* arraylist, ArrayListValue data);

	//ɾ����̬������ָ���±�����ݣ�index�Ǳ�����������ڵ��±�
	void arraylist_remove(ArrayList* arraylist, unsigned int index);

	//�����̬��������index��ʼ������Ϊlengh������
	void arraylist_remove_range(ArrayList* arraylist, unsigned int index, unsigned int length);

	//��ָ�����±�λ�ò���һ�����ݣ��������±��ն�̬����Ĵ�С����
	int arraylist_insert(ArrayList* arraylist, unsigned int index, ArrayListValue data);

	//�ڶ�̬�������ҵ��ض����ݵ���С�±ꡣcallback���ڱȽ������е����������������
	int arraylist_index_of(ArrayList* arraylist, ArrayListEqualFunc callback, ArrayListValue data);

	//��ն�̬�����е�����
	void arraylist_clear(ArrayList* arraylist);

	//�Զ�̬�����������compare_func����������������Ƚ����ݵĺ���
	void arraylist_sort(ArrayList* arraylist, ArrayListCompareFunc compare_func);

	//�ڲ����򣨿������򷽷�ʵ�֣�
	static void arraylist_sort_internal(ArrayListValue* listData, unsigned int listlength,
		ArrayListCompareFunc compare_func);

	void ArrayList_callback();
#ifdef _cpluscplus
}
#endif
#endif