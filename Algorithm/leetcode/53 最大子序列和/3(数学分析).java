/**
 * 我们来通过数学分析来看一下这个题目。

我们定义函数 S(i) ，它的功能是计算以 0（包括 0）开始加到 i（包括 i）的值。

那么 S(j) - S(i - 1) 就等于 从 i 开始（包括 i）加到 j（包括 j）的值。

我们进一步分析，实际上我们只需要遍历一次计算出所有的 S(i), 其中 i 等于 0,1,2….,n-1。
然后我们再减去之前的 S(k),其中 k 等于 0，1，i - 1，中的最小值即可。 因此我们需要
用一个变量来维护这个最小值，还需要一个变量维护最大值。

这种算法的时间复杂度 O(N), 空间复杂度为 O(1)。

其实很多题目，都有这样的思想， 比如之前的《每日一题 - 电梯问题》。


 */
public class 3(数学分析) {
    
}
class MaxSumSubarray {
    public int maxSubArray3(int[] nums) {
        int maxSum = nums[0];
        int sum = 0;
        int minSum = 0;
        for (int num : nums) {
          // prefix Sum
          sum += num;
          // update maxSum
          maxSum = Math.max(maxSum, sum - minSum);
          // update minSum
          minSum = Math.min(minSum, sum);
        }
        return maxSum;
    }
  }