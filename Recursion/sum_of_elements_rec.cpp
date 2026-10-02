class Solution{	
	public:
        int sum(int i,vector<int>& nums,int n){
            if(i==n) return 0;
            return nums[i] + sum(i+1,nums,n);
        }
		int arraySum(vector<int>& nums){
            int n = nums.size();
			return sum(0,nums,n);
		}
};