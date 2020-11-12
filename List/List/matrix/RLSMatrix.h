#ifndef __RLSMATRIX_H_HELLO_QIU__
#define __RLSMATRIX_H_HELLO_QIU__

#include "SparseMatrix.h"
#define RMAX CMAX
#define SMax RMAX

#ifdef __cpluscplus
extern "C"
{
#endif
	typedef struct RLSMatrix
	{
		//三元组表
		SPNode data[MAXSIZE];
		//各行第一个非零元素的位置表
		int rpos[RMAX + 1];
		//矩阵的行数、列数和非零元素个数
		int mu, nu, tu;
	}RLSMatrix;

	//求矩阵乘积C=A*B，采用行逻辑链接存储表示
	int sm_mult(RLSMatrix A, RLSMatrix B, RLSMatrix C);
#ifdef __cpluscplus
}
#endif

#endif