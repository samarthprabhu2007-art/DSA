class Solution{
	public:
    int mod = (int)pow(10,9) + 7;
	int perfectSum(vector<int>&arr, int k){
        int n = arr.size();
        vector<long> dp(k+1,0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j = k;j>=0;j--){
                int x = j + arr[i];
                if(x<=k) {
                    dp[x]+=dp[j];
                    dp[x]%=mod;
                }
            }
        }
        return dp[k];
	}
};