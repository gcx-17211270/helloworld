/**
* 数据结构：密矩阵
* author : 32353
* data: 2020.10.14 20:35
*/

#include "densematrix.h"

DenseMatrix dm_creat(int mu, int nu)
{
	int i;
	DenseMatrix A = (double**)malloc(sizeof(double*) * (mu + 1));
	for (i = 1; i <= mu; i++)
		A[i] = (double*)malloc(sizeof(double) * (nu + 1));
	return A;
}

void dm_plus(DenseMatrix A, DenseMatrix B, int mu, int nu)
{
	int i, j;
	for (i = 1; i <= mu; i++)
		for (j = 1; j <= nu; j++)
			A[i][j] += B[i][j];
}

DenseMatrix dm_transpose(DenseMatrix A, int mu, int nu)
{
	int i, j;
	DenseMatrix T = dm_creat(mu, nu);
	for (i = 1; i <= mu; i++)
		for (j = 1; j <= nu; j++)
			T[i][j] = A[j][i];
	return T;
}

DenseMatrix dm_mult(DenseMatrix A, DenseMatrix B, int amu, int bnu, int anu)
{
	int i, j, k;
	DenseMatrix C = dm_creat(amu, bnu);
	for (i = 1; i <= amu; i++)
		for (j = 1; j <= bnu; j++)
		{
			C[i][j] = 0;
			for (k = 1; k <= anu; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	return C;
}