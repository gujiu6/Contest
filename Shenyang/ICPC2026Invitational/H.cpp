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



void fft(vector<cd> &a, bool inv = false) {
    // a 是待变换序列,inv 表示是否做逆变换;原地完成 FFT,逆变换已除以长度.
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int k = n >> 1;
        while (j & k) {
            j ^= k;
            k >>= 1;
        }
        j ^= k;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cosl(ang), sinl(ang));
        for (int l = 0; l < n; l += len) {
            cd w{1.0L, 0.0L};
            for (int j = 0; j < len / 2; j++) {
                cd x = a[l + j];
                cd y = a[l + j + len / 2] * w;
                a[l + j] = x + y;
                a[l + j + len / 2] = x - y;
                w *= wlen;
            }
        }
    }
    if (inv) {
        for (auto &x : a) {
            x /= n;
        }
    }
}
template <class T = ld>
vector<T> mul(const vector<T> &a, const vector<T> &b) {
    // a,b 是实系数序列;返回二者的线性卷积,任一输入为空时返回空.
    if (a.empty() || b.empty()) {
        return {};
    }
    int sz = a.size() + b.size() - 1;
    int n = bit_ceil((unsigned long long)sz);
    vector<cd> x(n), y(n);
    copy(a.begin(), a.end(), x.begin());
    copy(b.begin(), b.end(), y.begin());
    fft(x, false);
    fft(y, false);
    for (int i = 0; i < n; i++) {
        x[i] *= y[i];
    }
    fft(x, true);
    vector<T> c(sz);
    for (int i = 0; i < sz; i++) {
        c[i] = llround(x[i].real());
    }
    return c;
}


inline void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<int> g_diff(n + 1), a(n + 1), ra(n + 1), g(n + 1);
    vector<int> cnt(26);
    for(int i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;
    }
    for(int i = 1; i <= n - 1; i++) {
        g_diff[i] = cnt[s[i] - 'a'];
    }
    for(char c = 'a'; c <= 'z'; c++) {
        for(int i = 1; i <= n; i++) {
            a[i] = s[i] == c;
            ra[n - i + 1] = a[i];
        }
        auto C = mul(a, ra);
        for(int k = 1; k < n; k++) {
            g_diff[k] -= C[n + k + 1];
        }
    }
    g[n] = cnt[s[n] - 'a'];
    for(int k = n - 1; k >= 1; k--) {
        g[k] += g[k + 1] + g_diff[k];
    }
    for(int i = 1; i <= n; i++) {
        cout << g[i] << endl;
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