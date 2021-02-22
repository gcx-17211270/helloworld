/*****************************************************************//**
 * \file   tree.h
 * \brief  树的ADT
 * 
 * \author 32353
 * \date   November 2020-11-11 9:16 
 *********************************************************************/
#ifndef __TREE_H_HELLO_QIU__
#define __TREE_H_HELLO_QIU__

#define TREE_NULL ((void*)0)			//树的空指针数据
#define bool int
#define TRUE 1
#define FALSE 0

#ifdef _cpluscplus
extern "C"
{
#endif
	struct _Tree;
	struct _TreeNode;
	typedef struct _Tree Tree;			//树结构
	typedef struct _TreeNode TreeNode;	//树的节点
	typedef void* TreeValue;			//树节点中的数据

	typedef void* (*TreeDefinition)(Tree* T);	//树的构造方法
	typedef int (*TreeTraverseFunc)(void);	//树的遍历中使用了，具体如前序、中序、后序

	struct _TreeNode
	{
		TreeValue value;
		TreeNode* firstchild;
		TreeNode* nextsibling;
	};

	struct _Tree
	{
		TreeNode* rootnode;
		unsigned int nodenum;
	};

	//构造空树
	Tree* tree_init(Tree* T);

	//销毁树
	bool tree_destroy(Tree* T);

	//definition给出树T的定义，按definition构造树T
	Tree* tree_create(Tree* T, TreeDefinition definition);

	//将树清空
	bool tree_clear(Tree* T);

	//判断树是否为空树,空则返回TRUE，否则返回FALSE
	bool tree_empty(Tree T);

	//树的深度
	int tree_depth(Tree T);

	//树的根
	Tree* tree_root(Tree* root);

	//树中某个节点的值
	TreeValue tree_value(Tree* T, TreeNode* cur_e);

	//将value值赋给书中cur_e节点
	bool tree_assign(Tree* T, TreeNode* cur_e, TreeValue value);

	//返回树中某个节点的双亲，否则函数值为“空”
	TreeNode* tree_parent(Tree* T, TreeNode* cur_e);

	//返回树中某个节点的最左孩子
	TreeNode* tree_left_child(Tree* T, TreeNode* cur_e);

	//返回树中某个节点的最右兄弟
	TreeNode* tree_right_sibling(Tree* T, TreeNode* cur_e);

	//将树c插入树T中p节点处，i是p节点在树中位置，1<=i<=p的节点度都要加1
	bool tree_insert_child(Tree* T, TreeNode* p, unsigned int i, Tree* c);

	//树T中p节点删除，i是p节点在树中位置，1<=i<=p的节点度都要减1
	bool tree_delete_child(Tree* T, TreeNode* p, unsigned int i);

	bool tree_traverse(Tree* T, TreeTraverseFunc visit());
#ifdef _cpluscplus
}
#endif

#endif