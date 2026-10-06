class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int x = 0;
        int y = prices[n-1];
        for(int i=n-2;i>=0;i--){
            int p  = max(x,-fee-prices[i]+y);
            int q  = max(y,prices[i]+x);
            x = p;
            y = q;
        }
        return x;
    }
};