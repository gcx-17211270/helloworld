#include "Sort.h"

void insert_sort(StaticTable* p, ArrayListCompareFunc compare_func)
{
	unsigned int i, j;
	for (i = 2; i <= p->length - 1; i++)
	{
		//小于时，需将data[i]插入有序表
		if (compare_func(p->data[i - 1], p->data[i]))
		{
			p->data[0] = p->data[i];				//为统一算法设置监测
			for (j = i - 1; compare_func(p->data[j], p->data[0]) == 1; j--)
			{
				p->data[j + 1] = p->data[j];		//记录后移
				if (j == 0)
					break;
			}
			p->data[j + 1] = p->data[0];			//插入正确的位置
		}
	}
}

void shell_sort(StaticTable* p, int len)
{
	int k = 1;
	while (k < len / 3) k = 3 * k + 1;				//k的值的序列，就相当于下面代码的增量序列
	while (k > 1)
	{
		for (int i = k; i < len; i++)
			for (int j = i; j >= k && (p->data[j - k] > p->data[j]); j = j - k)
			{
				ArrayListValue temp = p->data[j - k];
				p->data[j - k] = p->data[j];
				p->data[j] = temp;					//这样能交换两个值嘛？
			}
		k = k / 3;
	}
}
int compare(ArrayListValue a, ArrayListValue b)
{
	if (a >= b) return 0;
	else return -1;
}
void shell_sort_(StaticTable* p, int dlta[], int t)
{
	int k;
	ArrayListCompareFunc comp = compare;
	for (k = 0; k < t; k++)
		shell_insert(p, dlta[k], comp);
}

void shell_insert(StaticTable* p, int dk, ArrayListCompareFunc compare_func)
{
	unsigned int i, j;
	for (i = dk + 1; i <= p->length; i = i + dk)
	{
		if (compare_func(p->data[i - dk], p->data[i]))
		{
			p->data[0] = p->data[i];
			for (j = i - dk; j > 0 && compare_func(p->data[j], p->data[0]); j = j - dk)
			{
				p->data[j + dk] = p->data[j];
			}
			p->data[j + dk] = p->data[0];
		}
	}
}

void bubble_sort(StaticTable* p, ArrayListCompareFunc compare_func)
{
	int i, j, n, noswap = FALSE;
	ArrayListValue swap;
	n = p->length;

	//每次循环初始化noswap，如果有一次循环结束后仍为TRUE，说明表完成排序
	for (i = 1; i <= n - 1 && !noswap; i++)
	{
		noswap = TRUE;
		for (j = n - 1; j >= i; j--)
		{
			if (compare_func(p->data[j - 1], p->data[j]) == 1)
			{
				swap = p->data[j - 1];
				p->data[j - 1] = p->data[j];
				p->data[j] = swap;
				noswap = FALSE;
			}
		}
	}
}

void quickSort(int* st, int lo, int hi)
{
	if (lo >= hi) return;
	int k = partition(st, lo, hi);
	quickSort(st, lo, k - 1);
	quickSort(st, k + 1, hi);
}

int partition(int* st, int lo, int hi)
{
	int v = st[lo];
	int i = lo, j = hi + 1;
	while (1)
	{
		while (st[++i] < v) if (i >= hi) break;
		while (st[--j] > v) if (j <= lo) break;
		if (i >= j) break;
		int temp = st[i];
		st[i] = st[j];
		st[j] = temp;
	}
	st[lo] = st[j];
	st[j] = v;
	return j;
}

void quick_sort(StaticTable* tbl, int low, int high, ArrayListCompareFunc compare_func)
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = arraylist_partition(tbl, low, high, compare_func);
		quick_sort(tbl, low, pivotloc - 1, compare_func);
		quick_sort(tbl, pivotloc + 1, high, compare_func);
	}
}
int arraylist_partition(ArrayList* arraylist, int low, int high, ArrayListCompareFunc compare_func)
{
	ArrayListValue pivotkey;						//记录支点数据的变量
	ArrayListValue temp;
	pivotkey = arraylist->data[low];				//取支点记录关键字
	while (low < high)								//从表的两端交替地向中间扫描
	{
		while (low < high && compare_func(arraylist->data[high], pivotkey))
			high--;
		temp = arraylist->data[low];
		arraylist->data[low] = arraylist->data[high];
		arraylist->data[high] = temp;				//将比支点记录小的交换到低端
		while (low < high && compare_func(pivotkey, arraylist->data[low]))
			low++;
		temp = arraylist->data[high];
		arraylist->data[high] = arraylist->data[low];
		arraylist->data[low] = temp;				//讲比支点记录大的交换到高端
	}
	return low;
}

