/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-23 22:06:42
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-23 22:10:53
 */
/index.html
public class 暴力 {
    
}

class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int maxSat = 0;
        int maxTemp = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) 
                maxSat += customers[i];
            int temp = 0;
            for (int j = 0; j < X; j++) {
                if (i + j >= customers.length)
                    continue;
                if (grumpy[i + j] == 1)
                    temp += customers[i + j];
            if (maxTemp < temp) 
                maxTemp = temp;
            }
        }
        return maxSat + maxTemp;
    }
}
