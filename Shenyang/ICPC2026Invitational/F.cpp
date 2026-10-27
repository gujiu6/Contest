#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
void solve(){
    int n;cin>>n;
    if(n==1){cout<<0<<'\n';return;}
    else if(n==2){
        cout<<"1 0\n3 2\n";
        return;
    }
    vector<vector<int>> g(n,vector<int>(n));
    int cnt=0;
    rrp(i,0,n*n-1){
        if(i<n){
            g[0][i]=i;
        }else if(i<2*n-1) g[i-n+1][n-1]=i;
        else{
            g[cnt/(n-1)+1][cnt%(n-1)]=n*n-1-i+2*n-1;
            cnt++;
        }
    }
    swap(g[0][0],g[0][n-1]);
    rrp(i,0,n-1){
        rrp(j,0,n-1){
            cout<<g[i][j]<<' ';
        }
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
}