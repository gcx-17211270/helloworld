/**
 * 时间复杂度为 O(N*logN), 空间复杂度为 O(1)
 * 执行用时：8 ms, 在所有 C 提交中击败了73.98%的用户
 * 内存消耗：5.8 MB, 在所有 C 提交中击败了78.12%的用户
*/

#define MIN_VALUE -2147483647

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    //if (numsSize == 1) return nums[0];
    return helper(nums, 0, numsSize - 1);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int helper(int * nums, int lo, int hi)
{
    if (lo > hi) return MIN_VALUE;
    int mid = (lo + hi) / 2;
    int left = helper(nums, lo, mid - 1);
    int right = helper(nums, mid + 1, hi);
    //左侧最大
    int leftMax = 0;
    int leftSum = 0;
    for (int i = mid - 1; i >= lo; i--)
    {
        leftSum += nums[i];
        leftMax = max(leftMax, leftSum);
    }
    //右侧最大
    int rightMax = 0;
    int rightSum = 0;
    for (int i = mid + 1; i <= hi; i++)
    {
        rightSum += nums[i];
        rightMax = max(rightMax, rightSum);
    }
    return max(leftMax + rightMax + nums[mid], max(left, right));
}