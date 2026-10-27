#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
// #define int long long
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
//1.1 KrusKal
template <class T = i64>
T KrusKal(vector<DEdge> &edge, int n) {
    sort(edge.begin(), edge.end(), [](const DEdge& a, const DEdge& b){
        return a.w < b.w;
    });
    DSU d(n);
    T ans = 0;
    int cnt = 0;
    for(const auto &e : edge) {
        if(!d.merge(e.u, e.v)) continue;
        cnt++;
        ans += e.w;
        if(cnt == n - 1) break;
    }
    return ans;
}


inline void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    int mx = 0;
    rep(i, 1, n) {
        cin >> c[i];
        mx = max(mx, c[i]);
    }
    vector<int> min_d(mx + 1);
    rep(i, 1, n) {
        int v = c[i];
        for(int d = 1; d * d <= v; d++) {
            if(v % d == 0) {
                if(min_d[d] == 0 || v < c[min_d[d]]) {
                    min_d[d] = i;
                }
                int d2 = v / d;
                if(d2 != d) {
                    if(min_d[d2] == 0 || v < c[min_d[d2]]) {
                        min_d[d2] = i;
                    }
                }
            }
        }
    }
    auto get = [&](i64 a, i64 b)->i64 {
        return gcd(a, b) + lcm(a, b);
    };
    vector<DEdge> edges;
    rep(i, 1, n) {
        int v = c[i];
        vector<int> t;
        for(int d = 1; d * d <= v; d++) {
            if(v % d == 0) {
                if(min_d[d] != i) {
                    t.push_back(min_d[d]);
                }
                int d2 = v / d;
                if(d2 != d && min_d[d2] != i) {
                    t.push_back(min_d[d2]);
                }
            }
        }
        sort(all(t, 0));
        t.erase(unique(all(t, 0)), t.end());
        for(const auto &u : t) {
            edges.push_back({i, u, get(c[i], c[u])});
        }
    }
    auto ans = KrusKal(edges, n);
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