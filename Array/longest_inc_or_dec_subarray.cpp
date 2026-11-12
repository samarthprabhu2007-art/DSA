class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int x = INT_MAX;
        int y = INT_MIN;
        int a = 0;
        int b = 0;
        int la = 0;
        int lb = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] < x){
                x = nums[i];
                la++;
                a=max(a,la);
            }
            else{
                x = nums[i];
                la = 1;
            }
            if(nums[i] > y){
                y = nums[i];
                lb++;
                b=max(b,lb);
            }
            else{
                y = nums[i];
                lb = 1;
            }
        }
        return max(a,b);
    }
};