class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        if(g[0][0] == 1 || g[m-1][n-1] == 1) return 0;
        vector<long long> dp(m,0);
        dp[m-1]=1;
        for(int i = m-2;i>=0;i--){
            if(g[i][n-1]==1) dp[i]=0;
            else dp[i]=dp[i+1];
        }
        for(int j=n-2;j>=0;j--){
            for(int i = m-1;i>=0;i--){
                if(i==m-1){
                    if(g[i][j]==1) dp[i]=0;
                    continue;
                }
                if(g[i][j]==1) dp[i]=0;
                else dp[i]+=dp[i+1];
            }
        }
        return dp[0];
    }
};