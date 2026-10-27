#include <bits/stdc++.h>
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
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


// 4.割边与边双连通分量
class EdgeBCC {
public:
    int n, tim = 0, fa;
    vector<array<int, 2>> edges;
    vector<vector<array<int, 2>>> g;
    vector<int> dfn, low; // dfn[u] 是进入时间，low[u] 是不经过父边能到达的最早时间
    vector<bool> bridge; // bridge[i] 标记第 i 条边是否为桥
    vector<int> d, s;
    string ans;
    bool f = 0;
private:
    void dfs(int u, int pe, bool f = 0) {
        // u 是当前点,pe 是进入 u 的边编号,计算 low 并标记桥，无返回值
        dfn[u] = low[u] = ++tim;
        if(!f) s[u] = d[u];
        for(const auto &[v, id] : g[u]) {
            if (id == pe) {
                continue;
            }
            if (!dfn[v]) {
                dfs(v, id, f);
                low[u] = min(low[u], low[v]);
                if(!f) s[u] ^= s[v];
                if (low[v] > dfn[u]) {
                    bridge[id] = true;
                    // if(f) {
                    //     dbg(id)dbg(s[v])
                    // }
                    if(f and (s[v] or s[fa] ^ s[v])) {
                        ans[id] = '0';
                    }
                }
            }
            else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
public:
    EdgeBCC(int n) : n(n), g(n + 1), dfn(n + 1), low(n + 1), d(n + 1), s(n + 1) {}
    int addEdge(int u, int v) {
        int id = edges.size();
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
        return id;
    }

    void build() {
        // 无参数,重新计算全部桥,无返回值.
        tim = 0;
        fill(dfn.begin(), dfn.end(), 0);
        fill(low.begin(), low.end(), 0);
        bridge.assign(edges.size(), false);
        ans.assign(edges.size(), '1');
        for (int u = 1; u <= n; u++) {
            if (!dfn[u]) {
                fa = u;
                dfs(u, -1, 0);
                if(s[u]) {
                    f = 1;
                    return;
                }
            }
        }
        tim = 0;
        fill(dfn.begin(), dfn.end(), 0);
        fill(low.begin(), low.end(), 0);
        fill(bridge.begin(), bridge.end(), false);
        for (int u = 1; u <= n; u++) {
            if (!dfn[u]) {
                fa = u;
                dfs(u, -1, 1);
            }
        }
    }

    const vector<bool> &bridges() const {
        return bridge;
    }

    pair<int, vector<int>> comps() const {
        // 无参数,返回删除全部桥后每个点的边双连通分量编号.
        vector<int> bel(n + 1, -1);
        int cc = 0;
        for (int s = 1; s <= n; s++) {
            if (bel[s] != -1) {
                continue;
            }
            queue<int> q;
            q.push(s);
            bel[s] = ++cc;
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (const auto &[v, id] : g[u]) {
                    if (!bridge[id] && bel[v] == -1) {
                        bel[v] = bel[u];
                        q.push(v);
                    }
                }
            }
        }
        return {cc, bel};
    }
};



inline void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b; a = '0' + a + '0', b = '0' + b + '0';
    EdgeBCC g(n + 1);
    vector<int> d(n + 2);
    rep(i, 1, n + 1) {
        int x = (a[i] - '0') ^ (b[i] - '0');
        int p = (a[i - 1] - '0') ^ (b[i - 1] - '0');
        g.d[i] = x ^ p;
    }
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        v++;
        g.addEdge(u, v);
    }
    g.build();
    if(g.f) {
        cout << string(m, '0') << endl;
        return;
    }
    cout << g.ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
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