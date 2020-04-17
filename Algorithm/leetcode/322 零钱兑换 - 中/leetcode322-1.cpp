#include<stdio.h>
int coinChange(int* coins, int coinsSize, int amount); 
void quickSort(int* coins, int lo, int hi);
int partition(int* a, int lo, int hi);
int main()
{
	int coinsSize = 4;
	int coins[] = {2, 5, 10, 1};
	int amount = 27;
	int skip = coinChange(coins, coinsSize, amount);
	printf("%d",skip);
}

int coinChange(int* coins, int coinsSize, int amount){
    quickSort(coins, 0, coinsSize - 1);
    for(int i = 0; i < coinsSize; i++)
    	printf("%d ",coins[i]);
    printf("\n");
    int money = amount;
    int location = coinsSize - 1;
    int i = 0;
    while(money != 0)
    {
        money -= coins[location];
        if(money < 0)
        {
            money += coins[location];
            i--;
            location--;
        }
        if(location < 0) return -1;
        i++;
        printf("coin = %d i = %d \n",coins[location],i);
    }
    return i;
}
void quickSort(int* coins, int lo, int hi)
{
    if(hi <= lo) return;;
    int j = partition(coins, lo, hi);
    printf("j = %d a[j] = %d\n",j,coins[j]);
    quickSort(coins, lo, j - 1);
    quickSort(coins, j + 1, hi);
}
int partition(int* a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = a[lo];
    while(1)
    {
        while(a[++i] < v) if(i == hi) break;
        while(v < a[--j]) if(j == lo) break;
        if(i >= j) break;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[lo] = a[j];
    a[j] = v;
    return j;
}

