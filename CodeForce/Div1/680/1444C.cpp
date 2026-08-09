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
using i128 = __int128_t;
using ld = long double;
using ui64 = unsigned long long;
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



//3.可撤销DSU
struct RollbackDSU {
    vector<int> fa, sz;
    struct History {
        int x, px, sx;
        int y, py, sy;
        bool merged;
    };
    vector<History> st;
    RollbackDSU(int n = 0): fa(n + 1), sz(n + 1, 1){
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int i) const {
        while(fa[i] != i) {
            i = fa[i];
        }
        return i;
    }
    int snap() const {
        //返回当前回滚栈高度作为快照编号
        return st.size();
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            st.push_back({x, fa[x], sz[x], y, fa[y], sz[y], false});
            return false;
        }
        if(sz[x] < sz[y]) swap(x, y);
        st.push_back({x, fa[x], sz[x], y, fa[y], sz[y], true});
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    void rollback(int s) {
        //s:此前由snap返回的回滚栈高度;撤销到快照s时的并查集状态,无返回值
        while(st.size() > s) {
            auto [x, px, sx, y, py, sy, merged] = st.back();
            st.pop_back();
            if(merged) {
                fa[x] = px;
                sz[x] = sx;
                fa[y] = py;
                sz[y] = sy;
            }
        }
    }
    bool same(int x, int y) const {
        return find(x) == find(y);
    }
    int size(int i) const {
        return sz[find(i)];
    }
};


inline void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> bel(n + 1);
    vector<bool> vis(k + 1);
    int kk = k;
    rep(i, 1, n) {
        cin >> bel[i];
    }
    RollbackDSU d(2 * n);
    vector<array<int, 4>> edge;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        if(bel[u] > bel[v]) swap(u, v);
        if(bel[u] != bel[v]) {
            edge.push_back({u, bel[u], v, bel[v]});
        }
        else {
            if(vis[bel[u]]) continue;
            if(d.same(u, v)) {
                kk--;
                vis[bel[u]] = true;
            }
            else {
                d.merge(u, v + n);
                d.merge(v, u + n);
            }
        }
    }
    int ans = kk * (kk - 1) / 2;
    sort(all(edge, 0), [](const auto &x, const auto &y){
        if(x[1] != y[1]) return x[1] < y[1];
        return x[3] < y[3];
    });
    for(int l = 0; l < edge.size();) {
        int r = l;
        int u_team = edge[l][1], v_team = edge[l][3];
        while(r < edge.size() && edge[r][1] == u_team && edge[r][3] == v_team) {
            r++;
        }
        if(!vis[u_team] && !vis[v_team]) {
            int p = d.snap();
            for(int i = l; i < r; i++) {
                int u = edge[i][0], v = edge[i][2];
                if(d.same(u, v)) {
                    ans--;
                    break;
                }
                else {
                    d.merge(u, v + n);
                    d.merge(v, u + n);
                }
            }
            d.rollback(p);
        }
        l = r;
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