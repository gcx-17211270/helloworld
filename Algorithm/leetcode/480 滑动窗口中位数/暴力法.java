/*
 * @Descripttion: 将每一段取出来，排序，再判断出中位数，执行速度太慢无法通过测试用例
 * @version:        
 * @Author: 32353
 * @Date: 2021-02-04 00:05:09
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-04 00:06:43
 */
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] answer = new double[nums.length + 1 - k];
        int mid1 = 0, mid2 = 0;
        if (k % 2 == 0) {
            mid1 = k / 2 - 1;
            mid2 = k / 2;
        }
        else {
            mid1 = k / 2;
            mid2 = k / 2;
        }
        for (int i = 0; i < nums.length - k + 1; i++) {
            answer[i] = medianInWindow(nums, i, k, mid1, mid2);
            // System.out.println(mid1 +" " + mid2 + k);
        }
        return answer;
    }
    private double medianInWindow(int[] nums, int low, int k, int mid1, int mid2) {
        int[] temp = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = nums[i + low];
        }
        for (int i = 0; i < k; i++) 
            for (int j = i + 1; j < k; j++) {
                if (temp[j] < temp[i]) {
                    int tmp = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tmp;
                }
            }
        return ((long)temp[mid1] + temp[mid2]) / 2.0;    //因为有一个测试用例是2147……如果不是long就会溢出
    }
}