#include "olMatrix.h"

OLink olnode_setValue(int i, int j, MatrixValue e)
{
	OLink p;
	p = (OLNode*)malloc(sizeof(OLNode));
	p->row = i;
	p->col = j;
	p->val = e;
	p->down = NULL;
	p->right = NULL;
	return p;
}

OLMatrix olink_create(int mu, int nu, int tu)
{
	OLMatrix olmatrix;
	OLink p, q;
	int i, row, col;
	MatrixValue val;
	
	//申请行头节点
	olmatrix.rhead = (OLNode*)malloc(sizeof(OLNode) * mu);
	for (i = 0; i < mu; i++)
		olmatrix.rhead[i].right = NULL;

	olmatrix.chead = (OLNode*)malloc(sizeof(OLNode) * nu);
	for (i = 0; i < nu; i++)
		olmatrix.chead[i].down = NULL;

	olmatrix.mu = mu;
	olmatrix.nu = nu;
	olmatrix.tu = tu;

	for (i = 0; i < tu; i++)
	{
		printf("请输入 行号、列号、数值：");
		scanf_s("%d %d %lf", &row, &col, &val);
		p = olnode_setValue(row, col, val);
		
		q = &(olmatrix.rhead[row - 1]);
		while (q->right != NULL && q->right->col < col)			//将P插入行链中
		{
			q = q->right;							//插入后会多一个节点，不做处理吗？
		}
		p->right = q->right;
		q->right = p;

		q = &(olmatrix.chead[col - 1]);
		while (q->down != NULL && q->down->row < row)			//将P插入列链当中
		{
			q = q->down;
		}
		p->down = q->down;
		q->down = p;
	}
	return olmatrix;
}

void olMatrix_add(OLMatrix A, OLMatrix B)
{
	OLink pa, pb, qa;				//分别指向A和B第一行的第一个非零元素的节点
	for (int i = 0; i < A.mu; i++)
	{
		pa = A.rhead[i].right;
		pb = B.rhead[i].right;
		qa = &(A.rhead[i]);
		while (pa != NULL && pb != NULL)
		{
			if (pb == NULL) break;
			else if (pa == NULL || pa->col > pb->col)
			{
				OLink p = (OLNode*)malloc(sizeof(OLNode));
				p->row = pb->row;
				p->col = pb->col;
				p->val = pb->val;
				p->right = pa;
				pa->right = p;			//将新节点插入*pa的前面
				pa = p;

				//列链表也要做相应的改变
				OLink q = &(A.chead[p->col - 1]);
				while (q->down != NULL && q->down->row < p->row)
					q = q->down;
				p->down = q->down;
				q->down = p;

				pb = pb->right;
			}
			else if (pa != NULL && pa->col < pb->col)
			{
				qa = pa;
				pa = pa->right;
			}
			else if (pa != NULL && pa->col == pb->col)
			{
				pa->val += pb->val;
				if (pa->val == 0)
				{
					qa->right = pa->right;
					OLink q = &(A.chead[pa->col]);
					while (q->down != pa)
						q = q->down;
					q->down = pa->down;
					free(pa);
					pa = qa;
				}

				pa = pa->right;
				pb = pb->right;
			}
		}
	}
}

OL_SPMatrix olsm_transpose(OL_SPMatrix A)
{
	OL_SPMatrix T;
	OLink p, q, pa, pre;
	int i, rownum = 1;
	T.mu = A.nu;
	T.nu = A.mu;
	T.tu = A.tu;
	T.rhead = (OLNode*)malloc(sizeof(OLNode) * T.mu);
	for (i = 0; i < T.mu; i++)
		T.rhead[i].right = NULL;
	T.chead = (OLNode*)malloc(sizeof(OLNode) * T.nu);
	for (i = 0; i < T.nu; i++)
		T.chead[i].down = NULL;

	while (rownum <= T.mu)
	{
		pa = A.chead[rownum - 1].down;
		pre = &(T.rhead[rownum - 1]);		//*pre指向行链中前一个插入的节点
		while (pa != NULL)
		{
			p = olnode_setValue(pa->col, pa->row, pa->val);
			pre->right = p;					//在转置矩阵行链表中插入节点
			pre = p;
			q = &(T.chead[pa->row - 1]);
			while (q->down != NULL)
			{
				q = q->down;
			}
			q->down = p;
			pa = pa->down;
		}
		rownum++;
	}
	return T;
}

void olsm_print(OL_SPMatrix A)
{
	int i, j;
	OLink p, q;
	for (i = 1; i <= A.mu; i++)
	{
		j = 1;
		p = &(A.rhead[i - 1]);				//指向第i行的头节点
		q = p->right;						//指向第i行的第一个节点
		while (q != NULL)
		{
			for (; j < q->col; j++)
				printf("   0\t");
			j++;
			printf("%4.2f\t", q->val);
			q = q->right;
		}
		for (; j <= A.nu; j++)
			printf("   0\t");
		printf("\n");
	}
}

OL_SPMatrix olsm_mult(OL_SPMatrix A, OL_SPMatrix B)
{
	OL_SPMatrix M; 
	OLink p, q, qa, qb, pre;
	int i, j;
	ElementType x;
	M.mu = A.mu;
	M.nu = B.nu;
	if (A.nu != B.mu)
	{
		printf("Error: Size mismatch");
		return M;
	}

	M.rhead = (OLNode*)malloc(sizeof(OLNode) * M.mu);
	for (i = 0; i < M.mu; i++)
		M.rhead[i].right = NULL;

	M.chead = (OLNode*)malloc(sizeof(OLNode) * M.nu);
	for (i = 0; i < M.nu; i++)
		M.chead[i].down = NULL;

	for (i = 1; i < M.mu; i++)
	{
		pre = &(M.rhead[i - 1]);
		for (j = 1; j <= M.nu; j++)
		{
			qa = A.rhead[i - 1].right;
			qb = B.chead[j - 1].down;
			x = 0;
			while (qa != NULL && qb != NULL)
			{
				if (qa->col < qb->row)
					qa = qa->right;
				else if (qa->col > qb->row)
					qb = qb->down;
				else
				{
					x += qa->val * qb->val;
					qa = qa->right;
					qb = qb->down;
				}
			}
			if (x)
			{
				p = olnode_setValue(i, j, x);
				pre->right = p;							//将p插入第i行
				pre = p;
				q = &(M.chead[j - 1]);
				while (q->down != NULL)
					q = q->down;
				q->down = p;							//将p插入第j列中
			}
		}
	}
	return M;
}

void olMatrix_callback()
{
	int mu, nu, tu;
	OLMatrix new_olmatrix1, new_olmatrix2;
	printf("矩阵1：\n");
	printf("请输入稀疏矩阵的总行数、总列数、非零项数：");
	scanf_s("%d %d %d", &mu, &nu, &tu);
	new_olmatrix1  = olink_create(mu, nu, tu);
	olsm_print(new_olmatrix1);

	printf("矩阵2：\n");
	printf("请输入稀疏矩阵的总行数、总列数、非零项数：");
	scanf_s("%d %d %d", &mu, &nu, &tu);
	new_olmatrix2 = olink_create(mu, nu, tu);
	olsm_print(new_olmatrix2);
	olMatrix_add(new_olmatrix1, new_olmatrix2);
	olsm_print(new_olmatrix1);
	OL_SPMatrix T = olsm_transpose(new_olmatrix1);
	olsm_print(T);
	OL_SPMatrix M = olsm_mult(new_olmatrix1, new_olmatrix2);
	olsm_print(M);
	return;
}