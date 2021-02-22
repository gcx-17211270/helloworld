/*****************************************************************//**
 * \file   tree.h
 * \brief  ����ADT
 * 
 * \author 32353
 * \date   November 2020-11-11 9:16 
 *********************************************************************/
#ifndef __TREE_H_HELLO_QIU__
#define __TREE_H_HELLO_QIU__

#define TREE_NULL ((void*)0)			//���Ŀ�ָ������
#define bool int
#define TRUE 1
#define FALSE 0

#ifdef _cpluscplus
extern "C"
{
#endif
	struct _Tree;
	struct _TreeNode;
	typedef struct _Tree Tree;			//���ṹ
	typedef struct _TreeNode TreeNode;	//���Ľڵ�
	typedef void* TreeValue;			//���ڵ��е�����

	typedef void* (*TreeDefinition)(Tree* T);	//���Ĺ��췽��
	typedef int (*TreeTraverseFunc)(void);	//���ı�����ʹ���ˣ�������ǰ�����򡢺���

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

	//�������
	Tree* tree_init(Tree* T);

	//������
	bool tree_destroy(Tree* T);

	//definition������T�Ķ��壬��definition������T
	Tree* tree_create(Tree* T, TreeDefinition definition);

	//�������
	bool tree_clear(Tree* T);

	//�ж����Ƿ�Ϊ����,���򷵻�TRUE�����򷵻�FALSE
	bool tree_empty(Tree T);

	//�������
	int tree_depth(Tree T);

	//���ĸ�
	Tree* tree_root(Tree* root);

	//����ĳ���ڵ��ֵ
	TreeValue tree_value(Tree* T, TreeNode* cur_e);

	//��valueֵ��������cur_e�ڵ�
	bool tree_assign(Tree* T, TreeNode* cur_e, TreeValue value);

	//��������ĳ���ڵ��˫�ף�������ֵΪ���ա�
	TreeNode* tree_parent(Tree* T, TreeNode* cur_e);

	//��������ĳ���ڵ��������
	TreeNode* tree_left_child(Tree* T, TreeNode* cur_e);

	//��������ĳ���ڵ�������ֵ�
	TreeNode* tree_right_sibling(Tree* T, TreeNode* cur_e);

	//����c������T��p�ڵ㴦��i��p�ڵ�������λ�ã�1<=i<=p�Ľڵ�ȶ�Ҫ��1
	bool tree_insert_child(Tree* T, TreeNode* p, unsigned int i, Tree* c);

	//��T��p�ڵ�ɾ����i��p�ڵ�������λ�ã�1<=i<=p�Ľڵ�ȶ�Ҫ��1
	bool tree_delete_child(Tree* T, TreeNode* p, unsigned int i);

	bool tree_traverse(Tree* T, TreeTraverseFunc visit());
#ifdef _cpluscplus
}
#endif

#endif