class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int prev = 0;
        for(int i=0;i<s.length();i++){
            int x = s[i] - '0';
            ans+= min(abs(x-prev),abs(10-abs(x-prev)));
            prev = x;
        }
        return ans;
    }
};