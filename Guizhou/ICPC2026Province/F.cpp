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
constexpr int MAXX = 2e6+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};

i64 pow(i64 a, i64 b, i64 mod = MOD) {
	i64 ans = 1 % mod;
    a = (a % mod + mod) % mod;
	while(b > 0) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int base = 911382323, p1 = 1000000007, p2 = 1000000009;
int inv1 = 0, inv2 = 0;
vector<int> pw1(MAXX + 1), pw2(MAXX + 1);
void init() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i <= MAXX; i++) {
        pw1[i] = pw1[i - 1] * base % p1;
        pw2[i] = pw2[i - 1] * base % p2;
    }
    inv1 = pow(base, p1 - 2, p1);
    inv2 = pow(base, p2 - 2, p2);
}

inline void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    a = " " + a;
    string bb = " " + b + b;
    map<pii, int> mp;
    int h1 = 0, h2 = 0, ans = 0;
    for(int l = 1, r = 1; r <= 2 * n - 1; r++) {
        int cur1 = bb[r] * pw1[r - l + 1] % p1;
        int cur2 = bb[r] * pw2[r - l + 1] % p2;
        h1 = (h1 + cur1) % p1;
        h2 = (h2 + cur2) % p2;
        while(r - l + 1 > n) {
            int pre1 = bb[l] * pw1[1] % p1;
            int pre2 = bb[l] * pw2[1] % p2;
            h1 = ((h1 - pre1) % p1 + p1) % p1;
            h2 = ((h2 - pre2) % p2 + p2) % p2;
            h1 = h1 * inv1 % p1;
            h2 = h2 * inv2 % p2;
            l++;
        }
        if(r - l + 1 == n) {
            mp[{h1, h2}]++;
        }
    }
    h1 = 0, h2 = 0;
    for(int i = 1; i <= n; i++) {
        h1 = (h1 + a[i] * pw1[i]) % p1;
        h2 = (h2 + a[i] * pw2[i]) % p2;
    }
    for(int i = 1, j = 1; i <= n; i++) {
        while(j - i + 1 <= k) {
            int id = (j - 1) % n + 1;
            h1 = ((h1 - a[id] * pw1[id]) % p1 + p1) % p1;
            h2 = ((h2 - a[id] * pw2[id]) % p2 + p2) % p2;
            a[id] = '0' + (!(a[id] - '0'));
            h1 = (h1 + a[id] * pw1[id]) % p1;
            h2 = (h2 + a[id] * pw2[id]) % p2;
            j++;
        }
        ans += mp[{h1, h2}];
        h1 = ((h1 - a[i] * pw1[i]) % p1 + p1) % p1;
        h2 = ((h2 - a[i] * pw2[i]) % p2 + p2) % p2;
        a[i] = '0' + (!(a[i] - '0'));
        h1 = (h1 + a[i] * pw1[i]) % p1;
        h2 = (h2 + a[i] * pw2[i]) % p2;
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
    cin >> t;
    init();
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