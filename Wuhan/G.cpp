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
constexpr ld eps = 1e-12;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve() {
    int n, k; cin >> n >> k;
    int sum = 0;
    vector<int> cnt(n + 1);
    rep(i, 1, n) cin >> cnt[i];
    sort(all(cnt, 1), greater<int>());
    auto check = [&](int mid)->int {
        if(mid <= n) {
            for(int i = 1; i <= mid; i++) {
                if(cnt[i] <= 0) return false;
            }
            return true;
        }
        int m = 1 + (mid - n) / (n - 1), r = (mid - n) % (n - 1);
        int kk1 = k, kk2 = m - 1, limit = (m - 1 + 2 - 1) / 2;
        for(int i = 1; i <= n; i++) {
            int x = cnt[i];
            if(i <= r) {
                x -= (m + 1);
            }
            else {
                x -= m;
            }
            if(x < 0 and kk2 > 0) {
                if(min(kk2, limit) + x >= 0) {
                    kk2 += x;
                    x = 0;
                }
                else {
                    x += min(kk2, limit);
                    kk2 -= min(kk2, limit);
                }
            }
            kk1 += min(0LL, x);
            if(kk1 < 0) return false;
        }
        return kk1 >= 0;
    };
    int l = 0, r = INF, ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            // dbg(mid)
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
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