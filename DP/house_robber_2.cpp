class Solution {
public:
    int call(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = 0;
        int not_take = 0;
        take = nums[i]+call(i+2,n,nums,dp);
        not_take = call(i+1,n,nums,dp);
        return dp[i] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        return max(call(0,n-2,nums,dp),call(1,n-1,nums,dp2));
    }
};