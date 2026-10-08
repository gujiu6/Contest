#include <bits/stdc++.h>
#include <locale>
//#include <ranges>
using namespace std;
#define int long long
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = array<int,2>;
const int INF=LLONG_MAX;
const int MOD=1e9+7;
const int MAXX=2e5+10,MAXN=5e5+10,MAXM=5e5+10,LIMIT=20;
const double eps=1e-6;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n;cin>>n;
    vector<int>t(n+1),p(n+1),ans(n+1),dir(n+1);
    vector<vector<int>>mp(n+1);
    rep(i,1,n) cin>>t[i],mp[t[i]].push_back(i);
    rep(i,1,n) cin>>p[i],p[i]*=2;
    rep(i,1,n) dir[i]=p[i]<p[t[i]];
    vector<int>cur(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    rep(i,1,n){
        int v=t[i];
        if(dir[i]!=dir[v]) cur[i]=abs(p[i]-p[v])/2;
        q.push({cur[i],i});
    }
    vector<int>vis(n+1);
    while(!q.empty()){
        auto [times,i]=q.top();q.pop();
        if(vis[i]||times!=cur[i]) continue;
        vis[i]=1;
        ans[i]=times;
        int posi=dir[i]?times+p[i]:p[i]-times;
        for(int v:mp[i]){
            if(vis[v]) continue;
            int posv=dir[v]?times+p[v]:p[v]-times;
            int x=times+abs(posv-posi);
            cur[v]=x;
            q.push({cur[v],v});
        }
    }
    rep(i,1,n) cout<<ans[i]<<" \n"[i==n];
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
    
        solve();
    
    }
    return 0;
}
// 难道我不配AC吗
//   ▄████  █    ██  ▄▄▄██▀▀▀██▓ █    ██
//  ██▒ ▀█▒ ██  ▓██▒   ▒██  ▓██▒ ██  ▓██▒
// ▒██░▄▄▄░▓██  ▒██░   ░██  ▒██▒▓██  ▒██░
// ░▓█  ██▓▓▓█  ░██░▓██▄██▓ ░██░▓▓█  ░██░
// ░▒▓███▀▒▒▒█████▓  ▓███▒  ░██░▒▒█████▓
//  ░▒   ▒ ░▒▓▒ ▒ ▒  ▒▓▒▒░  ░▓  ░▒▓▒ ▒ ▒
//   ░   ░ ░░▒░ ░ ░  ▒ ░▒░   ▒ ░░░▒░ ░ ░
//  ░   ░  ░░░ ░ ░  ░ ░ ░   ▒ ░ ░░░ ░ ░
//       ░    ░      ░   ░   ░     ░