void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
    {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
}

/*
解题思路
1.贪心
	11. 想要总硬币数最少，肯定是优先用大面值硬币，所以对 coins 按从大到小排序
	12. 先丢大硬币，再丢会超过总额时，就可以递归下一层丢的是稍小面值的硬币

2.乘法对加法的加速
	21. 优先丢大硬币进去尝试，也没必要一个一个丢，可以用乘法算一下最多能丢几个

		k = amount / coins[c_index] 计算最大能投几个
		amount - k * coins[c_index] 减去扔了 k 个硬币
		count + k 加 k 个硬币

	如果因为丢多了导致最后无法凑出总额，再回溯减少大硬币数量
3.最先找到的并不是最优解
	31. 注意不是现实中发行的硬币，面值组合规划合理，会有奇葩情况
	32. 考虑到有 [1,7,10] 这种用例，按照贪心思路 10 + 1 + 1 + 1 + 1 会比 7 + 7 更早找到
	33. 所以还是需要把所有情况都递归完

4.ans 疯狂剪枝
	41. 贪心虽然得不到最优解，但也不是没用的
	42. 我们快速算出一个贪心的 ans 之后，虽然还会有奇葩情况，但是绝大部分普通情况就可以疯狂剪枝了

执行用时：8ms，在所有C++提交中击败了99.24%的用户
内存消耗：12.4MB，在所有C++提交中击败了77.84%的用户

作者：ikaruga
链接：https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/