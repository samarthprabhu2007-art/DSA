class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int cnt = 0;
        bool curr = false;
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (2,-1)));
        // dp[n-1][false][0] = 0;
        // dp[n-1][false][1] = 0;
        // dp[n-1][true][0] = prices[n-1];
        // dp[n-1][true][1] = prices[n-1];
        int p = 0;
        int q = 0;
        int r = prices[n-1];
        int s = prices[n-1];
        for(int i = n-2; i>=0 ; i--){
            // dp[i][false][0] = max(dp[i+1][false][0],-prices[i]+dp[i+1][true][0]);
            // dp[i][false][1] = max(dp[i+1][false][1],-prices[i]+dp[i+1][true][1]);
            // dp[i][true][0] = max(dp[i+1][true][0],prices[i]+dp[i+1][false][1]);
            // dp[i][true][1] = max(dp[i+1][true][1],prices[i]);
            int a = max(p,-prices[i]+r);
            int b = max(q,-prices[i]+s);
            int c = max(r,prices[i]+q);
            int d = max(s,prices[i]);
            p=a,q=b,r=c,s=d;
        }
        return p;
    }
};