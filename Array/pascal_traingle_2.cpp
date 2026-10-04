class Solution {
public:
    vector<int> getRow(int r) {
        long long x = 1;
        r++;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=r-1;i++){
            x = x*(r-i)/(i);
            ans.push_back(x);
        }
        return ans;
    }
};