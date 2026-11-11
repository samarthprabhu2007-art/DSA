class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans;
        //only cost1 and cost2
        long long a;
        a=(long long)cost1*need1+(long long)cost2*need2;
        //only costboth
        long long b;
        b=(long long)costBoth*max(need1,need2);
        //costboth till(min of cost 1 and cost 2)
        long long c;
        int x=cost2;
        if(max(need1,need2)==need1) x=cost1;
        c=(long long)costBoth*min(need1,need2)+(long long)(max(need1,need2)-min(need1,need2))*x;
        ans=min(a,min(b,c));
        return ans;
    }
};