void select_sort(StaticTable* s, ArrayListCompareFunc compare_func)
{
	unsigned int i, j, t;
	ArrayListValue swap;

	//作length - 1趟选取
	for (i = 0; i < s->length; i++)
	{
		//在i开始的length - i + 1个记录中选关键字最小的记录
		for (j = i + 1, t = i; j <= s->length - 1; j++)
		{
			if (compare_func(s->data[t], s->data[j]) == 1)
				t = j;
		}

		//将关键字最小的记录与第i个记录交换
		swap = s->data[t];
		s->data[t] = s->data[i];
		s->data[i] = swap;
	}
}

void mergeSort(int* p, int* q, int lo, int hi, int length)
{
	if (lo >= hi) return;
	int mid = (lo + hi) / 2;
	mergeSort(p, q, lo, mid, length);
	mergeSort(p, q, mid + 1, hi, length);
	merge(p, q, lo, mid, hi, length);
}

void merge(int* p, int* q, int lo, int mid, int hi, int length)
{
	int i = lo, j = mid + 1;
	for (int k = 0; k < length; k++)
		q[k] = p[k];
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid) p[k] = q[j++];
		else if (j > hi) p[k] = q[i++];
		else if (q[i] < q[j]) p[k] = q[i++];
		else p[k] = q[j++];
	}
}

void merge_sort(StaticTable* p, ArrayListValue* rf, ArrayListCompareFunc compare_func)
{
	ArrayListValue* q1, * q2, * swap;
	unsigned int i, len;
	q1 = rf;
	q2 = p->data;
	for (len = 1; len < p->length; len = 2 * len)				//从q2归并到q1
	{
		for (i = 0; i + 2 * len - 1 <= p->length; i = i + 2 * len)
			merge_(q2, q1, i, i + len, i + 2 * len - 1, compare_func);	//对等长的两个子表进行合并
		if (i + len - 1 < p->length)
			merge_(q2, q1, i, i + len, p->length - 1, compare_func);		//对不等长的两个子表进行合并
		else if (i < p->length)
			while (i <= p->length)
			{
				q1[i] = q2[i];
				i++;
			}
		swap = q1;
		q1 = q2;
		q2 = swap;
	}
	if (q2 != p->data)											//若最终结果不再*p表中，则传入子表合并
	{
		for (i = 1; i <= p->length - 1; i++)
			p->data[i] = q2[i];
	}
}

//两个子表合并，将rf表从第u项开始直到第t项的内容合并到rf从u开始的后续项中，如果从u到v和从v到t是不降的两组，那么合并后u到t的数据也是不降的
void merge_(ArrayListValue* r, ArrayListValue* rf, int u, int v, int t, ArrayListCompareFunc compare_func)
{
	int i, j, k;
	for (i = u, j = v, k = u; i < v && j <= t; k++)
	{
		if (compare_func(r[j], r[i]) == 1)
		{
			rf[k] = r[i];
			i++;
		}
		else
		{
			rf[k] = r[j];
			j++;
		}
	}
	if (i < v)
		for (; i < v; i++)
		{
			rf[k++] = r[i];										//将*r从i到v-1的内容赋值给*rf，从k到t
		}
	if (j <= t)
		for (; j <= t; j++)
		{
			rf[k++] = r[j];										//将*r从j到t的内容赋值给*rf，从k到t
		}
}

void sort_callback()
{
	int a[] = {15, 2, 5, 29, 24, 14, 79, 8, 23, 1, -3, 5, 234, 2838};
	int b[sizeof(a) / sizeof(int)] = { 0 };
	int length = sizeof(a) / sizeof(int);
	mergeSort(a, b, 0, length - 1, length);
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
	return;
}