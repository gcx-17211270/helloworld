/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-05 00:27:54
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-05 00:31:10
 */
class Solution {
    public int numRabbits(int[] answers) {
        if (answers == null) {
            return 0;
        }
        int num = 0;
        //key是兔子相同数目的种数
        //value是这种数目兔子已知的只数
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == 0) {
                num++;
                continue;
            }
            if (!map.containsKey(answers[i])) {
                map.put(answers[i], 1);
            }
            else {
                map.replace(answers[i], map.get(answers[i]) + 1);
            }
        }
        for (int key : map.keySet()) {
            //在图中有key的则至少有一只相同的
            //每种颜色的兔子可以有最多(1, key + 1)只
            //如果超出这个范围则说明至少有第其他颜色
            int color = 1 + (map.get(key) - 1) / (1 + key);
            //用颜色的数目乘以这个颜色兔子的数目就可以得到结果
            num = num + color * (1 + key);
        }
        return num;
    }
}
public class 用图存储相同数量兔子的数目 {
    
}
