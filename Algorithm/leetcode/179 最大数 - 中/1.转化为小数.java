/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-12 10:46:59
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-12 10:47:01
 */
/index.html
public class 1.转化为小数 {
    
}

class Solution {
    public String largestNumber(int[] nums) {
        double[] order = new double[nums.length];
        Map<Double, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            order[i] = nums[i];
            //但是这样1和10的结果是一样的，而且在插入图中会覆盖掉一个值
            //但实际上1的优先级显然大于10
            while (order[i] >= 1) {
                order[i] = order[i] * 1.0 / 10;
            }
            map.put(order[i], i);
        }
        StringBuffer str = new StringBuffer("");
        while (map != null) {
            double key = getMax(map);
            if (key != Double.MIN_VALUE){
                System.out.println(key + " " + map.get(key));
                str.append(nums[map.get(key)]);
                map.remove(key, map.get(key));
            }
            else {
                break;
            }
        }
        return str.toString();
    }

    private double getMax(Map<Double, Integer> map) {
        double res = Double.MIN_VALUE;
        for (double key : map.keySet()) {
            if (key > res) {
                res = key;
            }
        }
        return res;
    }
}