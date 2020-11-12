//查找使用的函数

#define KeyType double
#define OrderType int
#define StaticSearchTable KeyType*
#define IndexOrderTable OrderType*

#ifndef __SEARCH_H_HELLO_QIU__
#define __SEARCH_H_HELLO_QIU__

#ifdef _cplusplus
extern "C"
{
#endif
	//在静态查找有序表时，有以下查找方法

	//折半查找
	int search_bin(StaticSearchTable st, KeyType key);

	//斐波拉契查找
	int search_fab(StaticSearchTable st, KeyType key);

	//插值查找
	int search_int(StaticSearchTable st, KeyType key);
	int search_int_help(StaticSearchTable st, KeyType key, int lo, int hi);

	//分块查找
	int search_block(StaticSearchTable st, IndexOrderTable it, KeyType key);

#ifdef _cpluscplus
}
#endif
#endif