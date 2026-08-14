#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
#define int long long
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define dbg(x) cout<<#x<<"="<<x<<endl;
using i64 = long long;
using i128 = __int128_t;
using ld = long double;
using ui64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<DEdge> edge(n);
    rep(i, 1, n - 1) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    vector<i64> dp(n + 1, INF);
    vector<vector<WEdge>> g(n + 1);
    auto dfs = [&](auto &&self, int u, int f)->void {
        dp[u] = a[u];
        for(const auto &e : g[u]) {
            if(e.v == f) continue;
            self(self, e.v, u);
            dp[u] = min(dp[u], dp[e.v] + e.w);
        }
    };
    auto dfs1 = [&](auto &&self, int u, int f, int w)->void {
        if(u != 1) {
            dp[u] = min(dp[u], dp[f] + w);
        }
        for(const auto &e : g[u]) {
            if(e.v == f) continue;
            self(self, e.v, u, e.w);
        }
    };
    rep(i, 1, m) {
        int op; cin >> op;
        if(op == 1) {
            int id, x; cin >> id >> x;
            a[id] = x;
        }
        else if(op == 2) {
            int id, w; cin >> id >> w;
            edge[id].w = w;
        }
        else {
            g.assign(n + 1, vector<WEdge>());
            for(const auto &[u, v, w] : edge) {
                g[u].push_back({v, w});
                g[v].push_back({u, w});
            }
            dp.assign(n + 1, INF);
            dfs(dfs, 1, 0);
            dfs1(dfs1, 1, 0, 0);
            int ans = 0;
            for(int i = 1; i <= n; i++) ans ^= dp[i];
            cout << ans << endl;
        }
    }
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
    
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