#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll

void solve(){
    ll n;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
        if(s1>=a[i]) s1++;
        else s1--;
    }
    for(int i=n-1;i>=0;i--){
        if(s2>=a[i]) s2++;
        else s2--;
    }
    cout<<s1<<" "<<s2<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();;
}