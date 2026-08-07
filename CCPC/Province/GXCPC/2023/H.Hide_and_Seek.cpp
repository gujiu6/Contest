#include <bits/stdc++.h>
#include <cassert>
//#include <bit>
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
using i64 = long long;
using i128 = __int128_t;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};




inline void solve() {
    int m, r; cin >> m >> r;
    int l = 1;
    int g = 0;
    vector<pii> p;
    rep(i, 1, m) {
        int b, c; cin >> b >> c;
        if(b == c) {
            l = max(l, b + 1);
        }
        else {
            p.push_back({b, c});
        }
        g = gcd(g, b - c);
    }
    if(l > r) {
        cout << 0 << endl;
        return;
    }
    if(g == 0) {
        cout << r - l + 1 << endl;
        return;
    }
    int ans = 0;
    for(int i = 1; i * i <= g; i++) {
        if(g % i == 0) {
            int j = g / i;
            bool f1 = 0, f2 = 0;
            for(auto [b, c] : p) {
                if(b % i != c) {
                    f1 = 1;
                }
                if(b % j != c) {
                    f2 = 1;
                }
                if(f1 && f2) {
                    break;
                }
            }
            if(!f1 && i >= l && i <= r) ans++;
            if(!f2 && j != i && j >= l && j <= r) ans++;
            // dbg(i)dbg(f1)dbg(f2)
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