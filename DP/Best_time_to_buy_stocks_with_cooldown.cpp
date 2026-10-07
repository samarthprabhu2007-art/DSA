class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int x = n-1;
        int sec_true = prices[x];
        int sec_false = 0;
        x--;
        if(n == 1) return 0;
        int first_true = max(sec_true,prices[x]);
        int first_false = max(sec_false,-prices[x]+sec_true);
        for(int j = n-3;j>=0;j--){
            int curr_true = max(first_true,prices[j]+sec_false);
            int curr_false = max(first_false,-prices[j]+first_true);
            sec_true = first_true;
            sec_false = first_false;
            first_true = curr_true;
            first_false = curr_false;
        }
        return first_false;
    }
};