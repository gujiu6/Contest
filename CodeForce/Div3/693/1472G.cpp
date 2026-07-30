#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    vector<ll> dis(n + 1, INF);
    queue<pair<ll, int>> q;
    vector<bool> vis(n + 1);
    q.push({1, 0});
    dis[1] = 0;
    vis[1] = 1;
    while(!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if(d != dis[u]) continue;
        for(auto v : g[u]) {
            int nxt_d = d + 1;
            if(!vis[v] && nxt_d < dis[v]) {
                vis[v] = 1;
                dis[v] = nxt_d;
                q.push({v, nxt_d});
            }
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
    auto dfs = [&](auto &&dfs, int u, int p) {
        if(dp[u][p] != INF) return dp[u][p];
        ll ans = dis[u];
        for(int v : g[u]) {
            if(dis[v] <= dis[u]) {
                if(p) ans = min(ans, dfs(dfs, v, p - 1));
            }
            else {
                ans = min(ans, dfs(dfs, v, p));
            }
        }
        return dp[u][p] = ans;
    };
    rep(i, 1, n) {
        dfs(dfs, i, 1);
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
    
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