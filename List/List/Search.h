//����ʹ�õĺ���

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
	//�ھ�̬���������ʱ�������²��ҷ���

	//�۰����
	int search_bin(StaticSearchTable st, KeyType key);

	//쳲���������
	int search_fab(StaticSearchTable st, KeyType key);

	//��ֵ����
	int search_int(StaticSearchTable st, KeyType key);
	int search_int_help(StaticSearchTable st, KeyType key, int lo, int hi);

	//�ֿ����
	int search_block(StaticSearchTable st, IndexOrderTable it, KeyType key);

#ifdef _cpluscplus
}
#endif
#endif