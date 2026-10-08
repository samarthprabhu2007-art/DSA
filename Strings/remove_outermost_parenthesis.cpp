class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(st.size()==1){
                    s[i]=32;
                    s[st.top()]=32;
                }
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==32) continue;
            ans+=s[i];
        }
        return ans;
    }
};