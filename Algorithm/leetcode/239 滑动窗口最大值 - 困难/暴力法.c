/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int* returnNum = (int*)malloc(sizeof(int) * (numsSize + 1 - k));
    *returnSize = numsSize + 1 - k;
    for (int i = 0; i < numsSize + 1 - k; i++)
    {
        int max = maxNum(nums, i, k);
        returnNum[i] = max;
    }
    return returnNum;
}

int maxNum(int* nums, int Index, int length)
{
    int temp = nums[Index];
    for (int i = 1; i < length; i++)
        if (nums[i + Index] > temp)
            temp = nums[i + Index];
    return temp;
}