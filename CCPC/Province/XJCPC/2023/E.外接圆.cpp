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


struct P{
    i64 x, y;
};

i64 det3(
        i64 a, i64 b, i64 c, 
        i64 d, i64 e, i64 f,
        i64 g, i64 h, i64 i) {
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

bool pd(P a, P b, P c, P d) {
    i64 m[4][4];
    P p[4] = {a, b, c, d};
    for(int i = 0; i < 4; i++) {
        m[i][0] = p[i].x;
        m[i][1] = p[i].y;
        m[i][2] = p[i].x * p[i].x + p[i].y * p[i].y;
        m[i][3] = 1;
    }
    i64 ans = 0;
    for(int i = 0; i < 4; i++) {
        i64 mm[3][3];
        int r = 0;
        for(int j = 1; j < 4; j++) {
            int c = 0;
            for(int k = 0; k < 4; k++) {
                if(k == i) continue;
                mm[r][c++] = m[j][k];
            }
            r++;
        }
        i64 cur = det3(mm[0][0], mm[0][1], mm[0][2], mm[1][0], mm[1][1], mm[1][2], mm[2][0], mm[2][1], mm[2][2]);
        if(i & 1) ans += -m[0][i] * cur;
        else ans += m[0][i] * cur;
    }
    return ans == 0;
}
bool line(P a, P b, P c)
{
    return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}

inline void solve() {
    int n; cin >> n;
    vector<P> a(n + 1);
    map<pair<i64, i64>, int> count;
    rep(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        count[{a[i].x, a[i].y}]++;
    }
    vector<int> cc;
    for(auto [f, c] : count) {
        cc.push_back(c);
    }
    int cnt = 0;
    if(cc.size() == 1) {
        cnt = n;
    }
    else {
        for(int i = 0; i < count.size(); i++) {
            for(int j = i + 1; j < count.size(); j++) {
                cnt = max(cnt, cc[i] + cc[j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(line(a[i], a[j], a[k])) continue;
                int cur = 0;
                for(int x = 1; x <= n; x++) {
                    if(pd(a[i], a[j], a[k], a[x]))
                        cur++;
                }
                cnt = max(cnt, cur);
            }
        }
    }
    cout << n - cnt << endl;
    
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