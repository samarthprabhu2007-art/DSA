class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        vector<int> dp(n,0);
        int prev;
        for(int i=n-2;i>=0;i--){
            prev = 0;
            for(int j=i+1;j<n;j++){
                int x = dp[j];
                if(s[i] == s[j]) dp[j] = prev;
                else dp[j] = min(1+dp[j-1],1+dp[j]);
                prev = x;
            }
        }
        return dp[n-1];
    }
};