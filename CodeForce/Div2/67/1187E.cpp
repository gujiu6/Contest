#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


array<int, MAXX> h;
array<int, MAXX << 1> nxt, to, sz;
array<ll, MAXX> dp;
int cnt, n;
void build() {
    cnt = 1;
    fill(dp.begin(), dp.begin() + n + 1, 0);
    fill(h.begin(), h.begin() + n + 1, 0);
}

void addEdge(int u, int v) {
    nxt[cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt++;
}

void dfs(int u, int f) {
    deque<array<int, 3>> q;
    q.push_back({u, f, 0});
    while(!q.empty()) {
        auto [u, f, st] = q.back(); q.pop_back();
        if(st == 0) {
            q.push_back({u, f, 1});
            for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
                v = to[ei];
                if(v == f) continue;
                q.push_back({v, u});
            }
        }
        else {
            sz[u] = 1;
            for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
                v = to[ei];
                if(v == f) continue;
                sz[u] += sz[v];
            }
            dp[1] += sz[u];
        }
    }
    // sz[u] = 1;
    // for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
    //     v = to[ei];
    //     if(v == f) continue;
    //     dfs(v, u);
    //     sz[u] += sz[v];
    // }
    // dp[1] += sz[u];
}

inline void solve() {
    cin >> n;
    build();
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    auto dfs = [&](int u, int f)->void {
        // if(u != 1) {
        //     dp[u] = dp[f] - sz[u] + (n - sz[u]);
        // }
        // for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
        //     v = to[ei];
        //     if(v == f) continue;
        //     dfs(dfs, v, u);
        // }
        deque<pii> q;
        q.push_back({u, f});
        while(!q.empty()) {
            auto [u, f] = q.back();q.pop_back();
            if(u != 1) {
                dp[u] = dp[f] - sz[u] + (n - sz[u]);
            }
            for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
                v = to[ei];
                if(v == f) continue;
                q.push_back({v, u});
            }
        }
    };
    dfs(1, 0);
    ll ans = -INF;
    rep(i, 1, n) {
        ans = max(ans, dp[i]);
        // dbg(i)dbg(dp[i])
    }
    cout << ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    //cin>>t;
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