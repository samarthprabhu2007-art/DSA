class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            //always as repetion allowed
            //start from left , else from right
            for(int j=0;j<=amount;j++){
                if(dp[j]!=-1){
                    long long  x = (long long) j + coins[i];
                    if(x<=amount){
                        if(dp[x] == -1) dp[x]= dp[j]+1;
                        else dp[x]= min(dp[j] + 1,dp[x]);
                    }
                }
            }
        }
        return dp[amount];
    }
};