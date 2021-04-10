public class 动态规划解法 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-04 00:21:44
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-04 00:23:06
 */
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j]);
                dp[i][j] = Math.max(dp[i][j - 1], dp[i][j]);
            }
        }
        return dp[m][n];
    }
}