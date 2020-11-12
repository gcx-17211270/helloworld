#ifndef __OLMATRIX_H_HELLO_QIU__
#define __OLMATRIX_H_HELLO_QIU__

#include <stdio.h>
#include <stdlib.h>
#define OL_SPMatrix OLMatrix
#define ElementType MatrixValue

#ifdef __cpluscplus
extern "C"
{
#endif
	typedef double MatrixValue;

	typedef struct OLNode
	{
		int row, col;			//该非零元素的行和列下标
		MatrixValue val;		//该非零元素的值
		struct OLNode* down, * right;	//该非零元素所在行表和列表的后继链域
	}OLNode, * OLink;

	typedef struct OLMatrix
	{
		OLNode* rhead, * chead;
		int mu, nu, tu;
	}OLMatrix;

	//执行的函数
	void olMatrix_callback();

	OLink olnode_setValue(int i, int j, MatrixValue e);

	//创立十字链表
	OLMatrix olink_create(int mu, int nu, int tu);

	//十字链表相加,相加结果在矩阵A中
	void olMatrix_add(OLMatrix A, OLMatrix B);

	//矩阵转置
	OL_SPMatrix olsm_transpose(OL_SPMatrix A);

	//矩阵相乘
	OL_SPMatrix olsm_mult(OL_SPMatrix A, OL_SPMatrix B);

	//输出矩阵
	void olsm_print(OL_SPMatrix A);

#ifdef __cpluscplus
}
#endif

#endif
