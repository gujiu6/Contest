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


//快速幂
i64 power(i64 a, i64 b, i64 MOD = 1e9+7) {
	i64 ans = 1;
	a %= MOD;
	while(b > 0) {
		if(b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}
//费马小
i64 getinv(int n, int MOD = 1e9+7){
    return power(n, MOD - 2, MOD);
}
int inv = getinv(2, MOD);
int calc(int len, int l, int r) {
    if(len <= l) return 0;
    int k = min(r - l, len - l) % MOD;
    int h = (1 + k) * k % MOD * inv % MOD;
    if(len > r) {
        int rem = (len - r) % MOD;
        h = (h + (rem * ((r - l) % MOD))) % MOD;
    }
    return h;
}
int a, b, x_1, x_2, y_1, y_2;
inline void solve() {
    int sum1 = 1LL * a * b % MOD * (x_2 - x_1) % MOD * (y_2 - y_1) % MOD;
    int sum2 = 1LL * (1 + a) * a % MOD * inv % MOD * (1 + b) % MOD * b % MOD * inv % MOD;
    int w = calc(a, x_1, x_2) * calc(b, y_1, y_2) % MOD;
    cout << ((((sum1 + sum2) % MOD) - w) % MOD + MOD) % MOD << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; cin >> a >> b >> x_1 >> x_2 >> y_1 >> y_2; i++){
    
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