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
		int row, col;			//�÷���Ԫ�ص��к����±�
		MatrixValue val;		//�÷���Ԫ�ص�ֵ
		struct OLNode* down, * right;	//�÷���Ԫ�������б���б�ĺ������
	}OLNode, * OLink;

	typedef struct OLMatrix
	{
		OLNode* rhead, * chead;
		int mu, nu, tu;
	}OLMatrix;

	//ִ�еĺ���
	void olMatrix_callback();

	OLink olnode_setValue(int i, int j, MatrixValue e);

	//����ʮ������
	OLMatrix olink_create(int mu, int nu, int tu);

	//ʮ���������,��ӽ���ھ���A��
	void olMatrix_add(OLMatrix A, OLMatrix B);

	//����ת��
	OL_SPMatrix olsm_transpose(OL_SPMatrix A);

	//�������
	OL_SPMatrix olsm_mult(OL_SPMatrix A, OL_SPMatrix B);

	//�������
	void olsm_print(OL_SPMatrix A);

#ifdef __cpluscplus
}
#endif

#endif
