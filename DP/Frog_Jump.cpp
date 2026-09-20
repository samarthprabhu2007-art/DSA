class Solution {
  public:
    int minCost(vector<int>& h) {
        if(h.size()==1) return 0;
        if(h.size()==2) return abs(h[1]-h[0]);
        int prev=0;
        int curr=abs(h[1]-h[0]);
        for(int i=2;i<h.size();i++){
            int x=prev;
            prev=curr;
            curr=min(curr+abs(h[i]-h[i-1]),x+abs(h[i]-h[i-2]));
        }
        return curr;
    }
};