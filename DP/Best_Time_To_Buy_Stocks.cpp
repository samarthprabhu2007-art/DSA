class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0];
        int x=0;
        for(int i=1;i<prices.size();i++){
            x=max(x,prices[i]-mi);
            mi=min(mi,prices[i]);
        }
        return x;
    }
};