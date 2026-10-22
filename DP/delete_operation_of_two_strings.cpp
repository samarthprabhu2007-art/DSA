class Solution {
public:
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(n+1,-1);
        for(int j=0;j<=n;j++) dp[j] = n-j;
        int prev = 0;
        for(int i=m-1;i>=0;i--){
            prev = dp[n];
            dp[n] = m-i;
            for(int j=n-1;j>=0;j--){
                int x = dp[j];
                if(word1[i] == word2[j]) dp[j] = prev;
                else dp[j] = 1+min(dp[j],dp[j+1]);
                prev= x;
            }
        }
        return dp[0];
    }
};