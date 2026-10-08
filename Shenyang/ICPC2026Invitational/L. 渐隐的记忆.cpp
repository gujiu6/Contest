#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
void solve(){
    int n,m;cin>>n>>m;
    vector<string> a(m+1);
    rrp(i,1,m)cin>>a[i];
    vector<vector<int>> cnt(26,vector<int>(n+1));
    rrp(i,1,m){
        rrp(j,0,n-1){
            cnt[a[i][j]-'a'][j]++;
        }
    }
    rrp(i,0,n-1){
        rrp(j,0,25){
            if(cnt[j][i]>m/2){
                cout<<(char)(j+'a');
                break;
            }
        }
    }
        cout<<'\n';

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)solve();
}