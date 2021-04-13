/index.html
public class 寻找乘积第n大的数 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-11 12:44:34
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-11 12:44:36
 */

class Solution {
    public static ArrayList<Integer> arr = null;
    public static final int NUM2 = 2;
    public static final int NUM3 = 3;
    public static final int NUM5 = 5;
    public int nthUglyNumber(int n) {
        arr = new ArrayList<>();
        arr.add(1);
        int i = 0, j = 0, k = 0, m = 0;;
        for (; m < n; m++) {
            //System.out.println("i:" + i + " j:" + j + " k:" + k);
            int nth = min(NUM2 * arr.get(i), NUM3 * arr.get(j), NUM5 * arr.get(k));
            switch (nth) {
                case 1:
                    int temp = NUM2 * arr.get(i);
                    if (!arr.contains(temp)){
                        arr.add(temp);
                    }
                    else {
                        m--;
                    }
                    i++;
                    break;
                case 2:
                    temp = NUM3 * arr.get(j);
                    if (!arr.contains(temp)){
                        arr.add(temp);
                    }
                    else {
                        m--;
                    }
                    j++;
                    break;
                case 3:
                    temp = NUM5 * arr.get(k);
                    if (!arr.contains(temp)){
                        arr.add(temp);
                    }
                    else {
                        m--;
                    }
                    k++;
                    break;
                default :
                    break;
            }
        }
        System.out.println(m);
        System.out.println(arr);
        return arr.get(m - 1);
    }
    private int min(int num1, int num2, int num3) {
        int temp = num1 < num2 ? num1 : num2;
        temp = temp < num3 ? temp : num3;
        if (temp == num1) return 1;
        else if (temp == num2) return 2;
        else if (temp == num3) return 3;
        else {
            System.out.println("这不可能");
            return 0;
        }
    }
}