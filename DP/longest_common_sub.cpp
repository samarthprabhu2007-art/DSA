class Solution {
public:
    int call(int i,int j,int m,int n,string& text1,string& text2,vector<vector<int>>& dp){
        if(i == m || j == n){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = max(ans,1+call(i+1,j+1,m,n,text1,text2,dp));
        }
        else{
            ans = max(ans,call(i+1,j,m,n,text1,text2,dp));
            ans = max(ans,call(i,j+1,m,n,text1,text2,dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j  =0;
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return call(i,j,m,n,text1,text2,dp);
    }
};