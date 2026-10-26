class Solution {
public:
    int minDistance(string s1, string s2) {
        int i = 0;
        int j = 0;
        int m = s1.length();
        int n = s2.length();
        vector<int> dp(n+1,0);
        for(int j=0;j<=n;j++) dp[j] = n-j;
        for(int i=m-1;i>=0;i--){
            int prev = m-i-1;
            dp[n] = m-i;
            for(int j=n-1;j>=0;j--){
                int x = dp[j];
                if(s1[i] == s2[j]) dp[j] = prev;
                else{
                    dp[j] = 1+min(dp[j],min(dp[j+1],prev));
                }
                prev = x;
            }
        }
        return dp[0];
    }
};