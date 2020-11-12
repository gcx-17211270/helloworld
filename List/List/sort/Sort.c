#include "Sort.h"

void insert_sort(StaticTable* p, ArrayListCompareFunc compare_func)
{
	unsigned int i, j;
	for (i = 2; i <= p->length - 1; i++)
	{
		//С��ʱ���轫data[i]���������
		if (compare_func(p->data[i - 1], p->data[i]))
		{
			p->data[0] = p->data[i];				//Ϊͳһ�㷨���ü��
			for (j = i - 1; compare_func(p->data[j], p->data[0]) == 1; j--)
			{
				p->data[j + 1] = p->data[j];		//��¼����
				if (j == 0)
					break;
			}
			p->data[j + 1] = p->data[0];			//������ȷ��λ��
		}
	}
}

void shell_sort(StaticTable* p, int len)
{
	int k = 1;
	while (k < len / 3) k = 3 * k + 1;				//k��ֵ�����У����൱������������������
	while (k > 1)
	{
		for (int i = k; i < len; i++)
			for (int j = i; j >= k && (p->data[j - k] > p->data[j]); j = j - k)
			{
				ArrayListValue temp = p->data[j - k];
				p->data[j - k] = p->data[j];
				p->data[j] = temp;					//�����ܽ�������ֵ�
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

	//ÿ��ѭ����ʼ��noswap�������һ��ѭ����������ΪTRUE��˵�����������
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
	ArrayListValue pivotkey;						//��¼֧�����ݵı���
	ArrayListValue temp;
	pivotkey = arraylist->data[low];				//ȡ֧���¼�ؼ���
	while (low < high)								//�ӱ�����˽�������м�ɨ��
	{
		while (low < high && compare_func(arraylist->data[high], pivotkey))
			high--;
		temp = arraylist->data[low];
		arraylist->data[low] = arraylist->data[high];
		arraylist->data[high] = temp;				//����֧���¼С�Ľ������Ͷ�
		while (low < high && compare_func(pivotkey, arraylist->data[low]))
			low++;
		temp = arraylist->data[high];
		arraylist->data[high] = arraylist->data[low];
		arraylist->data[low] = temp;				//����֧���¼��Ľ������߶�
	}
	return low;
}

void select_sort(StaticTable* s, ArrayListCompareFunc compare_func)
{
	unsigned int i, j, t;
	ArrayListValue swap;

	//��length - 1��ѡȡ
	for (i = 0; i < s->length; i++)
	{
		//��i��ʼ��length - i + 1����¼��ѡ�ؼ�����С�ļ�¼
		for (j = i + 1, t = i; j <= s->length - 1; j++)
		{
			if (compare_func(s->data[t], s->data[j]) == 1)
				t = j;
		}

		//���ؼ�����С�ļ�¼���i����¼����
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
	for (len = 1; len < p->length; len = 2 * len)				//��q2�鲢��q1
	{
		for (i = 0; i + 2 * len - 1 <= p->length; i = i + 2 * len)
			merge_(q2, q1, i, i + len, i + 2 * len - 1, compare_func);	//�Եȳ��������ӱ���кϲ�
		if (i + len - 1 < p->length)
			merge_(q2, q1, i, i + len, p->length - 1, compare_func);		//�Բ��ȳ��������ӱ���кϲ�
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
	if (q2 != p->data)											//�����ս������*p���У������ӱ�ϲ�
	{
		for (i = 1; i <= p->length - 1; i++)
			p->data[i] = q2[i];
	}
}

//�����ӱ�ϲ�����rf��ӵ�u�ʼֱ����t������ݺϲ���rf��u��ʼ�ĺ������У������u��v�ʹ�v��t�ǲ��������飬��ô�ϲ���u��t������Ҳ�ǲ�����
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
			rf[k++] = r[i];										//��*r��i��v-1�����ݸ�ֵ��*rf����k��t
		}
	if (j <= t)
		for (; j <= t; j++)
		{
			rf[k++] = r[j];										//��*r��j��t�����ݸ�ֵ��*rf����k��t
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