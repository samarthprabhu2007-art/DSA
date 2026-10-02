class Solution{	
public:		
    void call(int i,vector<char>& s,int n){
        if(i==n/2) return ;
        swap(s[i],s[n-i-1]);
        call(i+1,s,n);
    }
	vector<char> reverseString(vector<char>& s){
        int n = s.size();
        call(0,s,n);
        return s;
	}
};