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

vector<i64> p(300, 1);
vector<int> prime;
vector<int> min_p;
void Prime(int n) {
    min_p.assign(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(!min_p[i]) {
            min_p[i] = i;
            prime.emplace_back(i);
        }
        for(int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            min_p[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
    for(int i = 1; i < 300; i++) {
        p[i] = p[i - 1] * 2 % MOD;
    }
}
template <class T = int>
struct ModLinearSol {
    vector<T> particular;
    vector<vector<T>> basis;
};
template <class T = int>
optional<ModLinearSol<T>> GaussMod(vector<vector<T>> a, i64 mod) {
    assert(!a.empty() && a[0].size() >= 2);
    int m = a.size(), n = a[0].size() - 1;
    auto norm = [&](T x) {
        return ((x % mod) + mod) % mod;
    };
    auto pow = [&](int a, int b) {
        int ans = 1;
        while(b) {
            if(b & 1) ans = (i128)ans * a % mod;
            a = (i128)a * a % mod;
            b >>= 1;
        }
        return ans;
    };
    for(auto &row : a) {
        assert(row.size() == n + 1);
        for(auto &x : row) {
            x = norm(x);
        }
    }
    vector<int> pivot(n, -1);
    int rk = 0;
    for(int col = 0; col < n && rk < m; col++) {
        int row = rk;
        while(row < m && a[row][col] == 0) {
            row++;
        }
        if(row == m) continue;
        swap(a[row], a[rk]);
        int inv = pow(a[rk][col], mod - 2);
        for(int j = n; j >= col; j--) {
            a[rk][j] = (i128)a[rk][j] * inv % mod;
        }
        for(int i = 0; i < m; i++) {
            if(i == rk) continue;
            int q = a[i][col];
            if(q == 0) continue;
            for(int j = col; j <= n; j++) {
                a[i][j] = norm(a[i][j] - (i128)q * a[rk][j] % mod);
            }
        }
        pivot[col] = rk++;
    }
    for(int i = rk; i < m; i++) {
        if(a[i][n]) return nullopt;
    }
    ModLinearSol<T> sol;
    sol.particular.assign(n, 0);
    for(int col = 0; col < n; col++) {
        if(pivot[col] != -1) {
            sol.particular[col] = a[pivot[col]][n];
        }
    }
    for(int free = 0; free < n; free++) {
        if(pivot[free] != -1) continue;
        vector<T> v(n);
        v[free] = 1;
        for(int col = 0; col < n; col++) {
            if(pivot[col] != -1) {
                int row = pivot[col];
                v[col] = (mod - a[row][free]) % mod;
            }
        }
        sol.basis.emplace_back(move(v));
    }
    return sol;
}


inline void solve() {
    int n; cin >> n;
    vector<vector<int>> a(prime.size(), vector<int>(n + 1));
    rep(i, 0, n - 1) {
        int x; cin >> x;
        for(int j = 0; j < prime.size(); j++) {
            int c = 0, p = prime[j];
            while(x % p == 0) {
                c ^= 1;
                x /= p;
            }
            a[j][i] = c;
        }
    }
    auto ans = GaussMod(a, 2);
    if(ans) {
        // dbg(ans.value().basis.size())
        cout << p[ans.value().basis.size()] - 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    Prime(2000);
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ":" << endl;
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