class Solution {
public:
    static bool comp(int& x,int& y){
        if(abs(x) > abs(y)) return true;
        return false;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        long long ans = 0;
        int n = nums.size();
        int x;
        x=n/2;
        if(n%2 == 0) x = n/2-1;
        for(int i=0;i<n;i++){
            if(i <= x){
                ans+=nums[i]*nums[i];
            }
            else{
                ans-=nums[i]*nums[i];
            }
        }
        return ans;
    }
};