#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
#define int long long
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
constexpr ll INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> inDeg(n + 1);
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        inDeg[v]++;
    }
    int k; cin >> k;
    int p;
    vector<int> vis(n + 1, 0);
    rep(i, 1, k) cin >> p, vis[p] = i;
    queue<int> q2;
    priority_queue<pii, vector<pii>, greater<pii>> q1;
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            if(vis[i]) q1.push({vis[i], i});
            else q2.push(i); 
        }
    }
    vector<int> ans;
    while(!q2.empty()) {
        auto u = q2.front();q2.pop();
        ans.push_back(u);
        for(int v : g[u]) {
            if(--inDeg[v] == 0) {
                if(vis[v]) q1.push({vis[v], v});
                else q2.push(v);
            }
        }
    }
    int pre = 0;
    while(!q1.empty()) {
        auto [f, u] = q1.top();q1.pop();
        if(f != pre + 1) {
            cout << -1 << endl;
            return;
        }
        ans.push_back(u);
        pre = f;
        for(int v : g[u]) {
            if(--inDeg[v] == 0) {
                if(vis[v]) q1.push({vis[v], v});
                else q2.push(v);
            }
        }
    }
    if(pre != k) {
        cout << -1 << endl;
        return;
    }
    while(!q2.empty()) {
        auto u = q2.front();q2.pop();
        ans.push_back(u);
        for(int v : g[u]) {
            if(--inDeg[v] == 0) {
                if(vis[v]) q1.push({vis[v], v});
                else q2.push(v);
            }
        }
    }
    if(ans.size() == n) {
        for(int x : ans) cout << x << " ";
        cout << endl;
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
    //cin >> t;
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