class Solution {
public: 
    // dp state represnts : Iam buying a stock
    int call(int i,vector<int>& prices,int n,vector<int>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        //skip
        ans=max(ans,call(i+1,prices,n,dp));
        //buy
        for(int j=i+1;j<n;j++){
            int diff = prices[j]-prices[i];
            if(diff>0) ans=max(ans,diff+call(j+1,prices,n,dp));
        }
        return dp[i] =  ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        return call(0,prices,n,dp);
    }
};