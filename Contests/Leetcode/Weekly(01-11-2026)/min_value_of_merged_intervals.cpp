class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=1;i<nums.size();i+=2){
            string x = to_string(nums[i-1]);
            x+=to_string(nums[i]);
            int y = stoi(x);
            ans = min(ans,y);
        }
        return ans;
    }
};.