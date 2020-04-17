#define min(a,b) ((a) < (b) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount){
    int i, j, dp[amount + 1];
    dp[0] = 0;
    for(i = 1;i < amount + 1;++i)
    {
        dp[i] = INT_MAX;
        for(j = 0;j < coinsSize;++j)
        {
            if(i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

/*
执行用时 :48 ms, 在所有 C 提交中击败了50.30%的用户
内存消耗 :5.3 MB, 在所有 C 提交中击败了100.00%的用户
*/