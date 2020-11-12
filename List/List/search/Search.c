#include "Search.h"

int search_bin(StaticSearchTable st, KeyType key)
{
	//在有序表中折半查找其关键字等于Key的数据元素，设关键字按升序排列
	//若找到则返回其在表中的位置，否则返回-1
	int low = 1, high = sizeof(st) / sizeof(KeyType), mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (st[mid] == key)
			return mid;
		else if (st[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int search_fab(StaticSearchTable st, KeyType key)
{
	int i = 0, j = 1, k;
	k = i + j;
	if (st[0] == key) return 0;
	if (st[k] == key)
		return k;
	else if (st[k] < key)
	{
		i = j;
		j = k;
		k = i + j;
	}
	else
	{
		search_fab(st + j - 1, key);
	}
	return -1;
}

int search_int(StaticSearchTable st, KeyType key)
{
	return search_int_help(st, key, 0, sizeof(st) / sizeof(KeyType));
}

int search_int_help(StaticSearchTable st, KeyType key, int lo, int hi)
{
	int i = (key - st[lo]) * (hi - lo + 1) / (st[hi] - st[lo]);
	if (st[i] == key) return i;
	else if (st[i] > key)
		return search_int_help(st, key, lo, i);
	else
		return search_int_help(st, key, i, hi);
}

int search_block(StaticSearchTable st, IndexOrderTable it, KeyType key)
{
	int index = 0;
	int lo = 0, hi = sizeof(IndexOrderTable) / sizeof(OrderType) - 1;
	while (lo < hi)
	{
		if (it[lo] == key)
		{
			index = lo;
			break;
		}
		if (it[hi] == key)
		{
			index = hi;
			break;
		}
		int mid = (lo + hi) / 2;
		if (it[mid] > key)
			if (it[mid - 1] > key)
				hi = mid - 1;
			else
			{
				index = mid;
				break;
			}
		else if (it[mid] < key)
			if (it[mid + 1] < key)
				lo = mid + 1;
			else
			{
				index = mid + 1;
				break;
			}
		else
		{
			index = mid;
		}
	}
	return search_bin(st + it[index], key);
}