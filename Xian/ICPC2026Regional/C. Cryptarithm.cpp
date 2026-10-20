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
constexpr i64 INF = 9e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve() {
    int n, m, x, y, z; cin >> n >> m >> x >> y >> z;
    vector<int> a(n + 1), b(m + 1);
    int C = x + n * z;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    vector<int> dp(n + 1, INF), ndp(n + 1, INF), pre(n + 1, INF), suf(n + 2, INF);
    for(int i = 1; i <= n; i++) {
        dp[i] = C + y * abs(a[i] - b[1]);
    }
    for(int j = 2; j <= m; j++) {
        for(int i = 1; i <= n; i++) {
            pre[i] = min(pre[i - 1], dp[i]);
        }
        for(int i = n; i >= 1; i--) {
            suf[i] = min(suf[i + 1], dp[i]);
        }
        for(int i = 1; i <= n; i++) {
            int x1 = pre[i - 1];
            int x2 = (suf[i] == INF ? INF : suf[i] + C);
            ndp[i] = min(x1, x2) + y * abs(a[i] - b[j]);
        }
        dp.swap(ndp);
    }
    cout << ranges::min(dp) - m * z << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
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