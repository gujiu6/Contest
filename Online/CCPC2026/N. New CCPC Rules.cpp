#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int tim=0;
    int a=0,b=0;
    int f=0;
    for(auto c:s){
        if(!f and isdigit(c)){
            a*=10;
            a+=c-'0';
        }else if(c==':'){
            f=1;
        }else{
            b*=10;
            b+=c-'0';
        }
    }
    if(m>=50 or m>=n*0.2 or a*60+b>=240){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}