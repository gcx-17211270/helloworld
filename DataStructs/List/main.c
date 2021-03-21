//使用#define来进行相应的操作

//链表求和
//#define _ADT_HELLO_QIU_

//逆波兰表达式求值
//#define _EVALRPN_HELLO_QIU_

//顺序表
//#define _ArrayList_HELLO_QIU_

//两数和
//#define _ADD_TWO_NUM_H_HELLO_QIU_

//十字邻接矩阵
//#define _OLMATRIX_HELLO_QIU_

//leetcode 5546. 按键持续时间最长的键
//#define _SLOWEST_KEY_HELLO_QIU_

//各种排序
//#define _SORT_HELLO_QIU_

//基数排序
//#define _CARDINAL_SORT_HELLO_QIU_

//表达式树
//#define _EXPRESSION_TREE_HELLO_QIU_

//临时调试
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

#ifdef _EXPRESSION_TREE_HELLO_QIU_
#include "tree/expression_tree.h"
#endif

int main(int argc, int* argv[])
{
	printf("%s %s\n", __DATE__, __TIME__);
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

#ifdef _EXPRESSION_TREE_HELLO_QIU_
	create_expression_tree_callback();
#endif

#ifdef _TEMP_DEBUG_HELLO_QIU_
	temp_callback();
#endif
	return 0;
}

