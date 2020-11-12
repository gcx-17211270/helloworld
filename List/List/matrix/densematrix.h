#ifndef densematrix_h
#define densematrix_h

#include <stdio.h>
#include <stdlib.h>

#ifdef __cpluscplus
extern "C"
{
#endif 
	typedef double** DenseMatrix;
	
	//创建一个矩阵
	DenseMatrix dm_creat(int mu, int nu);

	//把矩阵B加到矩阵A上
	void dm_plus(DenseMatrix A, DenseMatrix B, int mu, int nu);

	//矩阵转置
	DenseMatrix dm_transpose(DenseMatrix A, int mu, int nu);

	//矩阵乘法
	DenseMatrix dm_mult(DenseMatrix A, DenseMatrix B, int amu, int bnu, int anu);
#ifdef __cpluscplus
}
#endif
#endif 