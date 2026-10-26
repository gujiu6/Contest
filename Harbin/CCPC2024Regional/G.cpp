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






inline void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> vis(n + 1);
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        vis[x] = 1;
    }
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = 0;
    vector<bool> v(n + 1);
    vector<vector<int>> res;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        q.push(i);
        v[i] = 1;
        s++;
        break;
    }
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        if(vis[u]) continue;
        res.push_back({});
        res.back().push_back(u);
        for(const auto &vv : g[u]) {
            if(v[vv]) continue;
            q.push(vv);
            s++;
            v[vv] = 1;
            res.back().push_back(vv);
        }
        if(s == n) break;
    }
    if(s == n) {
        cout << "Yes" << endl;
        int ss = 0;
        for(const auto &vv : res) {
            if(vv.size() <= 1) continue;
            ss++;
        }
        cout << ss << endl;
        for(const auto &vv : res) {
            if(vv.size() <= 1) continue;
            cout << vv[0] << " ";
            cout << vv.size() - 1 << " ";
            for(int i = 1; i < vv.size(); i++) {
                cout << vv[i] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
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