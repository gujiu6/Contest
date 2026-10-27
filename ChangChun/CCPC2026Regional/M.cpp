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
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 1e6+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


vector<int> prime, minp;
void Prime_Euler(int n){
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i++){
        if(!minp[i]) {
            minp[i] = i;
            prime.emplace_back(i);
        }
        for(int j = 0;j < prime.size() && i * prime[j] <= n; j++){
            minp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}


inline void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> dp(MAXX + 1, -1);
    dp[0] = dp[1] = 0;
    i64 ans = 0;
    auto calc = [&](int x) {
        int xx = x, res = 1;
        if(dp[x] != -1) return dp[x];
        while(xx > 1) {
            int p = minp[xx], c = 0;
            while(xx % p == 0) {
                c++;
                xx /= p;
            }
            res *= c + 1;
        }
        return dp[x] = res - 1;
    };
    for(int i = 1; i <= n; i++) {
        auto fun = [&](int l, int r) {
            int g = 0;
            while(l >= 1 and r <= n) {
                int x = abs(a[l] - a[r]);
                g = gcd(g, x);
                int cur = 0;
                if(g == 0) {
                    cur = m - 1;
                }
                else {
                    // dbg(g)
                    cur = calc(g);
                }
                ans += cur;
                // if(cur == 0) break;
                l--, r++;
            }
            
        };
        fun(i, i + 1);
        fun(i, i + 2);
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
    Prime_Euler(MAXX);
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