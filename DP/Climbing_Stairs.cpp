class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int prev=1;
        int curr=1;
        for(int i=2;i<=n;i++){
            int x=prev;
            prev=curr;
            curr=curr+x;
        }
        return curr;
    }
};