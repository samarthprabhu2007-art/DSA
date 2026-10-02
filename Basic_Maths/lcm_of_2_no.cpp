class Solution {
public:
    int gcd(int n1,int n2){
        if(n1==0) return n2;
        return gcd(n2%n1,n1);
    }
    int LCM(int n1,int n2) {
        return (n1*n2)/gcd(n1,n2);
    }
};