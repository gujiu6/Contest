#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
#define pii array<int,2>
const int MO=998244353, INF = 1e18;
int binpow(int a,int b,int p=MO){
    if(b==0)return 1;
    int r=binpow(a, b>>1, p);
    if(b%2)return a*r%p*r%p;
    else return r*r%p;
}
int inv(int x){return binpow(x, MO-2);}
void solve(){
    int n,m,t;cin>>n>>m>>t;
    string s;cin>>s;
    vector<vector<pii>> g(n+1), rg(n + 1);
    vector<int> indeg(n + 1);
    s=' '+s;
    rrp(i,1,m){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        rg[v].push_back({u, w});
        indeg[u]++;
    }   
    vector<int> dis(n + 1, INF), cnt(n + 1), c(n + 1);
    queue<pii> q;
    q.push({0, t});
    dis[t] = 0;
    while(!q.empty()) {
        auto [d, u] = q.front();q.pop();
        for(const auto &[v, w] : rg[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    queue<int> qq;
    c[t] = 1;
    qq.push(t);
    auto deg = indeg;
    while(!qq.empty()) {
        auto u = qq.front(); qq.pop();
        for(const auto &[v, w] : rg[u]) {
            cnt[v]++;
            if(--indeg[v] == 0) {
                qq.push(v);
            }
            if(w + dis[u] == dis[v]) {
                c[v] = (c[v] + c[u]) % MO;
            }
        }
    }
    qq.push(t);
    vector<int> dp(n + 1, 0);
    while(!qq.empty()) {
        auto u = qq.front(); qq.pop();
        for(const auto &[v, w] : rg[u]) {
            if(--deg[v] == 0) {
                qq.push(v);
            }
            if(s[v] == '1') {
                if(dis[u] + w != dis[v]) continue;
                dp[v] = (dp[v] + (dp[u] + w) % MO * c[u] % MO * inv(c[v]) % MO) % MO;
            }
            else {
                dp[v] = (dp[v] + (dp[u] + w) % MO * inv(cnt[v]) % MO) % MO;
            }
            
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
}