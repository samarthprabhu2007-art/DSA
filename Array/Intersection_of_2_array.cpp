class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i =0;
        int j =0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
                int x = nums1[i];
                int a = 0;
                int b = 0;
                while(i<nums1.size() && nums1[i]==x) i++,a++;
                while(j<nums2.size() && nums2[j]==x) j++,b++;
                int z = min(a,b);
                while(z--) ans.push_back(x);
            }
        } 
        return ans;
    }
};