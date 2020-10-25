#include <stdio.h>

typedef  struct 
{
    int maxSum;
    int begin;
    int end;
}result;

result maxSumSubarray(int* nums, int len);

int main()
{
    int k;
    if(!scanf("%d", &k))
        return 1;
    int nums[k];
    for (int i = 0; i < k; i++)
        if(!scanf("%d", &nums[i]))
            return 1;
    result res = maxSumSubarray(nums, k);
    printf("%d %d %d\n", res.maxSum, res.begin, res.end);
    return 0;
}

result maxSumSubarray(int* nums, int len)
{
    result res;
    res.maxSum = nums[0];
    res.begin = 0;
    res.end = 0;
    int b[len];
    b[0] = nums[0];
    //10
	//-10 1 2 3 4 -5 -23 3 7 -21
    for (int i = 1; i < len; i++)
    {
        b[i] = b[i - 1] + nums[i];
        if (b[i] > res.maxSum)
        {
        	res.maxSum = b[i];
        	res.begin = 0;
        	res.end = i;
		}
    }
    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
        {
            int temp = b[j] - b[i];
            if (temp > res.maxSum)
            {
                res.maxSum = temp;
                res.begin = i + 1;
                res.end = j;
            }
        }
    return res;
}
