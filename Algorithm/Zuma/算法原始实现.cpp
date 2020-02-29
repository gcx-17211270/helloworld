/**
* @date 2020.02.29
* @time 16:48
* @author Gao Chengxin 
*/

#include<stdio.h>
int deal(char a[], int len);
int insert(char a[], int len, int key, char collor);
void show(char a[]);
int delete1(char a[], int len, int i);

int main()
{
	char str[1000];
	for(int i = 0; i < 1000; i++)
		str[i] = 0;
	int i = 0;
//	printf("Please enter a string:\n");
	str[i] = getchar();
	while(str[i] != '\n')
	{
		str[++i] = getchar();
//		printf("%c",str[i-1]);
	}
	int str_len = i;
	//完成第一步初始排列
	int length;
//	printf("\nPlease enter the length\n");
	scanf("%d", &length);
	//完成第二步记录回放长度 
	while(length)
	{
		int location = 0;
		static int i = 0;
		char collor = 'A';
//		printf("\nPlease enter the %dst skip\n",++i);
		scanf("%d %c", &location, &collor);
		str_len = insert(str, str_len, location, collor);	
		str_len = deal(str, str_len);
		show(str);
		length--;
	}
	return 0;
}

int deal(char a[], int len)
{
	int length = sizeof(a)/sizeof(char);
	for(int i = 0; i < length - 2; i++)
	{
		if(a[i]==a[i+1] && a[i]==a[i+2] && a[i+1] == a[i+2])
		{
			len=delete1(a, len, i);
			len=deal(a,len);
		}
	}
	return len;
}
int delete1(char a[], int len, int i)
{
	for(int t = i; t < len - 3; t++)
	{
		a[t] = a[t+3];
	}
	a[len - 3] = 0;
	a[len - 2] = 0;
	a[len - 1] = 0;
	len -= 3;
	return len;
}
int insert(char a[], int len, int key, char collor)
{
	len ++;
	for(int i = len ; i > key; i--)
	{
		a[i] = a[i - 1];
	}
	a[key] = collor;
	return len;
}
void show(char a[])
{
	int i = 0;
	while(a[i] != '\n')
	{
		printf("%c",a[i]);
		i++;
	}
}
