class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int x = 0;
        int y = prices[n-1];
        for(int i = n -2;i>=0;i--){
            int p = max(x,y-prices[i]);
            int q = max(x+prices[i],y);
            x=p;
            y=q;
        }
        return x;
    }
};