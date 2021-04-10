/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-04 00:21:31
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-04 00:22:45
 */
//相当于是匹配所有较短字符串中连续子串，这样得到的结果是不正确的

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int shorter = text1.length() < text2.length() ? 1 : 2;
        int len = 0;
        //text1较短，则找出text1的所有子序列，去同text2匹配
        if (shorter == 1) {
            len = compareText1ToText2(text1, text2);
        }
        //text2较短，则找出text2的所有子序列，去同text1匹配
        else {
            len = compareText1ToText2(text2, text1);
        }
        return len;
    }
    private int compareText1ToText2(String source, String destination) {
        //这里描述如何从短的source字符串中匹配到最长的公共子序列到destination字符串
        //m描述source字符串的起始匹配位置，n描述当前匹配位置
        int m = 0, n = 0;
        int len = 0;
        while (m < source.length()) {
            int len1 = 0, mm = 0, nn = 0;
            n = m;

            while (mm < destination.length() && n < source.length()) {
                if (source.charAt(n) == destination.charAt(mm)) {
                    len1++;
                    n++;
                }
                mm++;
            }

            if (len1 > len) {
                len = len1;
            }
            m++;
        }
        return len;
    }
}