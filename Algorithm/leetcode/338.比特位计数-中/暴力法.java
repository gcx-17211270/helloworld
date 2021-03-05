/index.html
public class 暴力法 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-05 22:55:03
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-05 22:55:33
 */

class Solution {
    public int[] countBits(int num) {
        int[] result = new int[num + 1];
        for (int i = 0; i <= num; i++)
            result[i] = getNum(i);
        return result;
    }
    private int getNum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 2;
            num /= 2;
        }
        return sum;
    }
}
