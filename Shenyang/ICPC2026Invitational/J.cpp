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
constexpr ld eps = 1e-12;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


// 2.Point / Vector
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
namespace {

template <class T> int sgn(T x) {
    // x 是整数;返回 -1、0、1 表示负、零、正.
    return (x > 0) - (x < 0);
}

int sgn(ld x) {
    // x 表示待判断的浮点数；返回 -1、0、1 表示负、近似零、正。
    ld t = eps * max<ld>(1, fabsl(x));
    return (x > t) - (x < -t);
}

template <class T> bool eq(T x, T y) {
    // x、y 是整数;返回二者是否相等.
    return x == y;
}

bool eq(ld x, ld y) {
    // x、y 表示两个浮点数;使用相对误差判断它们是否近似相等.
    return fabsl(x - y) <= eps * max<ld>(1, max(fabsl(x), fabsl(y)));
}

}
// 3.点积、叉积、长度、夹角、旋转
namespace {

template <class T> T dot(const Point<T> &a, const Point<T> &b) {
    // a、b 表示两个向量;返回点积.
    return a.x * b.x + a.y * b.y;
}

template <class T> T cross(const Point<T> &a, const Point<T> &b) {
    // a、b 表示两个向量;返回有向叉积.
    return a.x * b.y - a.y * b.x;
}

template <class T> T cross(const Point<T> &a, const Point<T> &b, const Point<T> &c){
    // a、b、c 表示三个点;返回三角形 abc 的有向面积两倍.
    return cross(b - a, c - a);
}

template <class T> T square(const Point<T> &a) {
    // a 表示向量;返回模长平方.
    return dot(a, a);
}

template <class T> ld abs(const Point<T> &a) {
    // a 表示向量;返回其欧氏模长.
    return sqrtl((ld)square(a));
}

template <class T> ld angle(const Point<T> &a, const Point<T> &b) {
    // a、b 是非零向量;返回 a 到 b 的有向夹角,范围为 (-pi,pi].
    return atan2l(cross(a, b), dot(a, b));
}

template <class T> Point<ld> rotate(const Point<T> &a, ld t) {
    // a 表示向量,t 表示逆时针旋转弧度;返回旋转后的浮点向量.
    return {a.x * cosl(t) - a.y * sinl(t), a.x * sinl(t) + a.y * cosl(t)};
}

template <class T> Point<T> rot(const Point<T> &a) {
    // a 表示向量;返回逆时针旋转 90 度后的向量.
    return {-a.y, a.x};
}

}

inline void solve() {
    int n, q; cin >> n >> q;
    vector<Point<int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(all(a, 0));
    vector<Point<int>> h;
    vector<int> Y;
    for(int i = 0; i < n; i++) {
        while(h.size() >= 2 and sgn(cross(h.back() - h[h.size() - 2], a[i] - h.back())) >= 0) {
            h.pop_back();
        }
        if(h.empty()) {
            Y.push_back(1);
        }
        else {
            Y.push_back(max(1LL, (int)ceil(((ld)a[i].x * h.back().y - a[i].y * h.back().x) / (a[i].x - h.back().x))));
        }
        h.push_back(a[i]);
    }
    sort(all(Y, 0));
    // for(int y : Y) cout << y << endl;
    while(q--) {
        int y; cin >> y;
        cout << upper_bound(all(Y, 0), y) - Y.begin() << endl;
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
