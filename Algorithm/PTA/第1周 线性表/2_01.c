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
    k = scanf("%d", &k);
    int nums[k];
    for (int i = 0; i < k; i++)
        nums[i] = scanf("%d", &nums[i]);
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
    for (int i = 1; i < len; i++)
    {
        b[i] = b[i - 1] + nums[i];
    }
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; i++)
        {
            int temp = b[j] - b[i];
            if (temp > res.maxSum)
            {
                res.maxSum = temp;
                res.begin = i;
                res.end = j;
            }
        }
    return res;
}
