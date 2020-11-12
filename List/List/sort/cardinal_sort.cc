#include "cardinal_sort.h"

ArrType f;
ArrType e;

void radix_sort(StaticList* list)
{
	for (int i = 0; i < list->recnum; i++)
		list->r[i].next = i + 1;
	list->r[(list->recnum) - 1].next = 0;					//将List改造为静态链表
	for (int i = 0; i < list->keynum; i++)			//按LSD依次对各关键字进行分配和采集
	{
		distribute(list->r, i, f, e);
		collect(list->r, i, f, e);
	}
}

void distribute(StaticListNode* r, int i, ArrType& f, ArrType& e)
{
	for (int j = 0; j < RADIX; j++)
	{
		f[j] = 0;
		e[j] = 0;
	}
	for (int p = r[0].next; p; p = r[p].next)
	{
		int j = r[p].keys[i];
		if (!f[j])
			f[j] = p;
		else
			r[e[j]].next = p;				
		e[j] = p;
	}
}

int succ(int j)
{
	while (!f[++j]);
	return j;
}

void collect(StaticListNode* r, int i, ArrType& f, ArrType& e)
{
	int j;
	for (j = 0; !f[j]; j = succ(j));								//找第一个非空子表
	r[0].next = f[j];						//r[0].next指向第一个非空子表中第一个节点
	int t = e[j];
	while (j < RADIX)
	{
		for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j));		//找下一个非空子表
		if (f[j]) {
			r[t].next = f[j];
			t = e[j];
		}
	}
	r[t].next = 0;
}

void creat_keys(KeyType keys[MAX_NUM_OF_KEY], int val, int len)
{
	char* ch;
	ch = (char*)malloc(sizeof(char) * 50);
	sprintf_s((ch), 50, "%d", val);
	for (int i = 0; i < len; i++)
	{
		if ((ch[i]) >= '0' && (ch[i]) <= '9')
			keys[i] = (int)(ch[i] - '0');
		else
			keys[i] = -1;
	}
}

int get_keys(KeyType keys[], int len)
{
	int val = (int)(keys[0] - '0');
	for (int i = 1; i < len; i++)
	{
		if (keys[i] == '\0') break;
		if (keys[i] == -1) break;
		val *= 10;
		val += (int)(keys[i] - '0');
	}
	return val;
}

void cardinal_sort_callback()
{
	StaticList* st = (StaticList*)malloc(sizeof(StaticList));
	(st->keynum) = 3;
	st->recnum = 10;
	creat_keys(st->r[0].keys, 278, 3);
	creat_keys(st->r[1].keys, 109, 3);
	creat_keys(st->r[2].keys, 63, 3);
	creat_keys(st->r[3].keys, 930, 3);
	creat_keys(st->r[4].keys, 589, 3);
	creat_keys(st->r[5].keys, 184, 3);
	creat_keys(st->r[6].keys, 505, 3);
	creat_keys(st->r[7].keys, 269, 3);
	creat_keys(st->r[8].keys, 8, 3);
	creat_keys(st->r[9].keys, 83, 3);
	radix_sort(st);
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = get_keys(st->r[i].keys, 3);
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
}