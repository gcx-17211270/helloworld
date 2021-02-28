public class 递归解法 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-28 11:50:12
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-28 11:50:14
 */
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < matrix[0].length; i++) {
            //从第一行任意元素起，寻找它下面的所有路径
            int temp = traveal(matrix, 0, i);
            result = result < temp ? result : temp;
        }
        return result;
    }
    private int traveal(int[][] matrix, int row, int col) {
        int left = 0, mid = 0, right = 0;
        if (row + 1 == matrix.length)
            return matrix[row][col];
        if (col - 1 >= 0) {
            left = matrix[row][col] + traveal (matrix, row + 1, col - 1);
        }
        else
            //只是想表示一个很大的数，如果直接是MAX_VALUE就容易越界
            left = Integer.MAX_VALUE / 2;
        mid = matrix[row][col] + traveal (matrix, row + 1, col);
        if (col + 1 < matrix[0].length) {
            right = matrix[row][col] + traveal (matrix, row + 1, col + 1);
        }
        else
            right = Integer.MAX_VALUE / 2;
        //System.out.println(row + " " + col + " " + left + " " + mid + " " + right);
        return min(left, mid, right);
    }
    private int min(int a, int b, int c) {
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }
}