//稀疏矩阵的专职算法
#ifndef __SPAREMATRIX_H_HELLO_QIU_
#define __SPAREMATRIX_H_HELLO_QIU_

#include "densematrix.h"
#include <stdlib.h>

//一个足够大的数组
#define MAXSIZE 1024
#define CMAX 512

#ifdef __cplusplus
extern "C"
{
#endif

	typedef double MatrixValue;

	typedef struct SPNode
	{
		int row, col;
		MatrixValue val;
	}SPNode;

	//三元组表的存储类型
	typedef struct SparseMatrix
	{
		//矩阵的行数、列数、非零元素的个数
		int mu, nu, tu;
		SPNode data[MAXSIZE + 1];
	}SparseMatrix;

	//稀疏矩阵转置算法
	SparseMatrix* sm_transpose1(SparseMatrix* a);

	//稀疏矩阵转置算法改进——快速转置
	SparseMatrix* sm_transpose2(SparseMatrix* a);
#ifdef __cplusplus
}
#endif

#endif