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
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n, m, t; cin >> n >> m >> t;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> nxt(n + 1);
    vector<int> inDeg(n + 1);
    rep(i, 1, m) {
        int b, c; cin >> b >> c;
        nxt[c] = b;
        inDeg[b]++;
    }
    vector<int> new_weights;
    int t0 = 0, vis = 0;
    rep(i, 1, n) {
        if(inDeg[i] == 0) {
            vector<int> path;
            int cur = i;
            while(cur != 0) {
                path.push_back(cur);
                vis++;
                cur = nxt[cur];
            }
            int k = path.size();
            for(int j = 0; j < k; j++) {
                t0 += j * a[path[j]];
            }
            int suf = 0;
            for(int j = k - 1; j >= 0; j--) {
                suf += a[path[j]];
                new_weights.push_back(suf);
            }
        }
    }
    if(vis < n || t0 > t) {
        cout << 0 << endl;
        return ;
    }
    int target = t - t0;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int w : new_weights) {
        for(int v = w; v <= target; v++) {
            dp[v] = (dp[v] + dp[v - w]) % MOD;
        }
    }
    cout << dp[target] << endl;
    
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    //cin>>t;
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