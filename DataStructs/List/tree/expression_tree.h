/*****************************************************************//**
 * \file   expression_tree.h
 * \brief  表达式树
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
	//构造表达式树
	bool create_expression_tree(BiTree* tree, BiTreeNode* parent, BiTreeNodeSide side, char* p, int l);

	//计算表达式树
	bool calculate(BiTreeNode* node, double* rst);

	//根据表达式，构造表达式树并计算表达式
	bool do_expression_calculate(char* exp, double* rst);

	void create_expression_tree_callback();
#ifdef _cpluscplus
}
#endif
#endif