class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans= 0;
        for(int i = 1, k=-1; n; n>>=1, i=i*2+1){
            if(n == 1) ans = i + k*ans;
            else if(n & 1) {
                ans += i*k;
                k=-k;
            }
        }
        return ans;
    }
};