/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-23 00:03:08
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-23 00:03:10
 */
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++) {
                if (i == 0 || j == 0)
                    continue;
                else {
                    if (matrix[i][j] != matrix[i - 1][j - 1])
                        return false;
                }
            }
        return true;
    }
}