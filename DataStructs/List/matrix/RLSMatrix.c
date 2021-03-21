/*
* 数据结构：行链接的顺序存储
* author：	32353
* data：	2020.10.17 13:34
*/
#include "RLSMatrix.h"

int sm_mult(RLSMatrix A, RLSMatrix B, RLSMatrix C)
{
	int tp, p, q, t, arow, brow, ccol, i;
	double ctemp[CMAX];
	if (A.nu != B.nu)
		return 0;
	C.mu = A.mu;
	C.nu = B.nu;
	C.tu = 0;
	if (A.tu * B.tu != 0)
	{
		for (arow = 1; arow <= A.mu; arow++)
		{
			for (i = 1; i <= C.nu; i++)
				ctemp[i] = 0;
			C.rpos[arow] = C.tu + 1;
			if (arow < A.mu)
				tp = A.rpos[arow + 1];
			else
				tp = A.tu + 1;
			//处理当前行中每个非零元素
			for (p = A.rpos[arow]; p < tp; p++)
			{
				brow = A.data[p].col;
				if (brow < B.mu)
					t = B.rpos[brow + 1];
				else
					t = B.tu + 1;
				for (q = B.rpos[brow]; q < t; q++)
				{
					ccol = B.data[q].col;		//乘积元素在C中列号
					ctemp[ccol] += A.data[p].val * B.data[q].val;
				}
			}
			for (ccol = 1; ccol <= C.nu; ccol++)	//存储该行非零元素
			{
				if (ctemp[ccol])
				{
					if (++C.tu > SMax)
						return 0;
					C.data[C.tu].row = arow;
					C.data[C.tu].row = ccol;
					C.data[C.tu].val = ctemp[ccol];
				}
			}
		}
	}
	return 1;
}