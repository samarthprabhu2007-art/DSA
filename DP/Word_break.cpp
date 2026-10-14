class Solution {
public:
    bool call(int i,int l,unordered_set<string>& st,string& s,int n,vector<int>& dp){
        //breaking at idx i, i+1, i + 2  so on uptil i+l
        if(i == n) return false;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i;j<min(n,i+l+1);j++){
            temp.push_back(s[j]);
            if(st.count(temp) == 1){
                if(j == n-1 || call(j+1,l,st,s,n,dp) == true) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int i = 0;
        unordered_set<string> st;
        int l = 0;
         int n = s.length();
        vector<int> dp(n,-1);
        for(auto x:wordDict){
            st.insert(x);
            l = max(l,(int)x.length());
        }
        return call(i,l,st,s,n,dp);
    }
};