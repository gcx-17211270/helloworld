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
		//��Ԫ���
		SPNode data[MAXSIZE];
		//���е�һ������Ԫ�ص�λ�ñ�
		int rpos[RMAX + 1];
		//����������������ͷ���Ԫ�ظ���
		int mu, nu, tu;
	}RLSMatrix;

	//�����˻�C=A*B���������߼����Ӵ洢��ʾ
	int sm_mult(RLSMatrix A, RLSMatrix B, RLSMatrix C);
#ifdef __cpluscplus
}
#endif

#endif