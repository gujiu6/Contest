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
    vector<pair<ll, int>> arr(n + 1);
    rep(i, 1, n) cin >> arr[i].first, arr[i].second = i;
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, INF));
    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, INF));
    rep(i, 1, n) {
        g[i][i] = 0;
    }
    rep(i, 1, m) {
        int u, v; ll w; cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    sort(all(arr, 1));
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++) pos[arr[i].second] = i;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], max(g[i][arr[k].second], g[arr[k].second][j]));
                if(g[i][j] != INF) {
                    ll mx = max({arr[pos[i]].first, arr[pos[j]].first, arr[k].first});
                    ans[i][j] = min(ans[i][j], mx * g[i][j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) cout << 0;
            else cout << (ans[i][j] == INF ? -1 : ans[i][j]);
            cout << " ";
        }
        cout << endl;
    }
    
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    //cin>>t;
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