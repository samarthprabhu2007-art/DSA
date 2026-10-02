class Solution {
public:
    bool isPerfect(int n) {
        int x  = sqrt(n);
        int s = 0;
        for(int i=1;i<=x;i++){
            if(n%i == 0){
                int p = i;
                int q = n/i;
                s+=p;
                if(p!=q) s+=q;
            }
        }
        return s == 2*n;
    }
};