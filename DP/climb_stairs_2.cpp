class Solution {
public:
    int call(int i,int n,vector<int>& costs,vector<int>& dp){
        if(i == n) return 0;
        if(dp[i+1]!=-1) return dp[i+1];
        int ans = INT_MAX;
        if(i+1 <= n) ans = min(ans,call(i+1,n,costs,dp) + 1 + costs[i+1-1]);
        if(i+2 <= n) ans = min(ans,call(i+2,n,costs,dp) + 4 + costs[i+2-1]);
        if(i+3 <= n) ans = min(ans,call(i+3,n,costs,dp) + 9 + costs[i+3-1]);
        return dp[i+1] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return call(0,n,costs,dp);
    }
};