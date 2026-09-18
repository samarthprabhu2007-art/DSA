class Solution {
public:
    int mod = (int)pow(10,9) + 7;
    long long call(int n){
        if(n==1) return 2;
        if(n==0) return 1;
        if(n%2==0){
            long long x = call(n/2)%mod;
            return (x*x)%mod;
        }
        else{
            long long x = call(n/2)%mod;
            return (x*x*2)%mod;
        }
    }
    int monkeyMove(int n) {
        // if u observe in all cases no matter what
        // monkey intersect, except if all move clockwise, 
        //or all move anticlockwise
        // total possible outcome is 2 power n ,
        // each monkey has two choice
        //hecne 2 cases where all move clock wise +
        // or anticlock wise

        long long x= call(n);
        if(x-2<0){
            x+=mod;
            x-=2;
            return x;
        }
        return x-2;
        //Imp edge case 
    }
};