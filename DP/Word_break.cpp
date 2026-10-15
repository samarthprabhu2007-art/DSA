class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i = 0;
        unordered_set<string> st;
        int l = 0;
        int n = s.length();
        vector<bool> dp(n,false);
        for(auto x:wordDict){
            st.insert(x);
            l = max(l,(int)x.length());
        }
        string temp;
        for(int i = 0;i<l;i++){
            temp.push_back(s[i]);
            if(st.count(temp) == 1) dp[i] = true;
        }
        for(int i=1;i<n;i++){
            if(dp[i-1] == false) continue;
            string temp2;
            for(int j=i;j<min(i+l,n);j++){
                temp2.push_back(s[j]);
                if(st.count(temp2) == 1) dp[j] = true; 
            }
        }
        return dp[n-1];
    }
};