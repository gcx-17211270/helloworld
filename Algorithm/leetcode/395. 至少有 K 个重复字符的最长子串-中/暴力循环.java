/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-01 09:48:13
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-01 09:48:29
 */
/index.html
public class 暴力循环 {
    
}
class Solution {
    public int longestSubstring(String s, int k) {
        int longestSub = 0;
        char[] s2 = s.toCharArray();
        for (int len = k; len <= s2.length; len++) {
            //s2[i…i+len-1]是现在的数组
            for (int i = 0; i + len <= s2.length; i++) {
                int[] temp = new int[26];
                for (int j = 0; j < 26; j++)
                    temp[j] = 0;
                for (int j = 0; j < len; j++) {
                    temp[(int)(s2[i + j] - 'a')]++;
                }
                int j = 0;
                for (; j < 26; j++) {
                    if (temp[j] != 0 && temp[j] < k)
                        break;
                }
                if (j == 26)
                    longestSub = Math.max(longestSub, len);
            }
        }
        return longestSub;
    }
}
