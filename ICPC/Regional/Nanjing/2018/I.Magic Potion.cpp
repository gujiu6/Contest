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


//1.Dinic最大流
template <class T = int>
class Flow {
public:
    struct E {
        int v, rev;//v:转移目标状态;rev:反向边编号
        T cap;//剩余容量
    };
    int n;//残量网络点数
    vector<vector<E>> e;//每个点发出的残量边
    vector<int> h, cur;//h:Dinic层次图中的距离标号,cur:每个点尚未尝试的第一条残量边下标
    Flow(int n = 0): n(n), e(n + 1), h(n + 1), cur(n + 1) {}
    //添加有向边u->v,容量c
    int add(int u, int v, T c) {
        int id = e[u].size();
        e[u].push_back({v, (int)e[v].size(), c});
        e[v].push_back({u, id, 0});
        return id;
    }
    //BFS建立层次图
    bool bfs(int s, int t) {
        fill(h.begin(), h.end(), -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(const auto &[v, r, c] : e[u]) {
                if(c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    q.push(v);
                }
            }
        }
        return h[t] != -1;
    }
    //DFS增广
    T dfs(int u, int t, T f) {
        if(u == t) return f;
        T ans = 0;
        for(int &i = cur[u]; i < e[u].size(); i++) {
            auto &a = e[u][i];
            if(a.cap == 0 || h[a.v] != h[u] + 1) {
                continue;
            }
            T d = dfs(a.v, t, min(f - ans, a.cap));
            a.cap -= d;
            e[a.v][a.rev].cap += d;
            ans += d;
            if(ans == f) break;
        }
        return ans;
    }
    //最大流
    T flow(int s, int t, T lim = numeric_limits<T>::max()) {
        T ans = 0;
        while(ans < lim && bfs(s, t)) {
            fill(cur.begin(), cur.end(), 0);
            ans += dfs(s, t, lim - ans);
        }
        return ans;
    }
    //最大流结束后,返回残量网络中从s可达的点集,即最小割的源点
    vector<bool> cut(int s) const {
        vector<bool> vis(n + 1);
        queue<int> q;
        vis[s] = true;
        q.push(s);
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(const auto &[v, r, c] : e[u]) {
                if(c > 0 && !vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return vis;
    }
};



inline void solve() {
    int n, m, k; cin >> n >> m >> k;
    int s = 0, mid = n + 1, t = n + m + 2;
    Flow g(t);
    g.add(s, mid, k);
    for(int u = 1; u <= n; u++) {
        g.add(s, u, 1);
        g.add(mid, u, 1);
        int x; cin >> x;
        while(x--) {
            int v; cin >> v;
            g.add(u, n + 1 + v, 1);
        }
    }
    for(int u = 1; u <= m; u++) {
        g.add(n + 1 + u, t, 1);
    }
    cout << g.flow(s, t) << endl;
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