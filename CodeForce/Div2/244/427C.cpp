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



pair<int, vector<int>> TarjanSCC(const vector<vector<Edge>>& g) {
    int n = g.size() - 1;
    int tim = 0, cc = 0;//时间戳,SCC编号
    vector<int> dfn(n + 1), st;
    vector<int> low(n + 1);//从u出发,能够回到的最小dfn编号
    vector<int> bel(n + 1, -1);//答案数组
    vector<bool> on(n + 1);//当前节点是否还在 Tarjan 栈里面
    auto dfs = [&](auto &&self, int u)->void {
        dfn[u] = low[u] = ++tim;
        st.push_back(u);
        on[u] = true;
        for(const auto &e : g[u]) {
            if(!dfn[e.v]) {
                self(self, e.v);
                low[u] = min(low[u], low[e.v]);
            }
            else if(on[e.v]) {
                low[u] = min(low[u], dfn[e.v]);
            }
        }
        if(low[u] != dfn[u]) return;
        cc++;
        while(true) {
            int v = st.back();st.pop_back();
            on[v] = false;
            bel[v] = cc;
            if(v == u) break;
        }
    };
    for(int u = 1; u <= n; u++) {
        if(!dfn[u]) {
            dfs(dfs, u);
        }
    }
    return {cc, bel};
}


inline void solve() {
    int n; cin >> n;
    vector<i64> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<Edge>> g(n + 1);
    int m; cin >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].push_back({v});
    }
    auto [cc, bel] = TarjanSCC(g);
    vector<i64> c(cc + 1), v(cc + 1, INF); 
    for(int i = 1; i <= n; i++) {
        int id = bel[i];
        if(a[i] < v[id]) {
            v[id] = a[i];
            c[id] = 1;
        }
        else if(a[i] == v[id]) {
            c[id]++;
        }
    }
    i64 ans = 0, cnt = 1;
    rep(i, 1, cc) {
        ans += v[i];
        cnt = (1LL * cnt * c[i]) % MOD;
    }
    cout << ans << " " << cnt << endl;
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