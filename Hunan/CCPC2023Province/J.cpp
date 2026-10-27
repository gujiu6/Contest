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
constexpr ld eps = 1e-6;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve() {
    int n; cin >> n;
    vector<string> s(n + 1);
    rep(i, 1, n) cin >> s[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int ii = 0; ii < s[i].size(); ii++) {
                int res = 0;
                for(int jj = 0; jj < s[j].size(); jj++) {
                    for(int l = 0; ii + l < s[i].size() and jj + l < s[j].size(); l++) {
                        if(s[i][ii + l] != s[j][jj + l]) break;
                        ans = max(ans, l + 1);
                    }
                }
                
            }
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