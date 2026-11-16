class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int need = target - curr;
            if(mp.count(need)==1) return {i,mp[need]};
            // inserting to the map
            mp[curr] = i;
        }
        return {};
    }
};