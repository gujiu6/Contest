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
using i64 = long long;
using i128 = __int128_t;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};




class DSU {
private:
    int n;
    vector<int> fa,sz;
public:
    DSU(int n) : n(n), fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int i){
        if(fa[i] != i){
            fa[i] = find(fa[i]);
        }
        return fa[i];
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x){
        return sz[find(x)];
    }
};
struct MEdge {
    int u, v;
    i64 a, b, w;
};
optional<pair<i64, vector<MEdge>>> KrusKal(vector<MEdge> edge, int n, int x) {
    for(int i = 0; i < edge.size(); i++) {
        edge[i].w = edge[i].a + edge[i].b * x;
    }
    sort(edge.begin(), edge.end(), [](const MEdge& a, const MEdge& b){
        return a.w < b.w;
    });
    DSU d(n);
    vector<MEdge> use;
    i64 ans = 0;
    for(auto e : edge) {
        if(!d.merge(e.u, e.v)) continue;
        ans += e.w;
        use.push_back(e);
    }
    if(use.size() + 1 != n && n) {
        return nullopt;
    }
    return pair{ans, use};
}
int n, m, l, r;
inline void solve() {
    vector<MEdge> edge;
    for(int i = 0; i < m; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        edge.push_back({u, v, a, b});
    }
    auto ans1 = KrusKal(edge, n, l);
    auto ans2 = KrusKal(edge, n, r);
    auto ans = min(ans1 ? ans1->first : INF, ans2 ? ans2->first : INF);
    cout << ans << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(cin >> n >> m >> l >> r){
    
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