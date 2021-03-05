/index.html
public class 改进位运算 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-05 22:58:19
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-05 22:58:48
 */

class Solution {
    public int[] countBits(int num) {
        int[] bits = new int[num + 1];
        for (int i = 0; i <= num; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }

    public int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }
}

