/*
* Ï¡Êè¾ØÕóµÄÑ¹Ëõ´æ´¢
* ÈýÔª×éË³Ðò±í´æ´¢
* author:	32353
* data:		2020.10.17 10:20
*/
#include "SparseMatrix.h"

SparseMatrix* sm_transpose1(SparseMatrix* a)
{
	SparseMatrix* b;
	int p, q, col;
	b = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	b->mu = a->mu;
	b->nu = a->nu;
	b->tu = a->tu;
	if (b->tu > 0)
	{
		q = 0;
		for (col = 1; col <= a->nu; col++)
			for (p = 1; p <= a->mu; p++)
				if (a->data[p].col == col)
				{
					b->data[q].row = a->data[p].col;
					b->data[q].col = a->data[p].row;
					b->data[q].val = a->data[p].val;
					q++;
				}
	}
	return b;
}

SparseMatrix* sm_transpose2(SparseMatrix* a)
{
	SparseMatrix* b;
	int i, j, k;
	int num[CMAX + 1], cpot[CMAX + 1];
	b = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	b->mu = a->mu;
	b->nu = a->nu;
	b->tu = a->tu;
	if (b->tu > 0)
	{
		for (i = 1; i <= a->nu; i++)
			num[i] = 0;
		for (i = 1; i <= a->tu; i++)
		{
			j = a->data[i].col;
			num[j]++;
		}
		cpot[1] = 1;
		for (i = 2; i <= a->nu; i++)
			cpot[i] = cpot[i - 1] + num[i - 1];
		for (i = 1; i <= a->tu; i++)
		{
			j = a->data[i].col;
			k = cpot[j];
			b->data[k].row = a->data[i].col;
			b->data[k].col = a->data[i].row;
			b->data[k].val = a->data[i].val;
			cpot[j]++;
		}
	}
	return b;
}
			