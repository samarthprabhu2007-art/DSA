class Solution {
public:
    int numDistinct(string s, string t) {
        int i=0;
        int j=0;
        int m = s.length();
        int n = t.length();
        vector<long> dp(n+1,0);
        dp[n] = 1;
        int prev; 
        for(int i=m-1;i>=0;i--){
            prev = 1;
            for(int j=n-1;j>=0;j--){
                int x = dp[j];
                if(s[i] == t[j]) {
                    dp[j]+=prev;
                    if(dp[j] > INT_MAX) dp[j] = 0;
                }
                prev = x;
            }
        }
        return dp[0];
    }
};