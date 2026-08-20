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

template <class T , class F>
class ST1 {
public:
    int n, lg2;
    vector<vector<T>> st;
    F op;
    ST1(const vector<T>& a, F f = {}): n(a.size() - 1), op(f) {
        lg2 = n ? bit_width(unsigned(n)) : 0;
        st.assign(lg2 + 1, vector<T>(n + 1));
        if(!n) return;
        st[0] = a;
        for(int p = 1; p <= lg2; p++) {
            for(int i = 1; i + (1LL << p) - 1 <= n; i++) {
                st[p][i] = op(st[p - 1][i], st[p - 1][i + (1LL << (p - 1))]);
            }
        }
    }

    T qry(int l, int r) const {
        assert(1 <= l && l <= r && r <= n);
        int p = bit_width(unsigned(r - l + 1)) - 1;
        T ans = op(st[p][l], st[p][r - (1LL << p) + 1]);
        return ans;
    }
};
class LCARMQ {
private:
    using pii = pair<int, int>;
    struct MinDepth {
        pii operator() (pii a, pii b) const {
            return min(a, b);
        }
    };
public:
    vector<int> first;
    ST1 <pii, MinDepth> st;
    static pair<vector<int>, vector<pii>> tour(const vector<vector<Edge>>& g, int root) {
        vector<int> first(g.size(), -1);
        vector<pii> euler(1);
        auto dfs = [&](auto &&self, int u, int f, int dep)->void {
            if(first[u] == -1) {
                first[u] = euler.size();
            }
            euler.push_back({dep, u});
            for(const auto &e : g[u]) {
                if(e.v == f) continue;
                self(self, e.v, u, dep + 1);
                euler.push_back({dep, u});
            }
        };
        dfs(dfs, root, 0, 0);
        return {first, euler};
    }
    LCARMQ(const vector<vector<Edge>>& g, int root = 1): LCARMQ(tour(g, root)){}
    int lca(int u, int v) const {
        int l = first[u], r = first[v];
        if(l > r) swap(l, r);
        return st.qry(l, r).second;
    } 
private:
    LCARMQ(pair<vector<int>, vector<pii>> p): first(move(p.first)), st(move(p.second), MinDepth{}){}
};


inline void solve() {
    int n ,m; cin >> n >> m;
    vector<int> w(n + 1);
    rep(i, 1, n) cin >> w[i];
    vector<vector<Edge>> g(n + 1);
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    LCARMQ lca(g);
    vector<int> c(n + 1), pa(n + 1);
    vector<int> a, b(1, 0);
    vector<i64> sa(n + 1);
    i64 ans = 0;
    while(m--) {
        int op, u; cin >> op >> u;
        if(op == 2) {
            b.push_back(u);
            for(int &v : a) {
                ans += w[lca.lca(v, u)] * c[v];
            }
        }
        else {
            if(!pa[u]) {
                pa[u] = 1;
                a.push_back(u);
            }
            ++c[u];
            int k = b.size() - 1;
            while(pa[u] <= k) {
                sa[u] += w[lca.lca(u, b[pa[u]])];
                pa[u]++;
            }
            ans += sa[u];
        }
        cout << ans << endl;
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