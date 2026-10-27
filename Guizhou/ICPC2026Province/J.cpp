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
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


template <class T> struct Point {
    T x, y;
    Point(const T &x = 0, const T &y = 0) : x(x), y(y) {}

    template <class U> explicit operator Point<U>() const {
        // U 表示目标坐标类型；返回逐坐标 C 风格转换后的点.
        return Point<U>((U)x, (U)y);
    }

    Point &operator+=(const Point &p) {
        // p 表示另一个向量;把 p 加到当前向量并返回自身.
        x += p.x;
        y += p.y;
        return *this;
    }

    Point &operator-=(const Point &p) {
        // p 表示另一个向量;从当前向量减去 p 并返回自身.
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point &operator*=(const T &k) {
        // k 表示缩放倍数;原地数乘并返回自身.
        x *= k;
        y *= k;
        return *this;
    }

    Point &operator/=(const T &k) {
        // k 表示非零除数;原地除法并返回自身.
        assert(k != T(0));
        x /= k;
        y /= k;
        return *this;
    }

    Point operator-() const {
        // 无参数;返回反向向量.
        return {-x, -y};
    }

    friend Point operator+(Point a, const Point &b) {
        // a、b 表示两个向量;返回逐坐标之和。
        return a += b;
    }

    friend Point operator-(Point a, const Point &b) {
        // a、b 表示两个点或向量;返回 a-b.
        return a -= b;
    }

    friend Point operator*(Point a, const T &k) {
        // a 表示向量,k 表示倍数;返回缩放后的向量.
        return a *= k;
    }

    friend Point operator*(const T &k, Point a) {
        // k 表示倍数,a 表示向量;返回缩放后的向量.
        return a *= k;
    }

    friend Point operator/(Point a, const T &k) {
        // a 表示向量,k 表示非零除数;返回缩放后的向量.
        return a /= k;
    }

    friend bool operator<(const Point &a, const Point &b) {
        // a、b 表示两个点;返回按 x、y 的字典序比较结果.
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    }

    friend bool operator==(const Point &a, const Point &b) {
        // a、b 表示两个点;返回坐标是否精确相等.
        return a.x == b.x && a.y == b.y;
    }
};

template <class T> T cross(const Point<T> &a, const Point<T> &b) {
    // a、b 表示两个向量;返回有向叉积.
    return a.x * b.y - a.y * b.x;
}

inline void solve() {
    int n, q; cin >> n >> q;
    vector<Point<int>> a(n);
    vector<pii> X(q);
    vector<int> Pre(q + 1), ans(q + 1);
    rep(i, 0, n - 1) cin >> a[i].x >> a[i].y;
    rep(i, 0, q - 1) {
        cin >> X[i][0];
        X[i][1] = i;
    }
    sort(all(X, 0));
    rep(i, 0, n - 1) {
        int pre = ((i - 1) % n + n) % n;
        int nxt = ((i + 1) % n + n) % n;
        int x = 0;
        if(a[pre].y > a[i].y and a[nxt].y > a[i].y and cross(a[pre] - a[i], a[i] - a[nxt]) < 0) {
            x = -1;
        }
        if(a[pre].y < a[i].y and a[nxt].y < a[i].y and cross(a[pre] - a[i], a[i] - a[nxt]) > 0) {
            x = 1;
        }
        if(x) {
            int r = upper_bound(all(X, 0), pii{a[i].y, -1}) - X.begin();
            Pre[0] += x;
            Pre[r] -= x;
        }
    }
    ans[X[0][1]] = Pre[0];
    for(int i = 1; i <= q - 1; i++) {
        Pre[i] += Pre[i - 1];
        ans[X[i][1]] = Pre[i];
    }
    for(int i = 0; i <= q - 1; i++) {
        cout << ans[i] << endl;
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