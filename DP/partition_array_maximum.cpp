class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int i = 0;
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m = -1;
            for(int j=i;j<min(n,i+k);j++){
                m = max(m,arr[j]);
                dp[i] = max(dp[i],m*(j-i+1)+dp[j+1]);
            }
        }
        return dp[0];
    }
};