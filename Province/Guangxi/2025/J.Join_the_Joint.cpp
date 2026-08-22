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


class HLD {
public:
    int n, tim = 0;
    vector<int> fa, dep, sz, in, rev, son, top;
    HLD(const vector<vector<Edge>>& g, int root = 1): n(g.size() - 1), fa(n + 1), sz(n + 1, 1), in(n + 1), rev(n + 1), son(n + 1), top(n + 1), dep(n + 1) {
        vector<int> ord{root};
        sz[0] = 0;
        dep[root] = 1;
        for(int i = 0; i < ord.size(); i++) {
            int u = ord[i];
            for(const auto &e : g[u]) {
                if(e.v == fa[u]) continue;
                ord.push_back(e.v);
                fa[e.v] = u;
                dep[e.v] = dep[u] + 1;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int &u = ord[i], &f = fa[u];
            sz[f] += sz[u];
            if(sz[u] > sz[son[f]]) {
                son[f] = u;
            }
        }
        auto dfs = [&](auto &&self, int u, int h)->void {
            top[u] = h;
            in[u] = ++tim;
            rev[tim] = u;
            if(son[u]) {
                self(self, son[u], h);
            }
            for(const auto &e : g[u]) {
                if(e.v == fa[u] || e.v == son[u]) continue;
                self(self, e.v, e.v);
            }
        };
        if(n) dfs(dfs, root, root);
    }
    int lca(int u, int v) {
        while(top[u] != top[v]) {
            if(dep[u] < dep[v]) {
                swap(u, v);
            }
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    template <class F> void path(int u, int v, F op, bool edge = false) {
        vector<pair<int, int>> right;
        while(top[u] != top[v]) {
            if(dep[u] >= dep[v]) {
                op(in[top[u]], in[u], true);
                u = fa[top[u]];
            }
            else {
                right.push_back({in[top[v]], in[v]});
                v = fa[top[v]];
            }
        }
        if(dep[u] >= dep[v]) {
            op(in[v] + edge, in[u], true);
        }
        else {
            right.push_back({in[u] + edge, in[v]});
        }
        reverse(right.begin(), right.end());
        for(const auto &[l, r] : right) {
            op(l ,r, false);
        }
    }
};
struct Tag {
    i64 add = 0;
    void apply(const Tag& t) {
        add += t.add;
    }
};
struct Info {
    i64 sum = 0;
    i64 c = 0;
    i64 w = 0;
    i64 len = 0;
    Info() = default;
    Info(i64 x) {
        w = x;
        sum = 0;
        c = 0;
        len = 1;
    }
    void apply(const Tag& t) {
        c += t.add;
        sum = (sum + t.add * w);
    }
    friend Info operator+ (const Info& a, const Info& b) {
        Info c;
        c.sum = a.sum + b.sum;
        c.w = a.w + b.w;
        c.c = a.c + b.c;
        c.len = a.len + b.len;
        return c;
    }
};
template <class Info = Info, class Tag = Tag>
class LazySeg {
public:
    int n;
    vector<Info> tr;
    vector<Tag> tag;
    LazySeg(const vector<Info>& a): n(a.size() - 1), tr((n << 2) + 4), tag((n << 2) + 4) {
        build(1, 1, n, a);
    }
private:
    void build(int p, int l, int r, const vector<Info>& a) {
        if(l == r) {
            tr[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pull(p);
    }
    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag{};
    }
    void pull(int p) {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void apply(int p, const Tag& t) {
        tr[p].apply(t);
        tag[p].apply(t);
    }
    void modify(int p, int l, int r, int ql, int qr, const Tag& t) {
        if(ql <= l && r <= qr) {
            apply(p, t);
            return;
        }
        push(p);
        int mid = (l + r) >> 1;
        if(ql <= mid) modify(p << 1, l, mid, ql, qr, t);
        if(qr > mid) modify(p << 1 | 1, mid + 1, r, ql, qr, t);
        pull(p);
    }
    Info qry(int p, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tr[p];
        }
        push(p);
        int mid = (l + r) >> 1;
        if(qr <= mid) return qry(p << 1, l, mid, ql, qr);
        if(ql > mid) return qry(p << 1 | 1, mid + 1, r, ql, qr);
        return qry(p << 1, l, mid, ql, qr) + qry(p << 1 | 1, mid + 1, r, ql, qr);
    }
public:
    void add(int l, int r, i64 x) {
        modify(1, 1, n, l, r, Tag{.add = x});
    }
    Info qry(int l, int r) {
        return qry(1, 1, n, l, r);
    }
};

inline void solve() {
    int n, m; cin >> n >> m;
    vector<i64> w(n + 1);
    rep(i, 1, n) cin >> w[i];
    vector<vector<Edge>> g(n + 1);
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    HLD hld(g);
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[hld.in[i]] = Info(w[i] - w[hld.fa[i]]);
    }
    array<LazySeg<>, 2> seg = {LazySeg(a), LazySeg(a)};
    i64 ans = 0;
    while(m--) {
        int op, u; cin >> op >> u;
        op--;
        hld.path(1, u, [&](int l, int r, bool rev) {
            ans += seg[1 ^ op].qry(l, r).sum;
        });
        hld.path(1, u, [&](int l, int r, bool rev) {
            seg[op].add(l, r, 1);
        });
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