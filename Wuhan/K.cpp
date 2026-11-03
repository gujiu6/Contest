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
constexpr int MOD = 998244353;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-12;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


int f[MAXX + 1], inv[MAXX + 1];
i64 pow(i64 a, i64 b){
    i64 ans = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
void init() {
    f[0] = 1;
    for(int i = 1; i <= MAXX; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    inv[MAXX] = pow(f[MAXX], MOD - 2);
    for(int i = MAXX - 1; i >= 0; i--){
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}


inline void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1), b(n + 1), sz(n + 1), dp(n + 1), indeg(n + 1), outdeg(n + 1), p(n + 1);
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    for(int v = 2; v <= n; v++) {
        int &u = p[v];
        if(a[v] > b[u]) {
            outdeg[v]++;
            indeg[u]++;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        else if(b[v] > a[u]) {
            outdeg[u]++;
            indeg[v]++;
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    auto dfs = [&](auto &&self, int u, int fa)->void {
        dp[u] = 1;
        sz[u] = 1;
        for(const auto &v : g[u]) {
            if(v == fa) continue;
            self(self, v, u);
            sz[u] += sz[v];
            dp[u] = dp[u] * dp[v] % MOD * inv[sz[v]] % MOD;
        }
        dp[u] = dp[u] * f[sz[u] - 1] % MOD;
    };
    queue<int> q;
    vector<bool> vis(n + 1);
    int ans = f[n];
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        vector<int> vec;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            vec.push_back(u);
            for(const auto &v : g[u]) {
                if(vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        int root = 0, cnt = 0;
        for (int u : vec) {
            if (indeg[u] == 0) {
                root = u;
                cnt++;
            }
        }
        if (cnt != 1) {
            for (int u : vec) {
                if (outdeg[u] == 0) {
                    root = u;
                    break;
                }
            }
        }
        dfs(dfs, root, 0);
        ans = ans * dp[root] % MOD * inv[sz[root]] % MOD;
    }
    cout << ans << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    init();
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