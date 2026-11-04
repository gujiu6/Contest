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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    int s = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            if(s != 0) {
                cout << -1 << endl;
                return;
            }
            else {
                s = i;
            }
        }
    }
    if(s == 0) {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++) {
        int d; cin >> d;
        while(d--) {
            int x; cin >> x;
            g[i].push_back(x);
        }
        sort(all(g[i], 0), [&](const auto &x, const auto &y){
            return a[x] < a[y];
        });
    }
    vector<bool> vis(n + 1);
    bool f = 0;
    auto dfs = [&](auto &&self, int u) {
        vis[u] = 1;
        if(f) return ; 
        for(const auto &v : g[u]) {
            if(vis[v]) continue;
            if(a[v] == a[u] + 1) {
                self(self, v);
            }
            else {
                f = 1;
                break;
            }
        }
    };
    dfs(dfs, s);
    if(f) {
        cout << -1 << endl;
        return;
    }
    cout << s << endl;
    for(int i = 1; i <= n; i++) {
        for(int &x : g[i]) {
            cout << x << " ";
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