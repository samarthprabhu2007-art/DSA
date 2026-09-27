class Solution {
public:
    int mod = INT_MAX;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount+1,0);
        //here since repetitio allowed left to right
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(dp[j]!=0){
                    long long x = (long long)j + coins[i];
                    if(x<=amount) {
                        dp[x]+=dp[j];
                        dp[x]%=mod;
                    }
                }
            }
        }
        return dp[amount];
    }
};