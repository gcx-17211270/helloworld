/*
* 数据结构：顺序表队列
**/

#include <stdio.h>
#include "ArrayList.h"
#include "seqqueue.h"

//数组的长度
#define MaxQueueSize 20

SeqQueue* seqqueue_new(void)
{
	SeqQueue* seqqueue = (SeqQueue*)malloc(sizeof(SeqQueue));
	seqqueue->array = (SeqQueueValue*)malloc(sizeof(SeqQueueValue) * MaxQueueSize);
	seqqueue->len = 0;
	return seqqueue;
}

void seqqueue_free(SeqQueue* seqqueue)
{
	int i = 0;
	for (i = 0; i < seqqueue->len; i++)
	{
		free(seqqueue->array[i]);
	}
	free(seqqueue);
}

int seqqueue_push(SeqQueue* seqqueue, SeqQueueValue data)
{
	return arraylist_append(seqqueue, data);
}

SeqQueueValue sequeue_pop(SeqQueue* seqqueue)
{
	SeqQueueValue result = seqqueue->array[0];
	arraylist_remove(seqqueue, 0);
	return result;
}

int seqqueue_length(SeqQueue* seqqueue)
{
	return seqqueue->len;
}

int seqqueue_is_empty(SeqQueue* seqqueue)
{
	return seqqueue->len == 0;
}

int seqqueue_is_full(SeqQueue* seqqueue)
{
	return seqqueue->len == MaxQueueSize;
}

SeqQueueValue seqqueue_peek(SeqQueue* seqqueue)
{
	return seqqueue->array[0];
}

void seqqueue_clear(SeqQueue* seqqueue)
{
	seqqueue->len = 0;
}