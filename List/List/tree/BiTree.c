/*****************************************************************//**
 * \file   BiTree.c
 * \brief  二叉树的实现
 *
 * \author 32353
 * \date   November 2020-11-11 11:17
 *********************************************************************/
#include "BiTree.h"

BiTreeNodeSide b = BITREE_NODE_LEFT;

BiTreeNode* bitree_rootnode(BiTree* tree)
{
	return tree->rootnode;
}

BiTreeNode* bitree_node_parent(BiTreeNode* node)
{
	return node->parent;
}

BiTreeValue bitree_node_value(BiTreeNode* node)
{
	return node->value;
}

BiTreeNode* bitree_node_child(BiTreeNode* node, BiTreeNodeSide side)
{
	if (side == BITREE_NODE_LEFT || side == BITREE_NODE_RIGHT)
		return node->children[side];
	else
	{
		printf("Error in bitree_node_child");
		return NULL;
	}
}

BiTreeNode* bitree_insert(BiTree* tree, BiTreeValue value, BiTreeNode* parent, BiTreeNodeSide side)
{
	BiTreeNode* newnode;
	if ((newnode = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL)
		return NULL;
	//初始化
	newnode->children[BITREE_NODE_LEFT] = NULL;
	newnode->children[BITREE_NODE_RIGHT] = NULL;
	newnode->parent = parent;
	newnode->value = value;
	if (parent == NULL)
	{
		//插入根节点
		if (tree->rootnode != NULL)
		{
			tree->rootnode->parent = newnode;
			newnode->children[side] = tree->rootnode;
			tree->rootnode = newnode;
		}
		else
		{
			printf("Error in bitree_insert.");
			return NULL;
		}
	}
	else
	{
		if (parent->children[side] != NULL)
		{
			parent->children[side]->parent = newnode;
			newnode->children[side] = parent->children[side];
		}
		else;
		parent->children[side] = newnode;
	}
	tree->nodenum++;
	return newnode;
}

void bitree_remove_subtree(BiTree* tree, BiTreeNode* node)
{
	if (node == NULL) return;
	bitree_remove_subtree(tree, node->children[BITREE_NODE_LEFT]);
	bitree_remove_subtree(tree, node->children[BITREE_NODE_RIGHT]);
	free(node);
	tree->nodenum--;
}

void bitree_free(BiTree* tree)
{
	bitree_remove_subtree(tree, tree->rootnode);
	free(tree);
}

void bitree_remove(BiTree* tree, BiTreeNode* node)
{
	BiTreeNode* parent = node->parent;

	if (parent != NULL)
	{
		if (parent->children[BITREE_NODE_LEFT] == node)
			parent->children[BITREE_NODE_LEFT] = NULL;
		else
			parent->children[BITREE_NODE_RIGHT] = NULL;
		bitree_remove_subtree(tree, node);	//这是删除一个结点？子树全没了？重建呢？
	}
	else
	{
		bitree_free(tree);					//删除根节点之后，这不是二叉树了，用free应该说得过去
		tree->rootnode = NULL;
	}
}

BiTree* bitree_new()
{
	BiTree* newtree;
	newtree = (BiTree*)malloc(sizeof(BiTree));
	if (newtree == NULL)
		return NULL;
	newtree->nodenum = 0;
	newtree->rootnode = NULL;
	return newtree;
}

bitree_pre_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	if (node)
	{
		visit(node);				//访问节点
		if (bitree_pre_order(node->children[BITREE_NODE_LEFT], visit))
		{
			if (bitree_pre_order(node->children[BITREE_NODE_RIGHT], visit))
				return TRUE;
		}
		return FALSE;
	}
	return TRUE;
}

bool bitree_in_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	if (node)
	{
		if (bitree_in_order(node->children[BITREE_NODE_LEFT], visit))
		{
			visit(node);
			if (bitree_in_order(node->children[BITREE_NODE_RIGHT], visit))
				return TRUE;
		}
		return FALSE;
	}
	return TRUE;
}

bool bitree_post_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	if (node)
	{
		if (bitree_post_order(node->children[BITREE_NODE_LEFT], visit))
			if (bitree_post_order(node->children[BITREE_NODE_RIGHT], visit))
			{
				visit(node);
				return TRUE;
			}
		return FALSE;
	}
}

void bitree_level_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	//if (node == NULL)
	//	return;
	//SeqQueue* queue = seqqueue_new();
	//seqqueue_push(queue, node);
	//while (!seqqueue_is_empty(queue))
	//{
	//	visit(queue->array[0]);
	//	if (queue->array[0]->children[BITREE_NODE_LEFT] != NULL)
	//		seqqueue_push(queue, queue->array[0]->children[BITREE_NODE_LEFT]);
	//	if (queue->array[0]->children[BITREE_NODE_RIGHT] != NULL)
	//		seqqueue_push(queue, queue->array[0]->children[BITREE_NODE_RIGHT]);
	//	sequeue_pop(queue);
	//}
}

void bitree_nrpre_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	ArrayList* stack = seqstack_new(MAXNODE);
	BiTreeNode* p = node;
	if (p == NULL)
		return;
	while (!(p == NULL && seqstack_is_empty(stack)))
	{
		while (p != NULL)
		{
			visit(p);
			seqstack_push(stack, p);
			p = p->children[BITREE_NODE_LEFT];
		}
		if (seqstack_is_empty(stack))				//栈空时结束
			return;
		else
		{
			p = (BiTreeNode*)seqstack_pop(stack);
			p = p->children[BITREE_NODE_RIGHT];
		}
	}
}

void bitree_nrin_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	ArrayList* stack = seqstack_new(MAXNODE);
	BiTreeNode* p = node;
	if (p == NULL)
		return;
	while (!(p == NULL && seqstack_is_empty(stack)))
	{
		while (p != NULL)
		{
			seqstack_push(stack, p);
			p = p->children[BITREE_NODE_LEFT];
		}
		if (seqstack_is_empty(stack))				//栈空时结束
			return;
		else
		{
			p = (BiTreeNode*)seqstack_pop(stack);
			visit(p);
			p = p->children[BITREE_NODE_RIGHT];
		}
	}
}

void bitree_nrpost_order(BiTreeNode* node, BiTreeVisitFunc visit)
{
	//ArrayList* stack = seqstack_new(MAXNODE);
	//BiTreeNode* p;
	//stacktype* q;
	//int sign;
	//if (node == NULL)
	//	return;
	//while (!(q == NULL && seqstack_is_empty(stack)))
	//{
	//	if (p != NULL)									//节点第一次进栈
	//	{
	//		q = malloc(sizeof(stacktype));
	//		q->link = p;
	//		q->flag = 1;
	//		seqstack_push(stack, q);
	//		p = p->children[BITREE_NODE_LEFT];
	//	}
	//	else
	//	{
	//		p = seqstack_peek(stack)->link;				//栈中的数据类型需要更改
	//		sign = seqstack_peek(stack)->flag;
	//		seqstack_pop(stack);
	//		if (sign == 1)
	//		{
	//			q = malloc(sizeof(stacktype));
	//			q->link = p;
	//			q->flag = 2;
	//			seqstack_push(stack, q);
	//			p = p->children[BITREE_NODE_RIGHT];
	//		}
	//		else
	//		{
	//			visit(p);
	//			p = NULL;
	//		}
	//	}
	//}
}