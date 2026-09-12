class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto i=mp.begin();i!=mp.end();i++){
            int x=i->first;
            int y=i->second;
            if(y==3){
                int f=-1;
                int s=-1;
                int l=-1;
                for(int j=0;j<nums.size();j++){
                    if(nums[j]==x){
                        if(f==-1) f=j;
                        else if(s==-1) s=j;
                        else l=j;
                    }
                }
                if(s-f == l-s) ans++;
            }
        }
        return ans;
    }
};