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
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};






inline void solve1() {
    int n; cin >> n;
    int ans = 0;
    vector<int> s;
    for(int i = 1; i * i <= n; i++) {
        if(n % i) continue;
        s.push_back(i);
        if(n / i != i) s.push_back(n / i);
    }
    sort(all(s, 0));
    set<pii> ss;
    s.erase(unique(all(s, 0)), s.end());
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            if(n % (s[i] * s[j]) == 0) {
                int g = gcd(s[i], s[j]);
                ss.insert({s[i] / g, s[j] / g});
            }
        }
    }
    for(auto [p, q] : ss) {
        cout << p << " " << q << endl;
    }
    cout << ss.size() << endl;
}
inline void solve() {
    int n; cin >> n;
    int ans = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i) continue;
        int c = 0;
        while(n % i == 0) {
            n /= i;
            c++;
        }
        ans *= 2 * c + 1;
    }
    if(n > 1) {
        ans *= 3;
    }
    cout << (ans + 1) / 2 << endl;
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
        // dbg(i)
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