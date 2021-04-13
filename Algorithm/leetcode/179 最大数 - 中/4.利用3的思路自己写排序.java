/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-13 15:48:28
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-13 15:48:50
 */
/index.html
public class Solution {
    public String largestNumber(int[] nums) {
        //合法性
        if (nums == null || nums.length == 0) {
            return "";
        }
        //数字数组->字符数组  转化
        String[] strArr = new String[nums.length];
        for (int i = 0; i < strArr.length; i++) {
            strArr[i] = String.valueOf(nums[i]);
        }

        //冒泡排序为例
        for (int i = 0; i < strArr.length; i++) {
            for (int j = i + 1; j < strArr.length; j++) {
                if (compareTo(strArr[i], strArr[j]) == -1) {
                    String temp = strArr[i];
                    strArr[i] = strArr[j];
                    strArr[j] = temp;
                }
            }
        }
        //字符数组->字符串 转化
        StringBuilder sb = new StringBuilder();
        for (String aStrArr : strArr) {
            sb.append(aStrArr);
        }
        String result = sb.toString();
        //特殊情况 若干个零
        if (result.charAt(0) == '0') {
            result = "0";
        }
        return result;
    }

    private int compareTo(String str1, String str2) {
        long a1 = Long.valueOf(str1 + str2);
        long a2 = Long.valueOf(str2 + str1);
        if (a1 > a2) {
            return 1;
        } 
        else if (a1 < a2) {
            return -1;
        }
        return 0;
    }
}class 4.利用3的思路自己写排序 {
    
}
