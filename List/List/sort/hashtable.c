#include "hashtable.h"

// hash_table_allocate_table是内部函数，未写入头文件中，其具体功能是在散列表扩大时给散列表分配内存
HashTable* hash_table_allocate_table(HashTable* hash_table)
{
	for (unsigned int i = 0; i < hash_table->table_size; i++)
	{
		hash_table->table[i] = (HashTableEntry*)malloc(sizeof(HashTableEntry));
		if (hash_table->table[i] == NULL)
			return NULL;
		hash_table->table[i]->key = 0;
		hash_table->table[i]->next = NULL;
		hash_table->table[i]->value = 0;
	}
	return hash_table;
}

HashTable* hash_table_new(HashTableHashFunc hash_func, HashTableEqualFunc equal_func)
{
	HashTable* hash_table;

	//分配一个内存空间
	hash_table = (HashTable*)malloc(sizeof(HashTable));
	if (hash_table == NULL)
		return NULL;
	hash_table->hash_func = hash_func;
	hash_table->equal_func = equal_func;
	hash_table->key_free_func = NULL;
	hash_table->value_free_func = NULL;
	hash_table->entries = 0;
	hash_table->prime_index = 0;

	//给每个节点分配内存空间，节点数量为table_size
	if (hash_table_allocate_table(hash_table) == NULL)
	{
		free(hash_table);
		return NULL;
	}
	return hash_table;
}

int hash_table_insert(HashTable* hash_table, HashTableKey key, HashTableValue value)
{
	HashTableEntry* rover;
	HashTableEntry* newentry;
	unsigned int index;

	//如果表中节点过多，冲突的可能性增大，散列表的查找效率下降，此时扩大表的大小
	if ((hash_table->entries * 3 / hash_table->table_size) > 0)
		if (!hash_table_enlarge(hash_table))
			//分配内存失败
			return 0;

	//根据关键字找到对应链表头节点的下标
	index = hash_table->hash_func(key) % hash_table->table_size;

	//遍历整个链表来查找是否有相同关键字的节点，有则覆盖，否则添加
	rover = hash_table->table[index];
	while (rover != NULL)
	{
		if (hash_table->equal_func(rover->key, key) != 0)
		{
			//若找到相同关键字，则用新数据覆写节点
			//如果有释放数值和关键字内存的函数，那么释放旧内存，否则跳过
			if (hash_table->value_free_func != NULL)
				hash_table->value_free_func(rover->value);
			if (hash_table->key_free_func != NULL)
				hash_table->key_free_func(rover->key);
			rover->key = key;
			rover->value = value;

			//覆写完成
			return 1;
		}
		rover = rover->next;
	}

	//没有关键字为Key的节点，则新建一个并加入链表头部
	newentry = (HashTableEntry*)malloc(sizeof(HashTableEntry));
	if (newentry == NULL)
		return 0;
	newentry->key = key;
	newentry->value = value;

	//插入序号为index的链表头部
	newentry->next = hash_table->table[index];
	hash_table->table[index] = newentry;
	
	//链表中节点的数量增加1
	hash_table->entries++;

	return 1;
}

static int hash_table_enlarge(HashTable* hash_table)
{
	HashTableEntry** old_table;
	unsigned int old_table_size;
	unsigned int old_prime_index;
	HashTableEntry* rover;
	HashTableEntry* next;
	unsigned int index;
	unsigned int i;

	//复制一份旧表结构并存储
	old_table = hash_table->table;
	old_table_size = hash_table->table_size;
	old_prime_index = hash_table->prime_index;

	//给新的表分配更大的内存
	++hash_table->prime_index;

	if (!hash_table_allocate_table(hash_table))
	{
		//为新表分配内存失败
		hash_table->table = old_table;
		hash_table->table_size = old_table_size;
		hash_table->prime_index = old_prime_index;
		return 0;
	}

	//把所有节点链接进新生成的表中
	for (i = 0; i < old_table_size; ++i)
	{
		rover = old_table[i];

		while (rover != NULL)
		{
			next = rover->next;

			//在新的表中找到原关键字对应的链表序号
			index = hash_table->hash_func(rover->key) % hash_table->table_size;

			//把节点接入序号是index的链表
			rover->next = hash_table->table[index];
			hash_table->table[index] = rover;

			//链表中的下一个
			rover = next;
		}
	}

	//释放旧表占用的内存
	free(old_table);
	return 1;
}

