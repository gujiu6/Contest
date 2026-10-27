#include <bits/stdc++.h>
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
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};




//4.Manacher(zuo神)
class Manacher {
public:
    string ss;//ss[1..m] = #a#b#c#
    vector<int> p;//以 ss[i] 为中心的回文半径
    int n, m;
    Manacher(const string& s) {
        n = s.size() - 1;
        m = 2 * n + 1;
        ss.assign(m + 1, '#');
        p.assign(m + 1, 0);
        // 构造 #a#b#c#
        for (int i = 1, j = 1; i <= m; i++) {
            ss[i] = (i & 1) ? '#' : s[j++];
        }
        //c:当前最右回文的中心;r:当前最右回文的右边界的下一位
        for (int i = 1, c = 1, r = 1, len; i <= m; i++) {
            len = r > i ? min(p[2 * c - i], r - i) : 1;
            while (i - len >= 1 && i + len <= m && ss[i - len] == ss[i + len]) {
                len++;
            }
            if (i + len > r) {
                c = i;
                r = i + len;
            }
            //原串回文长度:p[i]-1
            p[i] = len;
        }
    }
};

inline void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    Manacher mm(s);
    vector<int> nxt(mm.m + 2, mm.m + 1);
    vector<int> last(26, mm.m + 1);
    for(int i = mm.m; i >= 1; i--) {
        if(mm.ss[i] == '#') {
            nxt[i] = nxt[i + 1];
            continue;
        }
        int c = mm.ss[i] - 'a';
        int mn1 = mm.m + 1;
        int mn2 = mm.m + 1;
        for(int j = 0; j < 26; j++) {
            if(j == c) continue;
            if(last[j] < mn1) {
                mn2 = mn1;
                mn1 = last[j];
            }
            else if(last[j] < mn2) {
                mn2 = last[j];
            }
        }
        nxt[i] = mn2;
        last[c] = i;
    }
    auto pd = [&](int l, int r) {
        return nxt[l] > r;
    };
    i64 ans = 0;
    for(int i = 1; i <= mm.m; i++) {
        int len = mm.p[i] - 1;
        int l = 0, r = len, tmp = 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(pd(i - mid , i + mid)) {
                tmp = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // dbg(i)dbg(len)dbg(tmp)
        ans += (tmp + 1) / 2;
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