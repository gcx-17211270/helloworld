/*****************************************************************//**
 * \file   expression_tree.h
 * \brief  ���ʽ��
 * 
 * \author 32353
 * \date   November 2020-11-11 __TIME__ 
 *********************************************************************/
#ifndef __EXPRESSION_TREE_H_HELLO_QIU__
#define __EXPRESSION_TREE_H_HELLO_QIU__

#include "BiTree.h"

#ifdef _cpluscplus
extern "C"
{
#endif 
	//������ʽ��
	bool create_expression_tree(BiTree* tree, BiTreeNode* parent, BiTreeNodeSide side, char* p, int l);

	//������ʽ��
	bool calculate(BiTreeNode* node, double* rst);

	//���ݱ��ʽ��������ʽ����������ʽ
	bool do_expression_calculate(char* exp, double* rst);

	void create_expression_tree_callback();
#ifdef _cpluscplus
}
#endif
#endif