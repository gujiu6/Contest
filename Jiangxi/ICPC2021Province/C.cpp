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






inline void solve() {
    int n; cin >> n;
    vector<pii> a(n + 1);
    a[0][0] = a[0][1] = 0;
    rep(i, 1, n) cin >> a[i][0] >> a[i][1];
    vector<vector<i64>> dp(n + 2, vector<i64>(n + 2, -INF));//到i行选了j个l
    dp[n + 1][0] = 0;
    for(int i = n; i >= 1; i--) {
        auto [l, r] = a[i];
        for(int j = 0; j <= n - i + 1; j++) {
            //选r
            if(dp[i + 1][j] != -INF) {
                int cc = 2 * i + 2 * j - n - 1;
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + cc * r);
            }
            //选l
            if(j >= 1 && dp[i + 1][j - 1] != INF) {
                int cc = 2 * j - n - 1;
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + cc * l);
            }
        }
    }
    i64 sum = n * (n - 1) * (n + 1) / 6;
    i64 ans = -INF;
    for(int j = 0; j <= n; j++) {
        ans = max(ans, dp[1][j]);
    }
    cout << ans + sum << endl;
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