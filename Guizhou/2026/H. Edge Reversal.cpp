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
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


//2.SPFA最小费用最大流
template <class T = i64, class Cost = i64>
struct SpfaCostFlow {
    struct E {
        int v, rev;
        T cap;
        Cost cost;     // 单位流量费用
    };
    int n;
    vector<vector<E>> edges;
    vector<optional<Cost>> d;// 是本轮从源点出发的最短距离,空值表示不可达
    vector<int> in, cur, vis;

    SpfaCostFlow(int n = 0) : n(n + 1), edges(n + 1), d(n + 1), in(n + 1), cur(n + 1), vis(n + 1) {}
    void add(int u, int v, T cap, Cost cost) {
        int id = edges[u].size();
        int rev = edges[v].size() + (u == v);
        edges[u].push_back({v, rev, cap, cost});
        edges[v].push_back({u, id, 0, -cost});
    }

    bool shortest(int s, int t) {
        fill(d.begin(), d.end(), nullopt);
        fill(in.begin(), in.end(), 0);
        queue<int> q;
        d[s] = 0;
        q.push(s);
        in[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            in[u] = 0;
            for (const auto &e : edges[u]) {
                if (e.cap == 0) {
                    continue;
                }
                auto nd = *d[u] + e.cost;
                if (!d[e.v].has_value() || nd < *d[e.v]) {
                    d[e.v] = nd;
                    if (!in[e.v]) {
                        q.push(e.v);
                        in[e.v] = 1;
                    }
                }
            }
        }
        return d[t].has_value();
    }

    T dfs(int u, int t, T lim) {
        if (u == t) {
            return lim;
        }
        vis[u] = 1;
        T f = 0;
        for (int &i = cur[u]; i < (int)edges[u].size() && f < lim; i++) {
            auto &e = edges[u][i];
            if (e.cap == 0 || vis[e.v] || !d[e.v].has_value() || *d[u] + e.cost != *d[e.v]) {
                continue;
            }
            T x = dfs(e.v, t, min(lim - f, e.cap));
            e.cap -= x;
            edges[e.v][e.rev].cap += x;
            f += x;
        }
        vis[u] = 0;
        return f;
    }

    pair<T, Cost> flow(int s, int t, T lim = numeric_limits<T>::max()) {
        // s、t 是源汇点,lim 是最多发送的流量,返回实际流量与最小费用.
        if (s == t) {
            return {0, 0};
        }
        T f = 0;
        Cost cost = 0;
        while (f < lim && shortest(s, t)) {
            fill(cur.begin(), cur.end(), 0);
            fill(vis.begin(), vis.end(), 0);
            T x = dfs(s, t, lim - f);
            if (x == 0) break;
            f += x;
            cost += (Cost)x * (*d[t]);
        }
        return {f, cost};
    }
};



inline void solve() {
    int n, m; cin >> n >> m;
    SpfaCostFlow f(n + 5);
    int s = 0, t = n + 1;
    vector<int> deg(n + 1);
    int need = 0;
    vector<pii> edges;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        deg[v]++;
        edges.push_back({u, v});
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] > 1) {
            f.add(s, i, deg[i] - 1, 0);
        }
        else if(deg[i] == 0) {
            need++;
            f.add(i, t, 1, 0);
        }
    }
    for(const auto &[u, v] : edges) {
        f.add(v, u, 1, 1);
    }
    auto [flow, cost] = f.flow(s, t);
    if(flow == need) {
        cout << cost << endl;
    }
    else {
        cout << -1 << endl;
    }
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