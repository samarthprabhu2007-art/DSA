class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> st;
            st.insert(0);
            int s = 0;
            for(int j=i;j<nums.size();j++){
                s+=nums[j];
                int x = (2*nums[j])%k;
                if(x<0) x = k+x;
                st.insert(x);
                int y = s%k;
                if(y<0) y=k+y;
                if(st.count(y) == 1) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};