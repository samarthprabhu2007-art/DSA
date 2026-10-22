class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j  =0;
        int m = text1.size();
        int n = text2.size();
        vector<int> dp(n+1,0);
        for(int i=m-1;i>=0;i--){
            int prev= 0;
            for(int j=n-1;j>=0;j--){
                int x = dp[j];
                if(text1[i] == text2[j]) dp[j] = 1+prev;
                else dp[j] = max(dp[j+1],dp[j]);
                prev = x;
            }
        }
        return dp[0];
    }
};

