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
const int INF=1e9+7;
const int MOD=998244353;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


ll power(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
array<int, 105> inv;
void init() {
    for(int i = 1; i <= 100; i++) {
        inv[i] = power(i, MOD - 2, MOD);
    }
}

inline void solve() {
    int n; cin >> n;
    vector<ll> dp(105, 1);
    dp[0] = 0;
    auto fun = [&](int l) {
        vector<ll> f(105);
        f[0] = 1;
        for(int i = 1; i <= 100; i++) {
            f[i] = 1LL * f[i - 1] * (l + i - 1) % MOD * inv[i] % MOD;
        }
        return f;
    };
    for(int i = 1; i <= n; i++) {
        int l, h, op; cin >> l >> h >> op;
        auto f = fun(l);
        vector<ll> nxt_dp(105);
        if(op == 1) {
            for(int i = 1; i <= h; i++) {
                for(int j = 1; j <= i; j++) {
                    int d = i - j;
                    nxt_dp[i] = (nxt_dp[i] + dp[j] * f[d]) % MOD;
                }
            }
        }
        else {
            for(int i = 1; i <= h; i++) {
                for(int j = i; j <= h; j++) {
                    int d = j - i;
                    nxt_dp[i] = (nxt_dp[i] + dp[j] * f[d]) % MOD;
                }
            }
        }
        dp = nxt_dp;
    }
    ll ans = 0;
    for(int i = 1; i <= 100; i++) 
        ans = (ans + dp[i]) % MOD;
    cout << ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    init();
    cin>>t;
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