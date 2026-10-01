class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=1;
        int x = nums[0];
        int f  = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == x) continue;
            else{
                x=nums[i];
                swap(nums[i],nums[idx]);
                idx++;
                f++;
            }
        }
        return f;
    }
};