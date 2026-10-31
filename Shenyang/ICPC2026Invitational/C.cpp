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
constexpr ld eps = 1e-12;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve() {
    int n, m, s; cin >> n >> m >> s;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<pii>> g(n + 1);
    map<pii, int> mp;
    vector<bool> vis(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        mp[{u, v}] = max(mp[{u, v}], w);
    }
    for(const auto &[e, w] : mp) {
        auto &[u, v] = e;
        if(u == v) b[u] = w;
        else g[u].push_back({v, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int mx = a[s], pos = s;
    vis[s] = 1;
    for(const auto &[v, w] : g[s]) {
        b[v] += w;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(a[i] + b[i] > mx or a[i] + b[i] == mx and i >= pos) {
            q.push({a[i], i});
        }
    }
    for(int i = 1; i < n; i++) {
        while(!q.empty() and (vis[q.top()[1]] or q.top()[0] + b[q.top()[1]] < mx or (q.top()[0] + b[q.top()[1]] == mx and q.top()[1] < pos))) {
            q.pop();
        }
        if(q.empty()) {
            cout << "NO" << endl;
            return;
        }
        auto [val, u] = q.top(); q.pop();
        vis[u] = 1;
        // dbg(u)
        if(a[u] > mx) {
            mx = a[u];
            pos = u;
        }
        else if(a[u] == mx) {
            pos = max(pos, u);
        }
        for(const auto &[v, w] : g[u]) {
            b[v] += w;
            if(vis[v]) continue;
            if(a[v] + b[v] > mx or a[v] + b[v] == mx and v >= pos) {
                q.push({a[v], v});
            }
        }
    }
    cout << "YES" << endl;
    
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