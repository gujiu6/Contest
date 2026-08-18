#include <bits/stdc++.h>
#include <cassert>
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
using i128 = __int128_t;
using ld = long double;
using ui64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 998244353;
constexpr int MAXX = 1e6+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};

//矩阵快速幂
vector<vector<i64>> mul(const vector<vector<i64>>& a,const vector<vector<i64>>& b) {
    //a : n * k, b : n * m
    int n = a.size();
    int k = a[0].size();
    int m = b[0].size();
    vector<vector<i64>> ans(n, vector<i64>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int c = 0; c < k; c++){
                ans[i][j] = (ans[i][j] + 1LL * a[i][c] * b[c][j]) % MOD;
            }
        }
    }
    return ans;
}
vector<vector<i64>> power(vector<vector<i64>> A,int p,const vector<vector<i64>>& f) {
    //f : 初始矩阵
    vector<vector<i64>>ans = f;
    while(p > 0) {
        if(p & 1) ans = mul(A, ans);
        A = mul(A, A);
        p >>= 1;
    }
    return ans;
}


vector<int> prefix(const string& s) {
    int n = s.size() - 1;
    vector<int> p(n + 1);
    for(int i = 2; i <= n; i++) {
        int j = p[i - 1];
        while(j && s[i] != s[j + 1]) {
            j = p[j];
        }
        if(s[i] == s[j + 1]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

int pow_10[MAXX];
int go[7][10];
void init(int n) {
    pow_10[0] = 1;
    for(int i = 1; i <= n; i++) {
        pow_10[i] = 10LL * pow_10[i - 1] % MOD;
    }
}
bool pd(int n, int x) {
    int c = 0;
    while(x > 1 && x % 10 == 0) {
        x /= 10;
        c++;
    }
    return x == 1 && c <= n;
}
inline void solve() {
    int n; string s; cin >> n >> s; 
    int m = s.size();
    int x = stoi(s);
    s = " " + s;
    auto nxt = prefix(s);
    memset(go, -1, sizeof go);
    for(int j = 0; j < m; j++) {
        for(int d = 0; d <= 9; d++) {
            char c = '0' + d;
            int nj = j;
            while(nj && s[nj + 1] != c) {
                nj = nxt[nj];
            }
            if(s[nj + 1] == c) nj++;
            go[j][d] = nj;
        }
    }
    // vector<vector<int>> dp(11, vector<int>(7));
    // dp[0][0] = 1;
    // i64 ans = 0;
    // for(int pos = 1; pos <= n; pos++) {
    //     vector<vector<int>> ndp(11, vector<int>(7));
    //     for(int rem = 0; rem < 11; rem++) {
    //         for(int j = 0; j < m; j++) {
    //             if(dp[rem][j] == 0) continue;
    //             for(int d = 0; d <= 9; d++) {
    //                 int nrem = (rem * 10 + d) % 11;
    //                 int nj = go[j][d];
    //                 if(nj == m) {
    //                     ans = (ans + 1LL * dp[rem][j] * pow_10[n - pos] % MOD) % MOD;
    //                 }        
    //                 else {
    //                     ndp[nrem][nj] = (ndp[nrem][nj] + dp[rem][j]) % MOD;
    //                 }
    //             }
    //         }
    //     }
    //     dp = move(ndp);
    // }
    // for(int j = 0; j < m; j++) {
    //     ans = (ans + dp[0][j]) % MOD;
    // }
    // if(pd(n, x)) ans++;
    // cout << ans << endl;
    int sz = 11 * m + 11;
    auto idx0 = [&](int rem, int j)->int {
        return rem * m + j;
    };
    auto idx1 = [&](int rem) {
        return 11 * m + rem;
    };
    vector<vector<i64>> A(sz, vector<i64>(sz, 0));
    for(int rem = 0; rem < 11; rem++) {
        for(int j = 0; j < m; j++) {
            int from = idx0(rem, j);
            for(int d = 0; d <= 9; d++) {
                int nrem = (rem * 10 + d) % 11;
                int nj = go[j][d];
                //匹配到s?
                int to = (nj == m) ? idx1(nrem) : idx0(nrem, nj);
                A[to][from]++;
                dbg(to)dbg(from)
            }
        }
        //匹配到s
        int from = idx1(rem);
        for(int d = 0; d <= 9; d++) {
            int nrem = (rem * 10 + d) % 11;
            int to = idx1(nrem);
            A[to][from]++;
        }
    }
    vector<vector<i64>> f(sz, vector<i64>(1));
    f[idx0(0, 0)][0] = 1;
    auto res = power(A, n, f);
    i64 ans = 0;
    //s
    for(int rem = 0; rem < 11; rem++) {
        ans = (ans + res[idx1(rem)][0]) % MOD;
    }
    //% 11 == 0
    for(int j = 0; j < m; j++) {
        ans = (ans + res[idx0(0, j)][0]) % MOD;
    }
    if(pd(n, x)) ans++;
    cout << ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    init(MAXX - 1);
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