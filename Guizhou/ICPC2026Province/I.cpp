#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
// #define int long long
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
constexpr i64 INF = 1e9;
constexpr int MOD = 998244353;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};



int f[MAXX];
void init() {
    f[0] = 1;
    for(int i = 1; i < MAXX; i++) {
        f[i] = 1LL * f[i - 1] * i % MOD;
    }
}


inline void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a; b = ' ' + b;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF)), cnt(n + 1, vector<int>(m + 1));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
        cnt[i][0] = 1;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
        cnt[0][j] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i - 1][j - 1] + (a[i] != b[j]) <= dp[i][j]) {
                if(dp[i - 1][j - 1] + (a[i] != b[j]) == dp[i][j]) {
                    cnt[i][j] = ((i64)cnt[i][j] + cnt[i - 1][j - 1]) % MOD;
                }
                else {
                    cnt[i][j] = cnt[i - 1][j - 1];
                }
                dp[i][j] = dp[i - 1][j - 1] + (a[i] != b[j]);
            }

            if(dp[i - 1][j] + 1 <= dp[i][j]) {
                if(dp[i - 1][j] + 1 == dp[i][j]) {
                    cnt[i][j] = ((i64)cnt[i][j] + cnt[i - 1][j]) % MOD;
                }
                else {
                    cnt[i][j] = cnt[i - 1][j];
                }
                dp[i][j] = dp[i - 1][j] + 1;
            }

            if(dp[i][j - 1] + 1 <= dp[i][j]) {
                if(dp[i][j - 1] + 1 == dp[i][j]) {
                    cnt[i][j] = ((i64)cnt[i][j] + cnt[i][j - 1]) % MOD;
                }
                else {
                    cnt[i][j] = cnt[i][j - 1];
                }
                dp[i][j] = dp[i][j - 1] + 1;
            }
        }
    }
    cout << 1LL * f[dp[n][m]] * cnt[n][m] % MOD << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
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