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
using i128 = __int128;
using ld = long double;
using u64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 3e6+1000, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};


class Bit {
public:
    int n, tag;
    vector<int> bit, vis;
    Bit(int n): n(n), tag(0), bit(n + 1, -INF), vis(n + 1) {}
    void set(int p, int v) {
        while(p <= n) {
            if(vis[p] != tag) {
                vis[p] = tag;
                bit[p] = -INF;
            }
            bit[p] = max(bit[p], v);
            p += p & -p;
        }
    }
    int qry(int p) {
        int ans = -INF;
        while(p > 0) {
            if(vis[p] == tag) {
                ans = max(ans, bit[p]);
            }
            p -= p & -p;
        }
        return ans;
    }
    void clear() {
        tag++;
    }
};



inline void solve() {
    int n; cin >> n;
    int offest = MAXX;
    vector<int> r(n + 1), y(n + 1), b(n + 1), p_r(n + 1), p_y(n + 1), p_b(n + 1), p1(n + 1), p2(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> r[i] >> y[i] >> b[i];
        p_r[i] = p_r[i - 1] + r[i];
        p_y[i] = p_y[i - 1] + y[i];
        p_b[i] = p_b[i - 1] + b[i];
        p1[i] = p_r[i] - p_y[i];
        p2[i] = p_r[i] - p_b[i];
    }
    vector<int> ord(n + 1), dp(n + 1);
    iota(ord.begin(), ord.end(), 0);
    Bit bit(offest * 3);
    auto cdq = [&](auto &&self, int l, int r) {
        if(l == r) {
            if(l > 0) {
                dp[l] = max(dp[l], dp[l - 1]);
            }
            return;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid);
        vector<int> r_ord(r - mid);
        for(int i = mid + 1; i <= r; i++) {
            r_ord.push_back(ord[i]);
        }
        sort(all(r_ord, 0), [&](int x, int y){
            return p1[x] < p1[y];
        });
        bit.clear();
        int j = l;
        for(int i : r_ord) {
            while(j <= mid && p1[ord[j]] <= p1[i]) {
                bit.set(p2[ord[j]] + offest, dp[ord[j]] - ord[j]);
                j++;
            }
            int cur = bit.qry(p2[i] + offest);
            if(cur > -INF / 2) {
                dp[i] = max(dp[i], cur + i);
            }
        }
        self(self, mid + 1, r);
        sort(ord.begin() + l, ord.begin() + r + 1, [&](int x, int y){
            return p1[x] < p1[y];
        });
    };
    cdq(cdq, 0, n);
    cout << dp[n] << endl;
    
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