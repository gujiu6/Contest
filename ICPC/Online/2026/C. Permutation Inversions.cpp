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






inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<Edge>> g(n + 1);
    vector<int> deg(n + 1);
    rep(i, 1, m) {
        int l, r; cin >> l >> r;
        int x = r - l + 1;
        int p = 0;
        rep(j, 1, x) {
            int c; cin >> c;
            if(p) {
                g[p].push_back({c});
                deg[c]++;
            }
            p = c;
        }
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> res(n + 1);
    vector<int> ans;
    int idx = 1;
    while(!pq.empty()) {
        auto u = pq.top();pq.pop();
        ans.push_back(u);
        res[u] = idx++;
        for(auto &e : g[u]) { 
            if(--deg[e.v] == 0) {
                pq.push(e.v);
            }
        }
    }
    if(ans.size() < n) {
        cout << -1 << endl;
    }
    else {
        for(int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
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