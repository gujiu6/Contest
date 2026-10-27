#include <bits/stdc++.h>
#include <cassert>
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
constexpr int MAXX = (1LL << 20) + 100, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};



inline void solve() {
    int n, k; cin >> n >> k;
    int m = 1LL << n;
    vector<int> a(m + 1);
    rep(i, 1, m) {
        cin >> a[i];
    }
    vector<int> ans(m + 1), rk(m + 1), cur(m + 1), nxt(m + 1);
    vector<bool> vis(m + 1);
    iota(cur.begin(), cur.end(), 0);
    for(int len = 2; len <= m; len <<= 1) {
        int half = len >> 1;
        for(int base = 1; base <= m; base += len) {
            int st1 = base, end1 = st1 + half - 1;
            int st2 = end1 + 1, end2 = st2 + half - 1;
            int i = st1, j = st2, k = base;
            // dbg(st1)dbg(end1)dbg(st2)dbg(end2)
            while(i <= end1 and j <= end2) {
                if(a[cur[i]] <= a[cur[j]]) {
                    nxt[k++] = cur[i++];
                }
                else {
                    nxt[k++] = cur[j++];
                }
            }
            while(i <= end1) {
                nxt[k++] = cur[i++];
            }
            while(j <= end2) {
                nxt[k++] = cur[j++];
            }
            for(int t = 0; t < len; t++) {
                rk[nxt[base + t]] = t;
            }
        }
        for(int x = 1; x <= m; x++) {
            if(vis[x]) continue;
            int s = rk[x];
            int need = len - s - 1;
            if(need > k or len > a[x]) {
                vis[x] = 1;
            }
            else {
                ans[x]++;
            }
        }
        swap(cur, nxt);
    }
    for(int x = 1; x <= m; x++) {
        cout << ans[x] << " ";
    }
    cout << endl;
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