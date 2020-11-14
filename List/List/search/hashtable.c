#include "hashtable.h"

// hash_table_allocate_table���ڲ�������δд��ͷ�ļ��У�����幦������ɢ�б�����ʱ��ɢ�б�����ڴ�
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

	//����һ���ڴ�ռ�
	hash_table = (HashTable*)malloc(sizeof(HashTable));
	if (hash_table == NULL)
		return NULL;
	hash_table->hash_func = hash_func;
	hash_table->equal_func = equal_func;
	hash_table->key_free_func = NULL;
	hash_table->value_free_func = NULL;
	hash_table->entries = 0;
	hash_table->prime_index = 0;

	//��ÿ���ڵ�����ڴ�ռ䣬�ڵ�����Ϊtable_size
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

	//������нڵ���࣬��ͻ�Ŀ���������ɢ�б�Ĳ���Ч���½�����ʱ�����Ĵ�С
	if ((hash_table->entries * 3 / hash_table->table_size) > 0)
		if (!hash_table_enlarge(hash_table))
			//�����ڴ�ʧ��
			return 0;

	//���ݹؼ����ҵ���Ӧ����ͷ�ڵ���±�
	index = hash_table->hash_func(key) % hash_table->table_size;

	//�������������������Ƿ�����ͬ�ؼ��ֵĽڵ㣬���򸲸ǣ��������
	rover = hash_table->table[index];
	while (rover != NULL)
	{
		if (hash_table->equal_func(rover->key, key) != 0)
		{
			//���ҵ���ͬ�ؼ��֣����������ݸ�д�ڵ�
			//������ͷ���ֵ�͹ؼ����ڴ�ĺ�������ô�ͷž��ڴ棬��������
			if (hash_table->value_free_func != NULL)
				hash_table->value_free_func(rover->value);
			if (hash_table->key_free_func != NULL)
				hash_table->key_free_func(rover->key);
			rover->key = key;
			rover->value = value;

			//��д���
			return 1;
		}
		rover = rover->next;
	}

	//û�йؼ���ΪKey�Ľڵ㣬���½�һ������������ͷ��
	newentry = (HashTableEntry*)malloc(sizeof(HashTableEntry));
	if (newentry == NULL)
		return 0;
	newentry->key = key;
	newentry->value = value;

	//�������Ϊindex������ͷ��
	newentry->next = hash_table->table[index];
	hash_table->table[index] = newentry;
	
	//�����нڵ����������1
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

	//����һ�ݾɱ�ṹ���洢
	old_table = hash_table->table;
	old_table_size = hash_table->table_size;
	old_prime_index = hash_table->prime_index;

	//���µı���������ڴ�
	++hash_table->prime_index;

	if (!hash_table_allocate_table(hash_table))
	{
		//Ϊ�±�����ڴ�ʧ��
		hash_table->table = old_table;
		hash_table->table_size = old_table_size;
		hash_table->prime_index = old_prime_index;
		return 0;
	}

	//�����нڵ����ӽ������ɵı���
	for (i = 0; i < old_table_size; ++i)
	{
		rover = old_table[i];

		while (rover != NULL)
		{
			next = rover->next;

			//���µı����ҵ�ԭ�ؼ��ֶ�Ӧ���������
			index = hash_table->hash_func(rover->key) % hash_table->table_size;

			//�ѽڵ���������index������
			rover->next = hash_table->table[index];
			hash_table->table[index] = rover;

			//�����е���һ��
			rover = next;
		}
	}

	//�ͷžɱ�ռ�õ��ڴ�
	free(old_table);
	return 1;
}

HashTableValue hash_table_lookup(HashTable* hash_table, HashTableKey key)
{
	HashTableEntry* rover;
	unsigned int index;

	//���ݹؼ����ҵ���Ӧ����ͷ�ڵ���±�
	index = hash_table->hash_func(key) % hash_table->table_size;

	//�����±�Ϊindex������ֱ���ҵ��ؼ���Ϊkey�Ľڵ�
	rover = hash_table->table[index];
	while (rover != NULL)
	{
		if (hash_table->equal_func(key, rover->key) != 0)
			//�ҵ�Ŀ��ڵ㣬��������
			return rover->value;
		rover = rover->next;
	}

	//δ�ҵ��ڵ�
	return HASH_TABLE_NULL;
}

int hash_table_remove(HashTable* hash_table, HashTableKey key)
{
	HashTableEntry** rover;
	HashTableEntry* entry;
	unsigned int index;
	int result;

	//���ݹؼ����ҵ���Ӧ����ͷ�ڵ���±�
	index = hash_table->hash_func(key) % hash_table->table_size;
	result = 0;
	rover = &hash_table->table[index];
	while (*rover != NULL)
	{
		if (hash_table->equal_func(key, (*rover)->key) != 0)
		{
			//�ҵ���Ҫ���Ƴ��Ľڵ�
			entry = *rover;

			//������������
			*rover = entry->next;

			//���ٽڵ�ṹ
			hash_table_free_entry(hash_table, entry);
			hash_table->entries--;
			result = 1;
			break;
		}

		//̽���������һ�ڵ�
		rover = &((*rover)->next);
	}
	return result;
}

int hash_table_free_entry(HashTable* hash_table, HashTableEntry* entry)
{
	return 0;
}

//��ʼ��������
void hash_table_iterate(HashTable* hash_table, HashTableIterator* iterator)
{
	unsigned int chain;
	iterator->hash_table = hash_table;
	iterator->next_entry = NULL;

	//�ҵ���һ���ڵ�
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

//�ж�Ŀǰ�ڵ���ͬһ�������Ƿ��к�̽ڵ�
int hash_table_iter_has_more(HashTableIterator* iterator)
{
	return iterator->next_entry != NULL;
}

//������������һ�ڵ㣬���ص�ǰ�ڵ������
HashTableValue hash_table_iter_next(HashTableIterator* iterator)
{
	HashTableEntry* current_entry;
	HashTable* hash_table;
	HashTableValue result;
	unsigned int chain;
	hash_table = iterator->hash_table;

	//���нڵ㶼�ѱ�����
	if (iterator->next_entry == NULL)
		return HASH_TABLE_NULL;

	//��õ�ǰ�ڵ������
	current_entry = iterator->next_entry;
	result = current_entry->value;

	//�жϵ�ǰ�������Ƿ���δ�������Ľڵ�
	if (current_entry->next != NULL)
		//�����ڵ�ǰ�������
		iterator->next_entry = current_entry->next;
	else
	{
		//�Ӹ����������нڵ㶼��������������һ������
		chain = iterator->next_chain + 1;

		//��ʼ��ָ��
		iterator->next_entry = NULL;
		while (chain < hash_table->table_size)
		{
			//�ж��������Ƿ��нڵ�
			if (hash_table->table[chain] != NULL)
			{
				iterator->next_entry = hash_table->table[chain];
				break;
			}
			//������һ������
			chain++;
		}
		iterator->next_chain = chain;
	}
	return result;
}