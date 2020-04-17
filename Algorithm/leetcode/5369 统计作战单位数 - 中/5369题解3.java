//Java O(n^2)
class Solution {
    public int numTeams(int[] rating) {
        if(rating == null || rating.length <= 2){
            return 0;
        }
        int n = rating.length;

        int[] dpLeftMin = new int[n];
        int[] dpLeftMax = new int[n];

        int[] dpRightMax = new int[n];
        int[] dpRightMin = new int[n];
        
        for(int i=1;i<n-1;i++){
            for(int j=i-1;j>=0;j--) {
                if (rating[j] < rating[i]) {
                    dpLeftMin[i] ++;
                }
                if(rating[j] > rating[i]){
                    dpLeftMax[i] ++;
                }
            }

            for(int j=i+1;j<n;j++) {
                if (rating[i] > rating[j]) {
                    dpRightMin[i] ++;
                }
                if(rating[i] < rating[j]){
                    dpRightMax[i] ++;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            ans += dpLeftMax[i] * dpRightMin[i];
            ans += dpLeftMin[i] * dpRightMax[i];
        }
        return ans;
    }
}

作者：doctording-4
链接：https://leetcode-cn.com/problems/count-number-of-teams/solution/5369-tong-ji-zuo-zhan-dan-wei-shu-javaon2-by-docto/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。