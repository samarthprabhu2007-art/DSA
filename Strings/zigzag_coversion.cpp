class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        //vector<string> temp(n);
        vector<string> temp;
        for(int i=0;i<n;i++){
            string x;
            temp.push_back(x);
        }
        int len = s.length();
        int i = 0;
        int idx = 0;  // vectors string ka index
        bool going_down = true;
        while(i<len){
            temp[idx].push_back(s[i]);
            i++;
            if(going_down == true){
                idx++;
                if(idx == n){
                    idx = n-2;
                    if(idx!=0) going_down = false;
                }
            }
            else{
                idx--;
                if(idx == 0){
                    going_down=true;
                }
            }
        }
        string ans;
        for(int i=0;i<n;i++) ans+=temp[i];
        return ans;
    }
};