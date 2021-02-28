/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-02-25 23:38:36
 * @LastEditors: 32353
 * @LastEditTime: 2021-02-28 11:54:11
 */
public class 题解2 {
    
}
class Solution {
    public int longestSubarray(int[] nums, int limit) {

        PriorityQueue<Integer> minQueue = new PriorityQueue<>(Comparator.naturalOrder());
        PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Comparator.reverseOrder());

        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < nums.length && left < nums.length) {
            minQueue.add(nums[right]);
            maxQueue.add(nums[right]);

            if (maxQueue.peek() - minQueue.peek() <= limit) {
                ans = Math.max(ans, right - left + 1);
                right++;
                continue;
            }

            maxQueue.remove((Integer) nums[left]);
            minQueue.remove((Integer) nums[left]);
            left++;
            right++;
        }
        return ans;
    }
}