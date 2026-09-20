class Solution {
public:
    int frogJump(vector<int>& h, int k) {
        int n=h.size();
        if(n==1) return 0;
        if(n==2) return abs(h[1]-h[0]);
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        dp[1]=abs(h[1]-h[0]);
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=max(0,i-k);j--){
                dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
            }
        }
        return dp[n-1];
    }
};
