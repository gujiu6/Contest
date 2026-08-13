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



void solve2() {
    int n, k, m; cin >> n >> k >> m;
    vector<int> ans(n);
    vector<vector<int>> s(k + 1);
    rep(i, 0, n - 1) {
        int x; cin >> x;
        s[x].push_back(i);
    }
    int rem = m % n;
    m /= n;
    for(int i = 1; i <= k; i++) {
        if(s[i].size() % 2 == 0) {
            for(int j = 0; j < s[i].size(); j++) {
                int id = s[i][j];
                if(j & 1) {
                    ans[id] += m;
                    if(id < rem) ans[id]++;
                }
            }
        }
        else {
            if(m % 2 == 0) {
                for(int j = 0; j < s[i].size(); j++) {
                    int id = s[i][j];
                    ans[id] += m / 2;
                    if(j & 1 && id < rem) ans[id]++;
                }
            }
            else {
                for(int j = 0; j < s[i].size(); j++) {
                    int id = s[i][j];
                    if(j & 1) {
                        ans[id] += m / 2 + 1;
                    }
                    else {
                        ans[id] += m / 2;
                        if(id < rem) ans[id]++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}




inline void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<int> a(n), c(k + 1), ans(n);
    rep(i, 0, n - 1) cin >> a[i];
    for(int i = 0; i < m; i++) {
        int x = a[i % n];
        if(c[x]) {
            c[x] = 0;
            ans[i % n]++;
        }
        else {
            c[x]++;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
    
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
    
        solve2();
    
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