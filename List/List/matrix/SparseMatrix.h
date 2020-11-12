//ϡ������רְ�㷨
#ifndef __SPAREMATRIX_H_HELLO_QIU_
#define __SPAREMATRIX_H_HELLO_QIU_

#include "densematrix.h"
#include <stdlib.h>

//һ���㹻�������
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

	//��Ԫ���Ĵ洢����
	typedef struct SparseMatrix
	{
		//���������������������Ԫ�صĸ���
		int mu, nu, tu;
		SPNode data[MAXSIZE + 1];
	}SparseMatrix;

	//ϡ�����ת���㷨
	SparseMatrix* sm_transpose1(SparseMatrix* a);

	//ϡ�����ת���㷨�Ľ���������ת��
	SparseMatrix* sm_transpose2(SparseMatrix* a);
#ifdef __cplusplus
}
#endif

#endif