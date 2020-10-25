/**
 * 根据题意暴力循环
 * 执行用时: 220 ms
 * 内存消耗: 5.8 MB
*/

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}