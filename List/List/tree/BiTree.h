/*****************************************************************//**
 * \file   BiTree.h
 * \brief  ��������ADT
 * 
 * \author 32353
 * \date   November 2020-11-11 11:17 
 *********************************************************************/
#ifndef __BINARY_TREE_HELLO_QIU__
#define __BINARY_TREE_HELLO_QIU__

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../list/seqqueue.h"
#include "../list/seqstack.h"

#define BITREE_NULL ((void*)0)					//�������Ŀ�ָ������
#define MAXNODE 100								//��������������100���ڵ㣨���ڱ���ʱջ�Ĵ�С�趨��

#ifdef _cpluscplus
extern "C"
{
#endif
	//�����������Һ��ӱ��
	typedef enum
	{
		BITREE_NODE_LEFT = 0,
		BITREE_NODE_RIGHT = 1
	}BiTreeNodeSide;

	typedef struct _BiTree BiTree;				//�������ṹ
	typedef struct _BiTreeNode BiTreeNode;		//�������ڵ�
	typedef void* BiTreeValue;					//�������Ľڵ�����

	typedef BiTreeValue (*BiTreeVisitFunc)(BiTreeNode* node);

	struct _BiTreeNode
	{
		BiTreeNode* children[2];
		BiTreeNode* parent;
		BiTreeValue value;
	};

	struct _BiTree
	{
		BiTreeNode* rootnode;						//���ڵ�
		unsigned int nodenum;						//�ڵ���
	};

	//�������ĺ�������ǵݹ��㷨��ʹ�õ����ݽṹ����Ϊ�������һ���ڵ�Ҫ�롢��ջ����
	typedef struct
	{
		BiTreeNode* link;
		//��־λ��ֻ�еڶ��γ�ջ���ڵ�ſ��Է���
		int flag;									
	}stacktype;

	//ɾ������һ������
	void bitree_remove_subtree(BiTree* tree, BiTreeNode* node);

	//����һ��������
	void bitree_free(BiTree* tree);

	//����˫�׽������ҵ�λ�ã�����һ���ڵ�
	BiTreeNode* bitree_insert(BiTree* tree, BiTreeValue value, BiTreeNode* parent, BiTreeNodeSide side);

	//ɾ��һ���ڵ�
	void bitree_remove(BiTree* tree, BiTreeNode* node);

	//���Ҷ������ĸ��ڵ�
	BiTreeNode* bitree_rootnode(BiTree* tree);

	//��ø����ڵ��е�����
	BiTreeValue bitree_node_value(BiTreeNode* node);

	//���Ҹ����ڵ�ĺ��ӽڵ�
	BiTreeNode* bitree_node_child(BiTreeNode* node, BiTreeNodeSide side);

	//���Ҹ����ڵ��˫�׽��
	BiTreeNode* bitree_node_parent(BiTreeNode* node);

	//����һ���µĶ�����
	BiTree* bitree_new();

	//ǰ�����������
	bool bitree_pre_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//�������������
	bool bitree_in_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//�������������
	bool bitree_post_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//��α���������(ԭ��û�����ˣ����ǳ��򱨴�)
	void bitree_level_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//ǰ������ķǵݹ��㷨
	void bitree_nrpre_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//��������ķǵݹ��㷨
	void bitree_nrin_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//��������ķǵݹ��㷨
	void bitree_nrpost_order(BiTreeNode* node, BiTreeVisitFunc visit);
#ifdef _cpluscplus
}
#endif

#endif