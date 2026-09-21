// https://codeforces.com/contest/2266/problem/A#

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int  n;
        cin>>n;
        int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<n-min(a,min(b,c))<<endl;
    }
    return 0;
}