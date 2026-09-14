class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool delete_used = false;
        int ans=0;
        int pre =-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans=max(ans,i-pre);
            }
            else{
                if(delete_used == false){
                    delete_used=true;
                    ans=max(ans,i-pre);
                    continue;
                }
                while(delete_used == true){
                    pre++;
                    if(nums[pre]==0) delete_used=false;
                }
                delete_used=true;
                ans=max(ans,i-pre);
            }
        }
        return ans-1;
    }
};