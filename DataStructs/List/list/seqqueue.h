#ifndef __SEQQUEUE_H_HELLO_QIU__
#define __SEQQUEUE_H_HELLO_QIU__


#ifdef _cpluscplus
extern "C"
{
#endif
	//队列的数据指针
	typedef void* SeqQueueValue;

	//数组实现队列的结构
	typedef struct _SeqQueue SeqQueue;

	struct _SeqQueue
	{
		SeqQueueValue* array;
		int len;
	};

	//新建一个队列
	SeqQueue* seqqueue_new(void);

	//释放一个队列占用的内存
	void seqqueue_free(SeqQueue* seqqueue);

	//向队列中加入新元素
	int seqqueue_push(SeqQueue* seqqueue, SeqQueueValue data);

	//移除队头的元素，并返回该元素的值
	SeqQueueValue sequeue_pop(SeqQueue* seqqueue);

	//返回队列中的元素个数
	int seqqueue_length(SeqQueue* seqqueue);

	//判断队列是否为空
	int seqqueue_is_empty(SeqQueue* seqqueue);

	//判断队列是否已满
	int seqqueue_is_full(SeqQueue* seqqueue);

	//返回队头元素
	SeqQueueValue seqqueue_peek(SeqQueue* seqqueue);

	//清除队列中全部元素
	void seqqueue_clear(SeqQueue* seqqueue);
#ifdef _cpluscplus
}
#endif

#endif