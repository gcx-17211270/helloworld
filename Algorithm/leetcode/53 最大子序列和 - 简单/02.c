/**
 * 时间复杂度 O(N), 空间复杂度为 O(1)
*/

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int thissum, maxsum, j;
    thissum = maxsum = 0;
    for (j = 0; j < numsSize; j++)
    {
        thissum += nums[j];
        if (thissum > maxsum)
            maxsum = thissum;
        else if (thissum < 0)
            thissum = 0;
    }
    //处理全负数情况
    if (maxsum == 0)
        return max(nums, numsSize);
    return maxsum;
}
int max(int* nums, int numsSize)
{
    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max) max = nums[i];
    }
    return max;
}