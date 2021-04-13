/index.html
public class 2.稍优化的暴力判断 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-11 12:06:31
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-11 12:07:59
 */

class Solution {
    ArrayList<Integer> arrayList = new ArrayList<>();
    public int nthUglyNumber(int n) {
        int nth = 0, i = 1;
        while (true) {
            nth += isUgly(i) ? 1 : 0;
            if (nth % 500 == 0) {
                System.out.println(arrayList);
            }
            if (nth == n) {
                break;
            }
            i++;
        }
        return i;
    }
    private boolean isUgly(int num) {
        int temp = num;
        if (num <= 0) return false;
        while ((num & 1) == 0) {
            if (arrayList.contains(num)) {
                arrayList.add(temp);
                return true;
            }
            num = num >> 1;
        }
        while (num % 3 == 0){
            if (arrayList.contains(num)) {
                arrayList.add(temp);
                return true;
            }
            num /= 3;
        } 
        while (num % 5 == 0) {
            if (arrayList.contains(num)) {
                arrayList.add(temp);
                return true;
            }
            num /= 5;
        }
        if (num == 1) {
            arrayList.add(temp);
            return true;
        }
        else {
            return false;
        }
    }
}
