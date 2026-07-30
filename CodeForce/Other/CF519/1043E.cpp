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


struct Node {
    ll x, y, d;
    int id;
    bool operator< (const Node &other) const {
        return d < other.d;
    }
};



inline void solve() {
    int n, m; cin >> n >> m;
    vector<Node> a(n + 1);
    vector<int> pos(n + 1);
    rep(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        a[i].d = a[i].x - a[i].y;
        a[i].id = i;
    }
    sort(all(a, 1));
    vector<ll> pre_x(n + 2), pre_y(n + 2), suf_x(n + 2), suf_y(n + 2);
    rep(i, 1, n) pre_x[i] = pre_x[i - 1] + a[i].x, pre_y[i] = pre_y[i - 1] + a[i].y;
    per(i, n, 1) suf_x[i] = suf_x[i + 1] + a[i].x, suf_y[i] = suf_y[i + 1] + a[i].y;
    vector<ll> ans(n + 1);
    rep(i, 1, n) {
        int id = a[i].id;
        pos[id] = i;
        ans[id] = (pre_x[i - 1] + 1LL * (i - 1) * a[i].y) + (suf_y[i + 1] + 1LL * (n - i) * a[i].x);
    }
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        int id_u = pos[u], id_v = pos[v];
        ans[u] -= min(a[id_u].x + a[id_v].y, a[id_u].y + a[id_v].x);
        ans[v] -= min(a[id_u].x + a[id_v].y, a[id_u].y + a[id_v].x);
    }
    rep(i, 1, n) cout << ans[i] << " ";
    cout << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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