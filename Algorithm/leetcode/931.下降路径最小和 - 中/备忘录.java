/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-28 14:12:05
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-28 14:12:06
 */
/index.html
public class 备忘录 {
    
}
class Solution {
    int[][] memo;
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int res = Integer.MAX_VALUE;
        memo = new int[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(memo[i], 66666);
        for (int j = 0; j < n; j++)
            res = Math.min(res, dp(matrix, n - 1, j));
        return res;
    }
    private int dp(int[][] matrix, int i, int j) {
        if (i < 0 || j < 0 
            || i >= matrix.length
            || j >= matrix[0].length)
            return 999;
        if (i == 0)
            return matrix[i][j];
        //查询备忘录
        if (memo[i][j] != 66666)
            return memo[i][j];
        //进行状态转移
        memo[i][j] = matrix[i][j] + min(
            dp(matrix, i - 1, j),
            dp(matrix, i - 1, j - 1),
            dp(matrix, i - 1, j + 1)
        );
        return memo[i][j];
    }
    private int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}