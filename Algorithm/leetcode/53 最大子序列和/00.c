/**
 * 暴力法，计算出所有可能的子序列和，选出最大的
 * 由于使用了结构体记录所有的和，
 * 时间复杂度:O(n^2)
 * 空间复杂度:O(n)
 * 执行用时: 452 ms
 * 内存消耗: 6 MB
*/
typedef struct
{
    int lo;
    int hi;
    int value;
} coord;

int maxSubArray(int* nums, int numsSize){
    coord coo[numsSize];
    int result = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        coo[i].lo = i;
        coo[i].hi = i;
        coo[i].value = nums[i];
        int value = nums[i];
        for (int j = i + 1; j < numsSize; j++)
        {
            value += nums[j];
            if (value > coo[i].value)
            {
                coo[i].hi = i;
                coo[i].value = value;
            }
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (coo[i].value > result)
            result = coo[i].value;
    }
    return result;
}