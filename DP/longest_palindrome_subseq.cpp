class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n  = s.length();
        vector<int> dp(n,0);
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            int prev = dp[i];
            dp[i] = 1;
            for(int j=i+1;j<n;j++){
                int x = dp[j];
                if(s[i] == s[j]) dp[j]=2+prev;
                else{
                    dp[j] = max(dp[j],dp[j-1]);
                }
                prev= x;
            }
        }
        return dp[n-1];
    }
};