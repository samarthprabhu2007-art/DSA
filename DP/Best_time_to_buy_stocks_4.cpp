class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(k+1,vector<int> (2));
        vector<vector<int>> temp(k+1,vector<int> (2));
        for(int i = k;i>=0;i--){
            dp[i][false] = 0;
            dp[i][true] = prices[n-1];
        }
        temp = dp;
        for(int i = n-2;i>=0;i--){
            for(int j = k; j>=2; j--){
                temp[j][false] = max(temp[j][false],temp[j][true]-prices[i]);
                temp[j][true] = max(temp[j][true],prices[i]+temp[j-1][false]);
            }
            int j = 1;
            temp[j][false] = max(temp[j][false],temp[j][true]-prices[i]);
            temp[j][true] = max(temp[j][true],prices[i]);
            dp = temp;
        }
        return dp[k][false];
    }
};