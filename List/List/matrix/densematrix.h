#ifndef densematrix_h
#define densematrix_h

#include <stdio.h>
#include <stdlib.h>

#ifdef __cpluscplus
extern "C"
{
#endif 
	typedef double** DenseMatrix;
	
	//����һ������
	DenseMatrix dm_creat(int mu, int nu);

	//�Ѿ���B�ӵ�����A��
	void dm_plus(DenseMatrix A, DenseMatrix B, int mu, int nu);

	//����ת��
	DenseMatrix dm_transpose(DenseMatrix A, int mu, int nu);

	//����˷�
	DenseMatrix dm_mult(DenseMatrix A, DenseMatrix B, int amu, int bnu, int anu);
#ifdef __cpluscplus
}
#endif
#endif 