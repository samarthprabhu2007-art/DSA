// https://codeforces.com/contest/2266/problem/C#


#include <bits/stdc++.h>
using namespace std;
int call(int i,bool o,string& s,int n,vector<vector<int>>& dp){
    if(i==n) return 0;
    int x;
    if(o==false) x=0;
    if(o==true) x=1;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans=INT_MAX;
    if(s[i]=='0'){
        if(o==false) ans =min(ans,call(i+1,o,s,n,dp));
        else if(o==true){
            ans=min(ans,1+call(i+1,o,s,n,dp));
        }
    }
    else{
        if(o==true) ans =min(ans,call(i+1,o,s,n,dp));
        else{
            ans=1+min(ans,call(i+1,false,s,n,dp));
            ans=min(ans,call(i+1,true,s,n,dp));
        }
    }
    return dp[i][x]=ans;
}
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool o = false;
        if(s[0]=='1'){
            int ans=0;
            for(int i=1;i<n;i++){
                if(s[i]=='0') ans++;
            }
            cout<<ans<<endl;
        }
        else{
            vector<vector<int>> dp(n,vector<int> (2,-1));
            int ans = call(1,o,s,n,dp);
            cout<<ans<<endl;
        }
    }
    return 0;
}
