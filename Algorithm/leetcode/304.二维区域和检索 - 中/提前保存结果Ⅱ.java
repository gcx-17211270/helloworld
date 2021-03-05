/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-03 00:14:56
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-03 00:15:29
 */
/index.html
public class 提前保存结果Ⅱ {
    
}

class NumMatrix {
    int[][] matrix;
    int[][] presum;
    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
        int m = matrix.length;
        int n = 0;
        if (m != 0) n = matrix[0].length;
        presum = new int[m][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) 
                presum[i][j] = presum[i][j - 1] + matrix[i][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                presum[i][j] += presum[i - 1][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n; j++)
                System.out.print(presum[i][j] + " ");
            System.out.println();
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        //这个范围具体怎么表示值得商榷
        return presum[row2][col2 + 1] + presum[row1][col1] - presum[row1][col2 + 1] - presum[row2][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
