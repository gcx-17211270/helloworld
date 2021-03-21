//��������Ϊ����ʵ��ɢ�нṹ

#ifdef _cpluscplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
//����ɢ�б������ݵĿ�ָ��
#define HASH_TABLE_NULL ((void*)0)

#ifndef __HASH_TABLE_H_HELLO_QIU__
#define __HASH_TABLE_H_HELLO_QIU__

	//��ɢ�б��в������ݵĹؼ���
	typedef void* HashTableKey;

	//�洢��ɢ�б��е�����
	typedef void* HashTableValue;

	//ɢ�б�ڵ�
	struct _HashTableEntry
	{
		HashTableKey key;
		HashTableValue value;
		struct _HashTableEntry* next;
	};
	//ɢ�б��ڲ��ڵ�Ľṹ
	typedef struct _HashTableEntry HashTableEntry;


	//��ɢ�б����������ɹؼ���ɢ�����Ĺ�ϣ����
	typedef unsigned int (*HashTableHashFunc)(HashTableKey value);

	//�Ƚ������ؼ����Ƿ���ͬ�ĺ���
	typedef int (*HashTableEqualFunc)(HashTableKey value1, HashTableKey value2);

	//�����ڽڵ��Ƴ���ɢ�б�ʱ�ͷ�һ���ؼ��ֵĺ�������
	typedef void (*HashTableKeyFreeFunc)(HashTableKey value);

	//�����ڽڵ��Ƴ���ɢ�б�ʱ�ͷ�һ����ֵ�ĺ�������
	typedef void (*HashTableValueFreeFunc)(HashTableValue value);


	struct _HashTable
	{
		//����ɢ�б�����
		HashTableEntry** table;
		//ɢ�б�Ĵ�С��ָ����ɢ�б������������,��ֱ�Ӹ���
		unsigned int table_size;
		//ɢ�б�Ĺ�ϣ����������һ���ؼ��ַ��ص�ַ
		HashTableHashFunc hash_func;
		//ɢ�б��������ж������ؼ����Ƿ���ͬ�ĺ���
		HashTableEqualFunc equal_func;
		//�����ͷŹؼ��ڵ�ĺ���
		HashTableKeyFreeFunc key_free_func;
		//�����ͷŽڵ����ݵĺ���
		HashTableValueFreeFunc value_free_func;
		//���ڼ�¼ɢ�б�����ʹ�õĽڵ�����
		unsigned int entries;
		//ָʾһ���±꣬��һ�����������У����±���֪ʶ��������ɢ�б�Ĵ�С
		unsigned int prime_index;
	};
	//ɢ�б�ṹ
	typedef struct _HashTable HashTable;

	//����ɢ�б�������ṹ
	struct _HashTableIterator
	{
		HashTable* hash_table;
		HashTableEntry* next_entry;
		unsigned int next_chain;
	};
	//ɢ�б�������ṹ�����ڱ�������
	typedef struct _HashTableIterator HashTableIterator;

	//����һ���µ�ɢ�б�
	HashTable* hash_table_new(HashTableHashFunc hash_func, HashTableEqualFunc equal_func);

	//����һ��ɢ�б�
	void hash_table_free(HashTable* hash_table);

	//�Ǽ������ͷŹؼ��ֺ���ֵ�ĺ���
	void hash_table_register_free_functions(HashTable* hash_table,
		HashTableKeyFreeFunc key_free_func, HashTableValueFreeFunc value_free_func);

	//��ɢ�б��в���һ��ֵ�����Ḳ�������Ѵ��ڵ�ʹ����ͬ�ؼ��ֵĽڵ�
	int hash_table_insert(HashTable* hash_table, HashTableKey key, HashTableValue value);

	//ͨ���ؼ�����ɢ�б��в�������
	HashTableValue hash_table_lookup(HashTable* hash_table, HashTableKey key);

	//��ɢ�б����Ƴ�һ��ֵ
	int hash_table_remove(HashTable* hash_table, HashTableKey key);

	//����ɢ�б��еĽڵ����
	unsigned int hash_table_num_entries(HashTable* hash_table);

	//��ʼ��һ��ɢ�б������
	void hash_table_iterate(HashTable* hash_table, HashTableIterator* iterator);

	//�ж�ɢ�б�һ���������Ƿ��йؼ���������
	int hash_table_iter_has_more(HashTableIterator* iterator);

	//ʹ��ɢ�б��������������һ���ؼ���
	HashTableValue hash_table_iter_next(HashTableIterator* iterator);

	static int hash_table_enlarge(HashTable* hash_table);
	int hash_table_free_entry(HashTable* hash_table, HashTableEntry* entry);

#ifdef _cpluscplus
}
#endif

#endif