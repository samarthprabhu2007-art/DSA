class Solution{
    public:
        int knapsack01(vector<int>& wt, vector<int>& val, int n, int w) {
            vector<int> dp(w+1,0);
            for(int i=0;i<n;i++){
                for(int j = w;j>=0;j--){
                    int x = wt[i] + j;
                    if(x<=w){
                        dp[x]=max(dp[x],dp[j]+val[i]);
                    }
                }
            }
            return dp[w];
        }
};