class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> temp;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==0) continue;
            for(int j=0;j<digits.size();j++){
                if(j==i) continue;
                for(int k=0;k<digits.size();k++){
                    if(k==j || k==i) continue;
                    if(digits[k]%2 != 0) continue;
                    int x=digits[i];
                    x*=10;
                    x+=digits[j];
                    x*=10;
                    x+=digits[k];
                    temp.insert(x);
                }
            }
        }
        return temp.size();
    }
};