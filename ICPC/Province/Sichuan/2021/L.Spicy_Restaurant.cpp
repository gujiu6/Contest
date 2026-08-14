#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
// #define int long long
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
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 1e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};




int dis[MAXX][101];

inline void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> w(101); 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        w[x].push_back(i);
    }
    vector<vector<Edge>> g(n + 1);
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 100; j++) {
            dis[i][j] = INF;
        }
    }
    for(int ww = 1; ww <= 100; ww++) {
        queue<int> q;
        for(int u : w[ww]) {
            q.push(u);
            dis[u][ww] = 0;
        }
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto e : g[u]) {
                if(dis[e.v][ww] == INF) {
                    dis[e.v][ww] = dis[u][ww] + 1;
                    q.push(e.v);
                }
            }
        }
    }
    for(int u = 1; u <= n; u++) {
        for(int w = 2; w <= 100; w++) {
            dis[u][w] = min(dis[u][w - 1], dis[u][w]);
        }
    }
    while(q--) {
        int u, w; cin >> u >> w;
        cout << (dis[u][w] == INF ? -1 : dis[u][w]) << endl;
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