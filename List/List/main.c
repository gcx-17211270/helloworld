//ʹ��#define��������Ӧ�Ĳ��������û�д�ִ�еĴ�����ֻ��.h��.c�ļ�

//�������
//#define _ADT_HELLO_QIU_

//�沨�����ʽ��ֵ
//#define _EVALRPN_HELLO_QIU_

//˳���
//#define _ArrayList_HELLO_QIU_

//������
//#define _ADD_TWO_NUM_H_HELLO_QIU_

//ʮ���ڽӾ���
//#define _OLMATRIX_HELLO_QIU_

//leetcode 5546. ��������ʱ����ļ�
//#define _SLOWEST_KEY_HELLO_QIU_

//��������
//#define _SORT_HELLO_QIU_

//��������
//#define _CARDINAL_SORT_HELLO_QIU_

//��ʱ����
#define _TEMP_DEBUG_HELLO_QIU_

#ifdef _EVALRPN_HELLO_QIU_
#include "algorithm/evalRPN.h"
#include <stdlib.h>
#endif

#ifdef _ADT_HELLO_QIU_
#include "list/ADT.h"
#endif

#ifdef _ArrayList_HELLO_QIU_
#include "list/ArrayList.h"
#endif

#ifdef _ADD_TWO_NUM_H_HELLO_QIU_
#include "algorithm/addTwoNum.h"
#endif

#ifdef _OLMATRIX_HELLO_QIU_
#include "matrix/olMatrix.h"
#endif

#ifdef _SORT_HELLO_QIU_
#include "sort/Sort.h"
#endif

#ifdef _CARDINAL_SORT_HELLO_QIU_
#include "sort/cardinal_sort.h"
#endif

#ifdef _TEMP_DEBUG_HELLO_QIU_
#include "temp.h"
#endif

#ifdef _SLOWEST_KEY_HELLO_QIU_
#include "algorithm/slowestKey.h"
#endif

int main(int argc, int* argv[])
{
#ifdef _ADT_HELLO_QIU_
	ADT_callback();
#endif

#ifdef _EVALRPN_HELLO_QIU_
	evalRPN_callback();
#endif

#ifdef _ArrayList_HELLO_QIU_
	ArrayList_callback();
#endif

#ifdef _ADD_TWO_NUM_H_HELLO_QIU_
	addTwoSum_callback();
#endif

#ifdef _OLMATRIX_HELLO_QIU_
	olMatrix_callback();
#endif

#ifdef _SLOWEST_KEY_HELLO_QIU_
	slowestKey_callback();
#endif

#ifdef _SORT_HELLO_QIU_
	sort_callback();
#endif

#ifdef _CARDINAL_SORT_HELLO_QIU_
	cardinal_sort_callback();
#endif

#ifdef _TEMP_DEBUG_HELLO_QIU_
	temp_callback();
#endif
	return 0;
}

