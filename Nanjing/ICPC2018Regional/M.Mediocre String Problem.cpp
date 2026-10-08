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


vector<int> manacher(const string& s) {
    int n = s.size() - 1;
    int m = n * 2 + 1;
    string ss(m + 1, '#');
    vector<int> p(m + 1);
    for(int i = 1, j = 1; i <= m; i++) {
        ss[i] = i & 1 ? '#' : s[j++];
    }
    for(int i = 1, c = 1, r = 1, len; i <= m; i++) {
        len = r > i ? min(p[2 * c - i], r - i) : 1;
        while(i - len >= 1 && i + len <= m && ss[i - len] == ss[i + len]) {
            len++;
        }
        if(i + len > r) {
            c = i;
            r = i + len;
        }
        p[i] = len;
    }
    vector<int> start(n + 1);
    vector<int> d(n + 3);
    for(int i = 1; i <= m; i++) {
        int l = (i - p[i] + 1) / 2 + 1;
        int r = i / 2;
        if(l <= r) {
            d[l]++;
            d[r + 1]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        start[i] = start[i - 1] + d[i];
    }
    return start;
}
vector<int> Zfunc(const string& s) {
    int n = s.size() - 1;
    vector<int> z(n + 1);
    z[1] = n;
    for(int i = 2, l = 1, r = 1, len; i <= n; i++) {
        len = r >= i ? min(r - i + 1, z[i - l + 1]) : 0;
        while(i + len <= n && s[i + len] == s[1 + len])
            len++;
        if(i + len - 1 > r) {
            l = i;
            r = i + len - 1;
        }
        z[i] = len;
    }
    return z;
}


inline void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    auto rs = s;
    s = ' ' + s, t = ' ' + t;
    auto start = manacher(s);
    reverse(all(rs, 0));
    auto x = t + '#' + rs;
    auto z = Zfunc(x);
    int ans = 0;
    for(int p = 2; p <= n; p++) {
        ans += start[p] * z[m + n - p + 3];
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