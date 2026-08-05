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




//001 -> 100
//110 -> 011

inline void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> idx0_a, idx1_a, idx0_b, idx1_b;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') {
            if(i % 2) {
                idx1_a.push_back(i);
            }
            else {
                idx0_a.push_back(i);
            }
        }
        if(b[i] == '1') {
            if(i % 2) {
                idx1_b.push_back(i);
            }
            else {
                idx0_b.push_back(i);
            }
        }
    }
    if(idx0_a.size() != idx0_b.size() || idx1_a.size() != idx1_b.size()) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for(int i = 0; i < idx0_a.size(); i++) {
        ans += abs(idx0_a[i] / 2 - idx0_b[i] / 2);
    }
    for(int i = 0; i < idx1_a.size(); i++) {
        ans += abs(idx1_a[i] / 2 - idx1_b[i] / 2);
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