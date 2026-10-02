class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        int freq=0;
        for(auto x:mp){
            freq=max(freq,x.second);
        }
        int sec_freq = -1 ;
        for(auto x:mp){
            if(x.second == freq) continue;
            sec_freq = max(sec_freq,x.second);
        }
        if(sec_freq == -1) return -1;
        int ans = INT_MAX;
        for(auto x:mp){
            if(x.second == sec_freq) ans=min(ans,x.first);
        }
        return ans;
    }
};