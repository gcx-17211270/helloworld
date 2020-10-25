/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 根据要求，暴力循环，好的一点是第二次for循环中只用判断相等，不用做加法验证，可以减少一定时间
 * 执行用时: 136 ms
 * 内存消耗: 5.9 MB
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ReturnSize = (int*) malloc (sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++)
    {
        int goal2 = target - nums[i];
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == goal2)
            {
                ReturnSize[0] = i;
                ReturnSize[1] = j;
                *returnSize = 2;
                return ReturnSize;
            }
        }
    }
    return NULL;
}