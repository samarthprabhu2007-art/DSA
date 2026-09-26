class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s =0;
        long long x =0;
        for(int i=0;i<source.size();i++){
            s+=source[i];
            x+=target[i];
        }
        return s==x;
    }
};