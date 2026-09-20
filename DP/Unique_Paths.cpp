class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m,0);
        for(int i=m-1;i>=0;i--) dp[i]=1;
        for(int j=n-2;j>=0;j--){
            for(int i=m-2;i>=0;i--){
                dp[i]+=dp[i+1];
            }
       }
       return dp[0];
    }
};