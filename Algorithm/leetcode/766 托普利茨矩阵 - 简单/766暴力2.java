/index.html
public class 766暴力2 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-23 00:03:38
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-23 00:03:39
 */
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 1; i < matrix.length; i++) {
            int k = 0;
            for (int j = 1; j < matrix[i].length; j++, k++) {
                //0,j
                if (matrix[i-1][k] != matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}