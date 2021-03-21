//以拉链法为例，实现散列结构

#ifdef _cpluscplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
//定义散列表中数据的空指针
#define HASH_TABLE_NULL ((void*)0)

#ifndef __HASH_TABLE_H_HELLO_QIU__
#define __HASH_TABLE_H_HELLO_QIU__

	//在散列表中查找数据的关键字
	typedef void* HashTableKey;

	//存储在散列表中的数据
	typedef void* HashTableValue;

	//散列表节点
	struct _HashTableEntry
	{
		HashTableKey key;
		HashTableValue value;
		struct _HashTableEntry* next;
	};
	//散列表内部节点的结构
	typedef struct _HashTableEntry HashTableEntry;


	//在散列表中用来生成关键字散列数的哈希函数
	typedef unsigned int (*HashTableHashFunc)(HashTableKey value);

	//比较两个关键字是否相同的函数
	typedef int (*HashTableEqualFunc)(HashTableKey value1, HashTableKey value2);

	//用来在节点移除出散列表时释放一个关键字的函数类型
	typedef void (*HashTableKeyFreeFunc)(HashTableKey value);

	//用来在节点移除出散列表时释放一个数值的函数类型
	typedef void (*HashTableValueFreeFunc)(HashTableValue value);


	struct _HashTable
	{
		//访问散列表的入口
		HashTableEntry** table;
		//散列表的大小，指的是散列表中链表的数量,不直接更改
		unsigned int table_size;
		//散列表的哈希函数，输入一个关键字返回地址
		HashTableHashFunc hash_func;
		//散列表中用于判断两个关键字是否相同的函数
		HashTableEqualFunc equal_func;
		//用于释放关键节点的函数
		HashTableKeyFreeFunc key_free_func;
		//用于释放节点数据的函数
		HashTableValueFreeFunc value_free_func;
		//用于记录散列表中已使用的节点数量
		unsigned int entries;
		//指示一个下标，在一个素数集合中，该下标所知识的素数即散列表的大小
		unsigned int prime_index;
	};
	//散列表结构
	typedef struct _HashTable HashTable;

	//定义散列表迭代器结构
	struct _HashTableIterator
	{
		HashTable* hash_table;
		HashTableEntry* next_entry;
		unsigned int next_chain;
	};
	//散列表迭代器结构，用于遍历链表
	typedef struct _HashTableIterator HashTableIterator;

	//创建一个新的散列表
	HashTable* hash_table_new(HashTableHashFunc hash_func, HashTableEqualFunc equal_func);

	//销毁一个散列表
	void hash_table_free(HashTable* hash_table);

	//登记用来释放关键字和数值的函数
	void hash_table_register_free_functions(HashTable* hash_table,
		HashTableKeyFreeFunc key_free_func, HashTableValueFreeFunc value_free_func);

	//在散列表中插入一个值，将会覆盖所有已存在的使用相同关键字的节点
	int hash_table_insert(HashTable* hash_table, HashTableKey key, HashTableValue value);

	//通过关键字在散列表中查找数据
	HashTableValue hash_table_lookup(HashTable* hash_table, HashTableKey key);

	//在散列表中移除一个值
	int hash_table_remove(HashTable* hash_table, HashTableKey key);

	//检索散列表中的节点个数
	unsigned int hash_table_num_entries(HashTable* hash_table);

	//初始化一个散列表迭代器
	void hash_table_iterate(HashTable* hash_table, HashTableIterator* iterator);

	//判断散列表（一个链表）中是否还有关键字来遍历
	int hash_table_iter_has_more(HashTableIterator* iterator);

	//使用散列表迭代器来检索下一个关键字
	HashTableValue hash_table_iter_next(HashTableIterator* iterator);

	static int hash_table_enlarge(HashTable* hash_table);
	int hash_table_free_entry(HashTable* hash_table, HashTableEntry* entry);

#ifdef _cpluscplus
}
#endif

#endif