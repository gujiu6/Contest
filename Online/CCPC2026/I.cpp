#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
#define pii array<int,2>
int binpow(int a,int b,int p){
    if(b==0)return 0;
    int r=binpow(a, b>>1, p);
    if(b%2)return a*r%p*r%p;
    else return r*r%p;
}
void solve(){
    int n;cin>>n;
    if(n%2){
        cout<<-1<<'\n';
        return;
    }else{
        cout<<n/2<<' '<<1<<' '<<-1<<'\n';
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
}