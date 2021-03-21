#include "BinHeap.h"

#define minPQSize 0
#define minData 0.001
#define Error printf
#define FatalError printf

PriorityQueue initialize(int maxElements)
{
	PriorityQueue H;
	//�ж����ȶ��г����Ƿ����
	if (maxElements < minPQSize)
		Error("Priority queue size is too small");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		FatalError("Out of space");

	H->elements = (ElementType*)malloc((maxElements + 1) * sizeof(ElementType));
	if (H->elements == NULL)
		FatalError("Out of space");
	H->capacity = maxElements;
	H->size = 0;
	H->elements[0] = minData;

	return H;
}

void destroy(PriorityQueue H)
{
	free(H->elements);
	free(H);
}

void insert(ElementType data, PriorityQueue H)
{
	int i;
	//�ж����ȶ����Ƿ�����
	if (is_full(H)) {
		Error("Priority queue is full.");
		return;
	}
	//���ȶ��в������
	for (i = ++H->size; H->elements[i / 2] > data; i /= 2)
	{
		H->elements[i] = H->elements[i / 2];
		H->elements[i] = data;
	}
}

ElementType delete_min(PriorityQueue H)
{
	int i, child;
	ElementType minElement, lastElement;

	//�ж϶����Ƿ�Ϊ�գ���ʽ����������ڴ����
	if (is_empty(H)) {
		Error("Priority queue is empty");
		return H->elements[0];
	}

	minElement = H->elements[1];
	lastElement = H->elements[H->size];
	H->size--;
	//�����ȶ����в�����СԪ�أ�ɾ���󷵻�
	for (i = 1; i * 2 <= H->size; i = child)
	{
		child = i * 2;
		if (child != H->size && H->elements[child + 1] < H->elements[child])
			child++;
		if (lastElement > H->elements[child])
			H->elements[i] = H->elements[child];
		else
			break;
	}
	H->elements[i] = lastElement;

	return minElement;
}

ElementType fine_min(PriorityQueue H)
{
	return H->elements[1];
}

BOOL is_empty(PriorityQueue H)
{
	return H->size == 0;
}

BOOL is_full(PriorityQueue H)
{
	return H->capacity == H->size;
}
