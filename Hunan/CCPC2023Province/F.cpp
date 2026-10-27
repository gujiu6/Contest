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






inline void solve() {
    int a, b, p, q; cin >> a >> b >> p >> q;
    ld P = (ld)p / 100.0, Q = (ld)q / 100.0;
    if (b == 1) Q = 100 / (100 - q) - 1;
    if (Q >= 1) {
        cout << fixed << setprecision(15) << (Q + 1) * a << endl;
        return;
    }
    ld PP = ld(100 - p) / 100.0, QQ = ld(100 - q) / 100.0;
    vector<vector<ld>> dp(a + 1, vector<ld>(2));
    for(int i = b; i <= a; i++) {
        ld pre1 = max(dp[i - b][0], dp[i - b][1]);
        ld pre2 = max(dp[i - b + 1][0], dp[i - b + 1][1]);
        dp[i][0] = (pre1 + 1) * PP + (pre1 + 2) * P;
        dp[i][1] = (pre1 + 1) * QQ + (pre2 + 1) * Q;
    }
    cout << fixed << setprecision(15) << max(dp[a][0], dp[a][1]) << endl;
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