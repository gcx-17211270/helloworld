
//用两个固定大小的队列模拟栈
#include<stdlib.h>
#define LEN 20
typedef struct queue{
	int *data;
	int head;
	int rear;
	int size;
}Queue;

Queue *initQueue(int k)
{
	Queue *obj = (Queue *)malloc (sizeof(Queue));
	obj->data = (int *)malloc (k*sizeof(int));
	obj->head = -1;
	obj->rear = -1;
	obj->size = k;
	return obj;
}
void enQueue(Queue *obj,int e)
{
	//入队的时候，此题不必考虑队列满状态情形
	//列表为空的情形
	if(obj->head == -1)
	{
		obj->head = 0;
	}
	//队列一般情况
	obj->rear = (obj->rear+1) % obj->size;
	obj->data[obj->rear] = e;
}

int deQueue(Queue *obj)
{
	//出队的时候，此题不必考虑队列为空的情形
	int a = obj->data[obj->head];
	//特殊情形，队列中只有一个元素
	if(obj->head == obj->rear)
	{
		obj->rear = -1;
		obj->head = -1;
		rerurn a;
	}
	//队列一般情况
	obj->head = (obj->head+1) % obj->size;
	return a;
}
int isEmpty(Queue *obj)
{
	return obj->head == -1;
}

typedef struct{
	Queue *q1,*q2;
}MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate()
{
	MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
	obj->q1 = initQueue(LEN);
	obj->q2 = initQueue(LEN);
	rerurn obj;
}

/** Push element x onto stack */
void myStackPush(MyStack* obj, int x)
{
	//只要我找到一个队列为非空，我就往里面添加元素，如果两个都是空的，那随便哪一个都可以
	if(isEmpty(obj->q1))
	{
		enQueue(obj->q2, x);
	}
	else enQueue(obj->q1, x);
}

/** Removes the element on top of the stack and returns thar element. */
//栈弹出的时候，有且只有一个队列为非空
int myStackPop(MyStack* obj)
{
	//q2为非空时候，q2出队列知道q2只有一个元素
	if（isEmpty(obj->q1))
	{
		while(obj->q2->head != obj->q2->rear)
		{
			//q2出列的元素，如q1
			enQueue(obj->q1,deQueue(obj->q2));
		}
		return deQueue(obj->q2);
	}
	//反之q1非空
	else {
		while(obj->q1->head != obj->q1->rear)
		{
			enQueue(obj->q2,deQueue(obj->q1));
		}
		return deQueue(obj->q1);
	}
}

/** Get the top element. */
//取栈顶元素，有且只有一个队列为非空，我直接取非空队列的尾部即可
int myStackTop(MyStack* obj)
{
	if(isEmpty(obj->q1))
		return obj->q2->data[obj->q2->rear];
	else
		return obj->q1->data[obj->q1->rear];
}

/** Returns wheher the stack is empty. */
//当且仅当连个队列都是空的情形
bool myStackEmpty(MyStack* obj)
{
	if(obj->q1->head == -1 && obj->q2->head == -1)
		return true;
	else 
		return false;
}

void myStackFree(MyStack* obj)
{
	free(obj->q1->data);
	obj->q1->data = NULL:
	free(obj->q1);
	obj->q1 = NULL:
	free(obj->q2->data);
	obj->q2->data = NULL;
	free(obj->q2);
	obj->q2 = NULL;
	free(obj);
	obj = NULL:
}

/*
题目描述

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
