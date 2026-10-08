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
    vector<int> cnt(4);
    vector<vector<int>> precnt(n + 1, vector<int>(4));
    rep(i, 1, n) {
        int x; cin >> x;
        cnt[x]++;
        precnt[i] = {cnt[0], cnt[1], cnt[2], cnt[3]};
    }
    int m; cin >> m;
    vector<i64> h(m + 1);
    int sum = 0;
    rep(i, 1, m) {
        cin >> h[i];
        sum += h[i];
    }
    auto check = [&](int k)->bool {
        int r = k / n, rem = k % n;
        vector<int> c(4);
        for(int i = 1; i <= 3; i++) {
            c[i] += r * cnt[i] + precnt[rem][i];
        }
        if(c[1] + c[2] * 2 + c[3] * 3 < sum) return false;
        auto hh = h;
        for(int i = 1; c[3] && i <= m; i++) {
            if(hh[i] >= 3 && hh[i] % 2) {
                hh[i] -= 3;
                c[3]--;
            }
        }
        for(int i = 1; c[3] && i <= m; i++) {
            if(hh[i] >= 6) {
                int t = min(hh[i] / 6, c[3] / 2);
                hh[i] -= 6 * t;
                c[3] -= 2 * t;
            }
        }
        sort(all(hh, 1), greater());
        for(int i = 1; c[3] && i <= m; i++) {
            if(hh[i]) {
                c[3]--;
                hh[i] = max(0LL, hh[i] - 3);
            }
        }
        for(int i = 1; c[3] && i <= m; i++) {
            if(hh[i] == 2) {
                hh[i] = 0;
                c[3]--;
            }
        }
        for(int i = 1; c[3] && i <= m; i++) {
            if(hh[i]) {
                hh[i] = 0;
                c[3]--;
            }
        }
        for(int i = 1; c[2] && i <= m; i++) {
            if(hh[i] >= 2) {
                int t = min(hh[i] / 2, c[2]);
                c[2] -= t;
                hh[i] -= 2 * t;
            }
        }
        for(int i = 1; c[2] && i <= m; i++) {
            if(hh[i]) {
                c[2]--;
                hh[i] = max(0LL, hh[i] - 2);
            }
        }
        int cc = 0;
        for(int i = 1; i <= m; i++) cc += hh[i];
        return c[1] >= cc;
    };
    int l = 0, r = 1e15, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
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