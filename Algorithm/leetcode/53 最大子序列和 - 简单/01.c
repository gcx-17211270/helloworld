/**
 * 暴力法2
 * 舍弃了记录所有子序列和，节省了空间
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 执行用时：368 ms, 在所有 C 提交中击败了19.16%的用户
 * 内存消耗：5.9 MB, 在所有 C 提交中击败了52.65%的用户
*/
int maxSubArray(int* nums, int numsSize){
    int maxNum = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        for (int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            maxNum = max(maxNum, sum);
        }
    }
    return maxNum;
}
int max(int a, int b)
{
    return a > b ? a : b;
}