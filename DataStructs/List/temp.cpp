/*********************************************************************
 * @file   temp.cpp
 * @description   临时调试使用，可以任意更改
 * 
 * @author 32353
 * @date   2020-11-12 November
 *********************************************************************/
#include "temp.h"

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void temp_callback()
{
	//int a = 1, b = 2;
	//swap(a, b);
	//printf("a = %d b = %d\n", a, b);

	for (int i = 20; i < 10; i++)
	{
		printf("Error");
	}

	return;
}