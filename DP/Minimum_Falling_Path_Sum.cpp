class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,0);
        for(int i=0;i<matrix.size();i++){
            dp[i]=matrix[0][i];
        }
        vector<int> temp(n,0);
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int a=INT_MAX;
                int b=INT_MAX;
                int c=INT_MAX;
                if(j-1>=0) a=dp[j-1];
                if(j+1<n) c=dp[j+1];
                b=dp[j];
                int y=min(a,min(b,c));
                temp[j]=matrix[i][j]+y;
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<dp.size();i++) ans=min(ans,dp[i]);
        return ans;
    }
};