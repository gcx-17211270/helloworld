class Solution:
    def numTeams(self, rating: List[int]) -> int:
        
        def func(nums):
            dp = [0] * len_
            res = 0
            for i in range(1, len_):
                idx = i - 1
                while idx >= 0:
                    if nums[i] > nums[idx]:
                        dp[i] += 1
                        if dp[idx] > 0:
                            res += dp[idx]
                    idx -= 1
            return res
            
        len_ = len(rating)
        return func(rating[::-1]) + func(rating)   

'''
执行用时：80ms在所有Python3提交中击败了100%的用户
内存消耗：13.8MB，在所有Python3提交中击败了100%的用户
1.更新dp的同时，更新res；
2.dp[i]记录的是第i个数之前比其值小的数的个数；
3.两层判断，如果nums[i] > nums[idx], 更新dp[i]，其次，如果dp[idx]>0则再更新res。因为此时，num[i]已经大于nums[idx]，再算上一个比nums[idx]小的数，就构成了一个3个数的升序，这样的组合有dp[idx]；
另外的一种情况，将数组逆序即可。

作者：tike5
链接：https://leetcode-cn.com/problems/count-number-of-teams/solution/on2shi-jian-fu-za-du-de-dong-tai-gui-hua-shuang-ba/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''