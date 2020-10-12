/**
 * 我们来分析一下这个问题， 我们先把数组平均分成左右两部分。
 * 
 * 此时有三种情况：
 * 
 * 最大子序列全部在数组左部分最大子序列全部在数组右部分最大子序列横跨左右数组
 * 对于前两种情况，我们相当于将原问题转化为了规模更小的同样问题。
 * 对于第三种情况，由于已知循环的起点（即中点），我们只需要进行一次循环，分别找出
 * 左边和右边的最大子序列即可。
 * 所以一个思路就是我们每次都对数组分成左右两部分，然后分别计算上面三种情况的最大子序列和，
 * 取出最大的即可。
 * 
 * 执行用时：1 ms, 在所有 Java 提交中击败了95.96%的用户
 * 内存消耗：38.9 MB, 在所有 Java 提交中击败了47.70%的用户
 */
class MaximumsSubarrayDicideConquer
{
    public int maxSubArrayDividConquer(int[] nums)
    {
        if (nums == null || nums.length == 0)
            return 0;
        return helper(nums, 0, nums.length - 1);
    }
    private int helper(int[] nums, int l, int r)
    {
        if (l > r) return Integer.MIN_VALUE;
        int mid = (l + r) >>> 1;
        int left = helper(nums, l, mid - 1);
        int right = helper(nums, mid + 1, r);
        //left surfix maxSum start from index mid-1 to l
        int leftMaxSum = 0;
        int sum = 0;
        for (int i = mid - 1; i >= l; i--)
        {
            sum += nums[i];
            leftMaxSum = Math.max(leftMaxSum, sum);
        }
        //right prefix maxSum start from index mid+1 to r
        int rightMaxSum = 0;
        int sum = 0;
        for (int i = mid + 1; i <= r; i++)
        {
            sum += nums[i];
            rightMaxSum = Math.max(sum, rightMaxSum);
        }
        //max(left, right, crossSum)
        return Math.max(leftMaxSum + rightMaxSum + nums[mid], Math.max(left, right));
    }
}