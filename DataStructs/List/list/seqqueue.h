#ifndef __SEQQUEUE_H_HELLO_QIU__
#define __SEQQUEUE_H_HELLO_QIU__


#ifdef _cpluscplus
extern "C"
{
#endif
	//���е�����ָ��
	typedef void* SeqQueueValue;

	//����ʵ�ֶ��еĽṹ
	typedef struct _SeqQueue SeqQueue;

	struct _SeqQueue
	{
		SeqQueueValue* array;
		int len;
	};

	//�½�һ������
	SeqQueue* seqqueue_new(void);

	//�ͷ�һ������ռ�õ��ڴ�
	void seqqueue_free(SeqQueue* seqqueue);

	//������м�����Ԫ��
	int seqqueue_push(SeqQueue* seqqueue, SeqQueueValue data);

	//�Ƴ���ͷ��Ԫ�أ������ظ�Ԫ�ص�ֵ
	SeqQueueValue sequeue_pop(SeqQueue* seqqueue);

	//���ض����е�Ԫ�ظ���
	int seqqueue_length(SeqQueue* seqqueue);

	//�ж϶����Ƿ�Ϊ��
	int seqqueue_is_empty(SeqQueue* seqqueue);

	//�ж϶����Ƿ�����
	int seqqueue_is_full(SeqQueue* seqqueue);

	//���ض�ͷԪ��
	SeqQueueValue seqqueue_peek(SeqQueue* seqqueue);

	//���������ȫ��Ԫ��
	void seqqueue_clear(SeqQueue* seqqueue);
#ifdef _cpluscplus
}
#endif

#endif