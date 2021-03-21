/*****************************************************************//**
 * \file   BiTree.h
 * \brief  二叉树的ADT
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

#define BITREE_NULL ((void*)0)					//二叉树的空指针数据
#define MAXNODE 100								//假设二叉树最多有100个节点（用于遍历时栈的大小设定）

#ifdef _cpluscplus
extern "C"
{
#endif
	//二叉树的左、右孩子标记
	typedef enum
	{
		BITREE_NODE_LEFT = 0,
		BITREE_NODE_RIGHT = 1
	}BiTreeNodeSide;

	typedef struct _BiTree BiTree;				//二叉树结构
	typedef struct _BiTreeNode BiTreeNode;		//二叉树节点
	typedef void* BiTreeValue;					//二叉树的节点数据

	typedef BiTreeValue (*BiTreeVisitFunc)(BiTreeNode* node);

	struct _BiTreeNode
	{
		BiTreeNode* children[2];
		BiTreeNode* parent;
		BiTreeValue value;
	};

	struct _BiTree
	{
		BiTreeNode* rootnode;						//根节点
		unsigned int nodenum;						//节点数
	};

	//二叉树的后序遍历非递归算法中使用的数据结构，因为后序遍历一个节点要入、出栈两次
	typedef struct
	{
		BiTreeNode* link;
		//标志位，只有第二次出栈，节点才可以访问
		int flag;									
	}stacktype;

	//删除树中一棵子树
	void bitree_remove_subtree(BiTree* tree, BiTreeNode* node);

	//销毁一个二叉树
	void bitree_free(BiTree* tree);

	//给定双亲结点和左右的位置，插入一个节点
	BiTreeNode* bitree_insert(BiTree* tree, BiTreeValue value, BiTreeNode* parent, BiTreeNodeSide side);

	//删除一个节点
	void bitree_remove(BiTree* tree, BiTreeNode* node);

	//查找二叉树的根节点
	BiTreeNode* bitree_rootnode(BiTree* tree);

	//获得给定节点中的数据
	BiTreeValue bitree_node_value(BiTreeNode* node);

	//查找给定节点的孩子节点
	BiTreeNode* bitree_node_child(BiTreeNode* node, BiTreeNodeSide side);

	//查找给定节点的双亲结点
	BiTreeNode* bitree_node_parent(BiTreeNode* node);

	//建立一棵新的二叉树
	BiTree* bitree_new();

	//前序遍历二叉树
	bool bitree_pre_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//中序遍历二叉树
	bool bitree_in_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//后序遍历二叉树
	bool bitree_post_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//层次遍历二叉树(原理没问题了，就是程序报错)
	void bitree_level_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//前序遍历的非递归算法
	void bitree_nrpre_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//中序遍历的非递归算法
	void bitree_nrin_order(BiTreeNode* node, BiTreeVisitFunc visit);

	//后序遍历的非递归算法
	void bitree_nrpost_order(BiTreeNode* node, BiTreeVisitFunc visit);
#ifdef _cpluscplus
}
#endif

#endif