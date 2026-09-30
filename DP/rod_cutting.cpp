class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
        // tab;
        vector<int> dp(n+1,-1);
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                int len = j-i;
                if(j+1 >= n) dp[i]=max(dp[i],price[len]);
                else dp[i]=max(dp[i],dp[j+1]+price[len]);
            }
        }
        return dp[0];
    }
};