HashTableValue hash_table_lookup(HashTable* hash_table, HashTableKey key)
{
	HashTableEntry* rover;
	unsigned int index;

	//根据关键字找到对应链表头节点的下标
	index = hash_table->hash_func(key) % hash_table->table_size;

	//遍历下标为index的链表直到找到关键字为key的节点
	rover = hash_table->table[index];
	while (rover != NULL)
	{
		if (hash_table->equal_func(key, rover->key) != 0)
			//找到目标节点，返回数据
			return rover->value;
		rover = rover->next;
	}

	//未找到节点
	return HASH_TABLE_NULL;
}

int hash_table_remove(HashTable* hash_table, HashTableKey key)
{
	HashTableEntry** rover;
	HashTableEntry* entry;
	unsigned int index;
	int result;

	//根据关键字找到对应链表头节点的下标
	index = hash_table->hash_func(key) % hash_table->table_size;
	result = 0;
	rover = &hash_table->table[index];
	while (*rover != NULL)
	{
		if (hash_table->equal_func(key, (*rover)->key) != 0)
		{
			//找到将要被移除的节点
			entry = *rover;

			//从链表中脱离
			*rover = entry->next;

			//销毁节点结构
			hash_table_free_entry(hash_table, entry);
			hash_table->entries--;
			result = 1;
			break;
		}

		//探查链表的下一节点
		rover = &((*rover)->next);
	}
	return result;
}

int hash_table_free_entry(HashTable* hash_table, HashTableEntry* entry)
{
	return 0;
}

//初始化迭代器
void hash_table_iterate(HashTable* hash_table, HashTableIterator* iterator)
{
	unsigned int chain;
	iterator->hash_table = hash_table;
	iterator->next_entry = NULL;

	//找到第一个节点
	for (chain = 0; chain < hash_table->table_size; ++chain)
	{
		if (hash_table->table[chain] != NULL)
		{
			iterator->next_entry = hash_table->table[chain];
			iterator->next_chain = chain;
			break;
		}
	}
}

//判断目前节点在同一链表中是否还有后继节点
int hash_table_iter_has_more(HashTableIterator* iterator)
{
	return iterator->next_entry != NULL;
}

//迭代器进入下一节点，返回当前节点的数据
HashTableValue hash_table_iter_next(HashTableIterator* iterator)
{
	HashTableEntry* current_entry;
	HashTable* hash_table;
	HashTableValue result;
	unsigned int chain;
	hash_table = iterator->hash_table;

	//所有节点都已遍历完
	if (iterator->next_entry == NULL)
		return HASH_TABLE_NULL;

	//获得当前节点的数据
	current_entry = iterator->next_entry;
	result = current_entry->value;

	//判断当前链表中是否还有未被遍历的节点
	if (current_entry->next != NULL)
		//继续在当前链表遍历
		iterator->next_entry = current_entry->next;
	else
	{
		//从该链表中所有节点都被遍历，进入下一个链表
		chain = iterator->next_chain + 1;

		//初始化指针
		iterator->next_entry = NULL;
		while (chain < hash_table->table_size)
		{
			//判断链表中是否有节点
			if (hash_table->table[chain] != NULL)
			{
				iterator->next_entry = hash_table->table[chain];
				break;
			}
			//尝试下一个链表
			chain++;
		}
		iterator->next_chain = chain;
	}
	return result;
}