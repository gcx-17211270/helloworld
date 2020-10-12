/**
 * 我们来思考一下这个问题， 看能不能将其拆解为规模更小的同样问题，并且能找出
递推关系。

我们不妨假设问题 Q(list, i) 表示 list 中以索引 i 结尾的情况下最大子序列和，
那么原问题就转化为 Q(list, i), 其中 i = 0,1,2…n-1 中的最大值。

我们继续来看下递归关系，即 Q(list, i)和 Q(list, i - 1)的关系，
即如何根据 Q(list, i - 1) 推导出 Q(list, i)。

如果已知 Q(list, i - 1)， 我们可以将问题分为两种情况，即以索引为 i 的元素终止，
或者只有一个索引为 i 的元素。

如果以索引为 i 的元素终止， 那么就是 Q(list, i - 1) + list[i]
如果只有一个索引为 i 的元素，那么就是 list[i]
分析到这里，递推关系就很明朗了，即Q(list, i) = Math.max(0, Q(list, i - 1)) + list[i]

这种算法的时间复杂度 O(N), 空间复杂度为 O(1)
 */
public class 2(动态规划) {
    
}
class MaximumSubarrayDP {
    public int maxSubArray(int[] nums) {
       int currMaxSum = nums[0];
       int maxSum = nums[0];
       for (int i = 1; i < nums.length; i++) {
         currMaxSum = Math.max(currMaxSum + nums[i], nums[i]);
         maxSum = Math.max(maxSum, currMaxSum);
       }
       return maxSum;
    }
  }
