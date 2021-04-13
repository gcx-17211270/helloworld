/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-11 12:05:21
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-11 12:05:36
 */

class Solution {
    public int nthUglyNumber(int n) {
        int nth = 0, i = 1;
        while (true) {
            nth += isUgly(i) ? 1 : 0;
            if (nth == n) {
                break;
            }
            i++;
        }
        return i;
    }
    private boolean isUgly(int num) {
        if (num <= 0) return false;
        while ((num & 1) == 0) num = num >> 1;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        if (num == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}