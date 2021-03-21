/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-17 01:25:26
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-17 01:28:19
 */
class Solution {
    int len1, len2;
    public int numDistinct(String s, String t) {
        len1 = s.length();
        len2 = t.length();
        if (len1 < len2) return 0;
        if (len1 == len2) return s.equals(t) ? 1 : 0;
        if (len2 == 0) return 1;
        int num = 0;
        //s字符串中每个字符开始，统计所有可能
        for (int i = 0; i < len1 - len2 + 1; i++) {
            if (s.charAt(i) != t.charAt(0))
                continue;
            num += subNumDistinct(s, t, i, 1);
        }
        return num;
    }
    //参数含义：start表示现在已经匹配到s中的第i个字符(从0计数)，position表示t中已有匹配字符的数目(从1计数)
    private int subNumDistinct(String s, String t, int start, int position) {
        //统计完全匹配信息，position==pen2表示前面的字符已经完全匹配，后一个条件表示最后一个字母也完成匹配，从而加入统计中。
        if (position == len2 && s.charAt(start) == t.charAt(position - 1)) {
            //System.out.println(start + " " + position);
            return 1;
        }
        int num = 0; 
        for (int i = start + 1; i < len1; i++) {
            if (s.charAt(i) != t.charAt(position)) continue;
            num += subNumDistinct(s, t, i, position + 1);
        }
        return num;
    }
}