/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-17 02:47:55
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-17 02:47:56
 */
/index.html
public class 暴力法 {
    
}

class Solution {
    int top = 0, left = 0;
    int bottom, right;
    int[][] matrix2;
    public List<Integer> spiralOrder(int[][] matrix) {
        bottom = matrix.length;
        right = matrix[0].length;
        int len = bottom * right;
        matrix2 = new int[bottom][right];
        init(matrix2);
        MovePos mp = new MovePos(0, 0);
        List<Integer> ls = new ArrayList<Integer>();
        while (len != 0) {
            System.out.println(mp.x + " " + mp.y);
            ls.add(matrix[mp.x][mp.y]);
            turn(mp);
            len--;
        }
        return ls;
    }
    private void turn(MovePos mp) {
        //已知top left bottom right，即盒子的尺寸
        //已知现在的坐标mp.x mp.y，如何更改下一步的坐标呢？
        int deriction = matrix2[mp.x][mp.y];
        switch(deriction) {
            case 1 : 
                mp.y++;break;
            case 2 :
                mp.x++;break;
            case 3 :
                mp.y--;break;
            case 4 :
                mp.x--;break;
        }
    }
    //matrix2矩阵存储一个矩阵中各个点下一步应该有的状态
    private void init(int[][] matrix2) {
        int len = bottom * right, i = 0, j = 0;
        bottom -= 1;
        right -= 1;
        //数字代表这个点的下一个运动方向
        final int RIGHT = 1;
        final int DOWN = 2;
        final int LEFT = 3;
        final int UP = 4;
        while (len >= 0) {
            //System.out.println(i + " " + j + " " + len);
            //这几个if也不是事儿啊，if里面的if成立后，要到下一个if才能确定matrix2[i][j]中的值，这对于一些来说是有问题的，应该把这几种情况分开，弄成个switch
            if (j != right && i == top){
                matrix2[i][j] = RIGHT;
                j++;
                if (j == right) {
                    len--;
                    top++;
                }
            }
            if (j == right && i != bottom) {
                matrix2[i][j] = DOWN;
                i++;
                if (i == bottom) {
                    len--;
                    right--;
                }
            }
            if (j != left && i == bottom) {
                matrix2[i][j] = LEFT;
                j--;
                if (j == left){
                    len--;
                    bottom--;
                }
            }
            if (j == left && i != top) {
                matrix2[i][j] = UP;
                i--;
                if (i == top) {
                    len--;
                    left++;
                }
            }
            len--;
        }
        for (int m = 0; m < matrix2.length; m++) {
            for (int n = 0; n < matrix2[0].length; n++)
                System.out.print(matrix2[m][n] + " ");
            System.out.println();
        }
    }
}

//当前位置
class MovePos {
    int x, y;
    public MovePos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}