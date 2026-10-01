class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open.push(s[i]);
            else if(s[i]=='[') open.push(s[i]);
            else if(s[i]=='{') open.push(s[i]);
            else if(s[i]==')'){
                if(open.size()==0) return false;
                if(open.top()!='(') return false;
                open.pop();
            }
            else if(s[i]==']'){
                if(open.size()==0) return false;
                if(open.top()!='[') return false;
                open.pop();
            }
            else{
                if(open.size()==0) return false;
                if(open.top()!='{') return false;
                open.pop();
            }
        }
        return open.size()==0;
    }
};