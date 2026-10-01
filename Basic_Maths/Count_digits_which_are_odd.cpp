class Solution {
public:
    int countOddDigit(int n) {
        int cnt = 0;
        while(n!=0){
            int x = n%10;
            n/=10;
            if(x%2==1) cnt++;
        }
        return cnt;
    }
};