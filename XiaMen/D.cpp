#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
// #define ONLINE_JUDGE
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
constexpr int MOD = 998244353;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-12;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


struct BIT {
    int n = 0;
    vector<int> bit, a;
    BIT(int n = 0): n(n), bit(n + 1), a(n + 1) {}
    void add(int p, int v) {
        while(p <= n) {
            bit[p] += v;
            bit[p] %= MOD;
            p += p &  -p;
        }
    }
    void set(int p, int v) {
        add(p, v - a[p]);
        a[p] = v;
    }
    int sum(int p) {
        int ans = 0;
        while(p > 0) {
            ans += bit[p];
            ans %= MOD;
            p -= p & -p;
        }
        return ans;
    }
};

inline void solve() {
    int n, m; cin >> n >> m;
    map<int, pii> mp1, mp2;
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        mp1[x] = {y, i};
    }
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        mp2[x] = {y, i};
    }
    vector<pii> a;
    for(const auto &[x, y] : mp1) {
        if(mp2.find(x) == mp2.end() or mp2[x][0] == y[0]) continue;
        a.push_back({y[1], mp2[x][1]});
    }
    if(a.size() <= 1) {
        if(a.size() == 0) cout << 1 << endl;
        else cout << 2 << endl;
        return;
    }
    sort(all(a, 0), [&](const auto &x, const auto &y) {
        return x[0] < y[0];
    });
    BIT bit(m + 1);
    vector<int> dp(m + 1);
    dp[0] = 1;
    bit.set(1, dp[0]);
    for(int i = 0; i < a.size(); i++) {
        auto &[_, id] = a[i];
        dp[id] += bit.sum(id);
        bit.set(id + 1, dp[id]);
    }
    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans += dp[i];
        ans %= MOD;
    } 
    cout << ans << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
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