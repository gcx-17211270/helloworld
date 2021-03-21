/*****************************************************************//**
 * \file   cardinal_sort.h
 * \brief  ʹ������ĵ�ʱ��Ӧ�ð�main.c��׺����Ϊmain.cpp����C++�﷨���������ͨ��
 * 
 * \author 32353
 * \date   November 2020-11-11
 *********************************************************************/
#ifndef __CARDINAL_SORT_HELLO_QIU__
#define __CARDINAL_SORT_HELLO_QIU__

#define _cpluscplus

#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM_OF_KEY 3			//�ؼ������������ֵ
#define RADIX 10					//�ؼ��ֻ�������ʱ��ʮ���������Ļ���
#define MAX_SPACE 10			

#define KeyType int
#define InfoType void*

	typedef struct StaticListNode
	{
		KeyType keys[MAX_NUM_OF_KEY];	//�ؼ���
		InfoType otheritems;			//����������
		int next;
	}StaticListNode;

	typedef struct StaticList
	{
		StaticListNode r[MAX_SPACE];	//��̬����Ŀ����ÿռ䣬r[0]Ϊͷ�ڵ�
		int keynum;						//��¼��ǰ�Ĺؼ��ָ���
		int recnum;						//��̬����ĵ�ǰ����
	}StaticList;

	typedef int ArrType[RADIX];			//ָ����������

	//��̬����list��r���м�¼�Ѱ�(keys[0],����,key[i-1]���򣬱��㷨����i���ؼ���key[i]����RADIX���ӱ�ʹͬһ�ӱ��м�¼keys[i]��ͬ
	//f[0,����, RADIX-1]��e[0,����,RADIX-1]�ֱ�ָ����ӱ��е�һ�������һ����¼
	void distribute(StaticListNode* r, int i, ArrType& f, ArrType& e);

	//���㷨��keys[i]��С����f[0,����,RADIX-1]��ָ���ӱ��������ӳ�һ������,e[0,����,RADIX]Ϊ���ӱ��βָ��
	void collect(StaticListNode* r, int i, ArrType& f, ArrType& e);

	//list�ǲ��þ�̬�����ʾ��˳���
	//��list����������ʹ��list��Ϊ���ؼ�����С���������̬����list.r[0]Ϊͷ�ڵ�
	void radix_sort(StaticList* list);

	void cardinal_sort_callback();

	void creat_keys(KeyType keys[MAX_NUM_OF_KEY], int val, int len);
	int get_keys(KeyType keys[], int len);

#endif