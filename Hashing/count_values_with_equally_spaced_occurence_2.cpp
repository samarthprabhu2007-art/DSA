class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(mp[i->first].size() >= 3){
                int x=mp[i->first][1]-mp[i->first][0];
                bool is =true;
                for(int j=2;j<mp[i->first].size();j++){
                    if(mp[i->first][j]-mp[i->first][j-1] != x) {
                        is=false;
                        break;
                    }
                }
                if(is) ans++;
            }
        }
        return ans;
    }
};