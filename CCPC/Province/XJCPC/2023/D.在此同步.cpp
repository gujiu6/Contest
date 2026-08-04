#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
#define int long long
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
constexpr ll INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) {
        cin >> a[i];
    }
    int c = 0, m = (1 + (n - 1)) * (n - 1) / 2;
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            c += (a[j] > a[i]);
        }
    }
    if(c == 0 || c == m) {
        cout << -1 << endl;
        return;
    }
    int cc = c;
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    for(int i = 1; i <= n && c; i++) {
        int x = min(c, n - i);
        if(x > 0) {
            int v = ans[i + x];
            for(int j = i + x; j > i; j--) {
                ans[j] = ans[j - 1];
            }
            ans[i] = v;
            c -= x;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] != a[i]) {
            for(int j = 1; j <= n; j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    iota(ans.begin(), ans.end(), 0);
    for(int i = n; i >= 1 && cc; i--) {
        int x = min(cc, i - 1);
        if(x > 0) {
            int v = ans[i - x];
            for(int j = i - x; j < i; j++) {
                ans[j] = ans[j + 1];
            }
            ans[i] = v;
            cc -= x;
        }
    }
    for(int j = 1; j <= n; j++) {
        cout << ans[j] << " ";
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