/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-01-02 21:21:43
 * @LastEditors: 32353
 * @LastEditTime: 2021-01-02 21:40:36
 */

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        int len = nums.length, left = 0;
        PriorityQueue<int[]> queue = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                if(a[0] == b[0]) return a[1] - b[1];
                // 大到小排序
                return b[0] - a[0];
            }
        });


        while(left < k) {
            queue.add(new int[]{nums[left], left++});
        }

        list.add(queue.peek()[0]);
        for(int i = left; i < len; i++){
            queue.add(new int[]{nums[i], i});
            // 最大的下标
            int idx = queue.peek()[1];
            int dis = i - idx;
            while (dis >= k) {
                queue.poll();
                dis = i - queue.peek()[1];;
            }
            list.add(queue.peek()[0]);
        }


        // 转移到 ans 数组中
        int[] ans = new int[list.size()];
        int index = 0;
        for(Integer val : list) {
            ans[index++] = val;
        }
        return ans;
    }
}