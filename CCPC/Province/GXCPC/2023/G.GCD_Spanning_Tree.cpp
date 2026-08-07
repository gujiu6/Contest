#include <bits/stdc++.h>
#include <cassert>
//#include <bit>
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
using i64 = long long;
using i128 = __int128_t;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 1e6+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

array<int, MAXX> fa;
int cnt;
void build(int n) {
    iota(fa.begin(), fa.begin() + n + 1, 0);
}

int find(int i) {
    if(i != fa[i]) {
        fa[i] = find(fa[i]);
    }
    return fa[i];
}
bool merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    fa[x] = y;
    cnt--;
    return true;
}

struct Medge {
    int u, v;
    i64 w;
};
vector<int> M[MAXX + 1];
int ans[MAXX + 1];

inline void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<Medge> edge(m + 1);
    int mx = 1;
    for(int i = 1; i <= m; i++) {
        int u, v; i64 w;cin >> u >> v >> w;
        edge[i] = {u, v, w};
        for(int d = 1; d * d <= w; d++) {
            if(w % d == 0) {
                int dd = w / d;
                M[d].push_back(i);
                if(dd != d) M[dd].push_back(i);
                mx = max({mx, d, dd});
            }
        }
    }
    // dbg(mx)
    build(n);
    for(int i = 0; i <= MAXX; i++) {
        ans[i] = n - 1;
    }
    for(int d = 1; d <= mx; d++) {
        auto &v = M[d];
        // dbg(v.size())
        if(v.empty()) continue;
        cnt = n;
        for(int i : v) {
            auto &[u, v, w] = edge[i];
            merge(u, v);
        }
        ans[d] = cnt - 1;
        for(int i : v) {
            auto &[u, v, w] = edge[i];
            fa[u] = u;
            fa[v] = v;
        }
    }


    while(q--) {
        int x; cin >> x;
        cout << ans[x] << endl;
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