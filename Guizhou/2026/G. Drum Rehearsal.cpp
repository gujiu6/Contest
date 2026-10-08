#include <bits/stdc++.h>
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


struct Tag {
    bool vis = false;
    // 先执行当前 Tag，再执行 t
    void apply(const Tag& t) {
        vis ^= t.vis;
    }
};
struct Info {
    i64 sum = 0;
    i64 mx = 0;
    i64 pre_mx = 0, pre_mn = 0;
    i64 suf_mx = 0, suf_mn = 0;
    i64 mn = 0;
    int len = 0;
    Info() = default;
    Info(i64 x) {
        sum = x;
        pre_mx = x;
        pre_mn = x;
        suf_mx = x;
        suf_mn = x;
        mx = x;
        mn = x;
        len = 1;
    }
    void apply(const Tag& t) {
        if(t.vis) {
            sum = -sum;
            swap(mn, mx);
            mn = -mn;
            mx = -mx;
            swap(pre_mn, pre_mx);
            pre_mn = -pre_mn;
            pre_mx = -pre_mx;
            swap(suf_mn, suf_mx);
            suf_mn = -suf_mn;
            suf_mx = -suf_mx;
        }
    }
    friend Info operator+ (const Info& a, const Info& b) {
        Info c;
        c.len = a.len + b.len;
        c.pre_mx = max(a.pre_mx, a.sum + b.pre_mx);
        c.pre_mn = min(a.pre_mn, a.sum + b.pre_mn);
        c.suf_mx = max(b.suf_mx, b.sum + a.suf_mx);
        c.suf_mn = min(b.suf_mn, b.sum + a.suf_mn);
        c.sum = a.sum + b.sum;
        c.mx = max({a.mx, b.mx, a.suf_mx + b.pre_mx});
        c.mn = min({a.mn, b.mn, a.suf_mn + b.pre_mn});
        return c;
    }
};
template <class Info = Info, class Tag = Tag>
class LazySeg {
public:
    int n;
    vector<Info> tr;
    vector<Tag> tag;
    LazySeg(int n = 0):n(n), tr((n << 2) + 4, Info{}), tag((n << 2) + 4, Tag{}) {
        if(n) build(1, 1, n);
    }
    LazySeg(const vector<Info>& a): n(a.size() - 1), tr((n << 2) + 4, Info{}), tag((n << 2) + 4, Tag{}) {
        if(n) build(1, 1, n, a);
    }
private:
    void build(int p, int l, int r) {
        tr[p].len = r - l + 1;
        tr[p].sum = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }
    void build(int p, int l, int r, const vector<Info>& a) {
        if(l == r) {
            tr[p] = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        pull(p);
    }
    void pull(int p) {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void apply(int p, const Tag& t) {
        tr[p].apply(t);
        tag[p].apply(t);
    }
    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag{};
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
        if(ql <= l && r <= qr) return tr[p];
        push(p);
        int mid = (l + r) >> 1;
        if(qr <= mid) return qry(p << 1, l, mid, ql, qr);
        if(ql > mid) return qry(p << 1 | 1, mid + 1, r, ql, qr);
        return qry(p << 1, l, mid, ql, qr) + qry(p << 1 | 1, mid + 1, r, ql, qr);
    }
public:
    // 区间信息
    Info qry(int l, int r) {
        return qry(1, 1, n, l, r);
    }
    void op(int l, int r) {
        modify(1, 1, n, l, r, Tag{.vis = 1});
    }
};



inline void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = Info(s[i - 1] == '0' ? -1 : 1);
    }
    LazySeg seg(a);
    while(q--) {
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) {
            seg.op(l, r);
        }
        else {
            Info res = seg.qry(l, r);
            cout << max({llabs(res.sum), res.sum - res.mn, res.mx - res.sum}) << endl;
        }
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