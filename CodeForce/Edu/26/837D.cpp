#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


int calc(ll x, int y) {
    int ans = 0;
    while(x % y == 0) {
        x /= y;
        ans++;
    }
    return ans;
}



inline void solve() {
    int n, k; cin >> n >> k;
    vector<pii> a(n + 1);
    int sum2 = 0;
    rep(i, 1, n) {
        ll x; cin >> x;
        a[i] = {calc(x, 2), calc(x, 5)};
        sum2 += a[i][0];
    }
    vector<vector<int>> dp(k + 1, vector<int>(sum2 + 1,(int)-1e9));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = k; j >= 1; j--) {
            for(int s = sum2; s >= a[i][0]; s--) {
                if(dp[j - 1][s - a[i][0]] == (int)-1e9) continue;
                dp[j][s] = max(dp[j][s], dp[j - 1][s - a[i][0]] + a[i][1]);
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= k; j++) {
        for(int s = sum2; s >= 0; s--) {
            ans = max(ans, min(s, dp[j][s]));
        }
    }
    cout << ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
    
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