class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for(auto x:nums) s+=x;
        int r = 2*s + 1;
        if(target +s < 0  || target+s >= r) return 0;
        vector<int> dp(r,0);
        dp[s] = 1;
        for(int i = 0;i<n;i++){
            vector<int> temp(2*s+1,0);
            for(int j=0;j<r;j++){
                int r = j+nums[i];
                int l = j-nums[i];
                if(r<=2*s && r>=0) temp[j] = dp[r];
                if(l<=2*s && l>=0) temp[j] += dp[l];
            }
            dp=temp;
        }
        return dp[target+s];
    }
};