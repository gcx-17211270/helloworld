/*
* ʹ��˳������������ʽ�ĺ͡���
* ��ϰ��ʹ��������ʵ�֣���Ҫ�漰���ϲ�ͬ���
**/

#include "ADT.h"
#include <stdio.h>
#include <stdlib.h>

void polynomial_zero(ArrayList* poly) {
	unsigned int i;
	for (i = 0; i < poly->_alloced; i++)
		*((double*)(poly->data[i])) = 0;
	poly->length = 1;	//��ߴ���Ϊpoly->length-1 
}

void polynomial_add(ArrayList* poly1, ArrayList* poly2, ArrayList** polySum) {
	unsigned int i, l;
	//ȡpoly1��poly2��ߴ����Ľϴ���Ϊ��Ӻ����ߴ��� 
	l = poly1->length;
	if (poly2->length > poly1->length)
		l = poly2->length;
	*polySum = arraylist_new(l);
	//�����ڴ�ռ� 
	for (i = 0; i < (*polySum)->_alloced; i++)
		(*polySum)->data[i] = (double*)malloc(sizeof(double));
	polynomial_zero(*polySum);	//��ʼ�� 
	(*polySum)->length = l;

	for (i = 0; i < (*polySum)->length; i++)
		*(double*)((*polySum)->data[i]) = *(double*)(poly1->data[i]) + *(double*)(poly2->data[i]);
}

void polynomial_mult(ArrayList* poly1, ArrayList* poly2, ArrayList** polyMult) {
	unsigned int i, j, l;
	l = (poly1->length - 1) + (poly2->length - 1) + 1;	//poly1��poly2����ߴ���֮��Ϊ��˺����ߴ���
	(*polyMult) = arraylist_new(l);
	for (i = 0; i < (*polyMult)->_alloced; i++)
		(*polyMult)->data[i] = (double*)malloc(sizeof(double));
	polynomial_zero(*polyMult);
	(*polyMult)->length = l;

	for (i = 0; i < poly1->length; i++)
		for (j = 0; j < poly2->length; j++)
			*(double*)((*polyMult)->data[i + j]) += *(double*)(poly1->data[i]) * *(double*)(poly2->data[j]);
}

void ADT_callback()
{
	unsigned int i;
	ArrayList* poly1, * poly2, * poly;
	poly1 = arraylist_new(10);
	poly2 = arraylist_new(10);
	for (i = 0; i < poly1->_alloced; i++) {
		poly1->data[i] = (double*)malloc(sizeof(double));
		poly2->data[i] = (double*)malloc(sizeof(double));
	}
	polynomial_zero(poly1);
	polynomial_zero(poly2);
	poly1->length = 10;
	poly2->length = 10;
	*(double*)(poly1->data[0]) = 3;
	*(double*)(poly1->data[1]) = 2;
	*(double*)(poly1->data[2]) = 1;
	*(double*)(poly1->data[3]) = 0;
	*(double*)(poly1->data[4]) = 4;
	*(double*)(poly1->data[5]) = 5;
	*(double*)(poly1->data[6]) = 6;
	*(double*)(poly1->data[7]) = 7;
	*(double*)(poly1->data[8]) = 8;
	*(double*)(poly1->data[9]) = 9;
	*(double*)(poly2->data[0]) = 4;
	*(double*)(poly2->data[1]) = 5;
	*(double*)(poly2->data[2]) = 1;
	*(double*)(poly2->data[3]) = 3;
	*(double*)(poly2->data[4]) = 7;
	*(double*)(poly2->data[5]) = 6;
	*(double*)(poly2->data[6]) = 8;
	*(double*)(poly2->data[7]) = 9;
	*(double*)(poly2->data[8]) = 2;
	*(double*)(poly2->data[9]) = 0;
	polynomial_add(poly1, poly2, &poly);
	for (i = 0; i < poly->length; i++)
		printf("%.1f  ", *(double*)(poly->data[i]));
	printf("\n");
	polynomial_mult(poly1, poly2, &poly);
	for (i = 0; i < poly->length; i++)
	{
		if (i == 10)
			printf("\n");
		printf("%.1f  ", *(double*)(poly->data[i]));
	}
}