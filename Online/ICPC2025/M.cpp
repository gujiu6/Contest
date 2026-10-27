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
using i128 = __int128;
using ld = long double;
using u64 = unsigned long long;
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




//1.倍增LCA
class LCA {
public:
    int n, lg2, tim = 0;
    vector<int> dep, in, out, sz;
    vector<vector<int>> stjump;
    vector<i64> dis;
    LCA(const vector<vector<WEdge>>& g, int root = 1)
    : n(g.size() - 1), lg2(bit_width((unsigned)max(1LL, n))), dep(n + 1), in(n + 1), out(n + 1), dis(n + 1), sz(n + 1), stjump(lg2, vector<int>(n + 1)) {
        auto dfs = [&](auto &&self, int u, int f)->void {
            in[u] = ++tim;
            dep[u] = dep[f] + 1;
            stjump[0][u] = f;
            sz[u] = 1;
            for(int p = 1; p < lg2; p++) {
                stjump[p][u] = stjump[p - 1][stjump[p - 1][u]];
            }
            for(const auto &e : g[u]) {
                if(e.v == f) continue;
                dis[e.v] = dis[u] + e.w;
                self(self, e.v, u);
                sz[u] += sz[e.v];
            }
            out[u] = tim;
        };
        if(n) dfs(dfs, root, root);
    }
    //u是否为v的祖先
    bool ancestor(int u, int v) const {
        return in[u] <= in[v] && out[v] <= out[u];
    }
    //u向上跳k层
    int jump(int u, int k) const {
        if(k >= dep[u]) return -1;
        for(int p = 0; k; p++, k >>= 1) {
            if(k & 1) {
                u = stjump[p][u];
            }
        }
        return u;
    }
    //lca
    int lca(int u, int v) const {
        if(ancestor(u, v)) return u;
        if(ancestor(v, u)) return v;
        for(int p = lg2 - 1; p >= 0; p--) {
            if(!ancestor(stjump[p][u], v)) {
                u = stjump[p][u];
            }
        }
        return stjump[0][u];
    }
    //u到v的距离(边数)
    int dist(int u, int v) const {
        int f = lca(u, v);
        return dep[u] + dep[v] - 2 * dep[f];
    }
    //u到v的边权和(边数)
    i64 distW(int u, int v) const {
        int f = lca(u, v);
        return dis[u] + dis[v] - 2 * dis[f];
    }
    // 路径u->v上的第k(0-base)个节点
    int pathKth(int u, int v, int k) const {
        int p = lca(u, v);
        int a = dep[u] - dep[p];
        int b = dep[v] - dep[p];
        if(k < 0 || k > a + b) return -1;
        if(k <= a) return jump(u, k);
        return jump(v, a + b - k);
    }
};

inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<WEdge>> g(n + 1);
    vector<vector<int>> nxt(n + 1);
    rep(i, 1, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }
    LCA lca(g);
    vector<int> dp(n + 1);
    int ans = 0;
    for(int u = 1; u <= n; u++) {
        dp[u] = lca.distW(u, 1), ans += dp[u];
    }
    cout << ans << endl;
    
    for(int k = 1; k <= n; k++) {
        vector<int> val(n + 1, INF);
        for(int x = 1; x <= n; x++) {
            for(const auto &y : nxt[x]) {
                val[x] = min(val[x], dp[y]);
            }
        }
        vector<int> dis = val;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for(int u = 1; u <= n; u++) {
            if(dis[u] < INF) {
                q.push({dis[u], u});
            }
        }
        while(!q.empty()) {
            auto [d, u] = q.top(); q.pop();
            if(d != dis[u]) continue;
            for(const auto &[v, w] : g[u]) {
                if(dis[v] > d + w) {
                    dis[v] = d + w;
                    q.push({dis[v], v});
                }
            }
        }
        vector<int> ndp(n + 1);
        ans = 0;
        for(int u = 1; u <= n; u++) {
            ndp[u] = min(dp[u], dis[u]);
            ans += ndp[u];
        }
        cout << ans << endl;
        dp = move(ndp);
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