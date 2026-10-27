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
constexpr int MAXX = 4e7+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acosl(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};



//4.Manacher(zuo神)
class Manacher {
public:
    string s;
    string ss;//ss[1..m] = #a#b#c#
    vector<int> p;//以 ss[i] 为中心的回文半径
    int n, m;
    Manacher(const string& s) : s(s) {
        n = s.size() - 1;
        m = 2 * n + 1;
        ss.assign(m + 1, '#');
        p.assign(m + 1, 0);
        // 构造 #a#b#c#
        for (int i = 1, j = 1; i <= m; i++) {
            ss[i] = (i & 1) ? '#' : s[j++];
        }
        //c:当前最右回文的中心;r:当前最右回文的右边界的下一位
        
    }
};


vector<int> pre(MAXX), a(MAXX), Len(MAXX);

inline void solve() {
    int n; cin >> n;
    for(int i = 1; i <= 4 * n; i++) {
        pre[i] = a[i] = Len[i] = 0;
    }
    string s; cin >> s;
    string ss = " ";
    for(const auto &c : s) {
        if(c == 'w') {
            a[ss.size() * 2] = 1;
            ss.push_back('v');
            a[ss.size() * 2] = 1;
            Len[ss.size() * 2] = 1;
            ss.push_back('v');
        }
        else {
            Len[ss.size() * 2] = 1;
            ss.push_back(c);
        }
    }
    Manacher mm(ss);
    for(int i = 1; i <= mm.m; i++) {
        pre[i] = pre[i - 1] ^ a[i];
        Len[i] += Len[i - 1];
    }
    int L = 2, R = 2, res = 1;
    for (int i = 1, c = 1, r = 1, len; i <= mm.m; i++) {
        len = r > i ? min(mm.p[2 * c - i], r - i) : 1;
        auto check = [&](int d) {
            d--;
            if(mm.ss[i + d] == '#') d--;
            if(pre[i + d] ^ pre[i - d - 1] == 0) {
                int cur = Len[i + d] - Len[i - d - 1];
                if(cur > res) {
                    res = cur;
                    L = i - d;
                    R = i + d;
                }
            }
        };
        check(len);
        while (i - len >= 1 && i + len <= mm.m && mm.ss[i - len] == mm.ss[i + len]) {
            len++;
            check(len);
        }
        check(len);
        if (i + len > r) {
            c = i;
            r = i + len;
        }
        //原串回文长度:p[i]-1
        mm.p[i] = len;
    }
    string ans;
    while(L <= R) {
        if(a[L]) {
            ans += 'w';
            L += 4;
        }
        else {
            ans += mm.ss[L];
            L += 2;
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