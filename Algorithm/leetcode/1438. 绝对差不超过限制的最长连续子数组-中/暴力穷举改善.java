class Solution {
    int[] memo;
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        memo = new int[n];
        for (int i = 0; i < n; i++)
           memo[i] = n + 1;
        int max = 1;       
        //子数组的长度
        for (int i = 2; i <= nums.length; i++) {
            for (int j = 0; i + j - 1 < nums.length; j++) {
                //nums[j...i+j-1]是目前的子数组
                if (i < max) continue;
                //memo是记录不符合要求数组的起始位置（起：数组下标，子数组长度：memo[i]值
                if (memo[j] <= i)
                    continue;
                int temp = maxSub(nums, j, i, limit);
                max = max > temp ? max : temp;
            }
        }
        return max;
    }
    private int maxSub(int[] nums, int start, int length, int limit) {
        int[] temp = new int[length];
        for (int i = 0; i < length; i++) {
            temp[i] = nums[start + i];
        }
        Arrays.sort(temp);
        if (temp[length - 1] - temp[0] <= limit) {
            //System.out.println(start);
            return length;
        }
        else {
            memo[start] = length;
            return 1;
        }
    }
}