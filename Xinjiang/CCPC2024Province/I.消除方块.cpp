#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define endl '\n'
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
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

int n, m;
bool cmp(pii a, pii b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]) > 1;
}
char mp[65][65];
string s[30];
int c_to_str[256];

inline void solve() {
    cin >> n >> m;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> mp[i][j];
    int k; cin >> k;
    vector<ll> dp(1LL << k, -1);
    auto del = [&](const int &id, const pii pos[])->bool {
        const string &ss = s[id];
        for(int i = 0; i < ss.size() - 1; i++) {
            char ch1 = ss[i], ch2 = ss[i + 1];
            if(cmp(pos[ch1], pos[ch2])) {
                return false;
            }
        }
        return true;
    };
    auto calc = [&](const int& mask, pii pos[])->void {
        int col = 0;
        for(int c = 0; c < m; c++) {
            int row = 0;
            for(int r = 0; r < n; r++) {
                char ch = mp[r][c];
                int id = c_to_str[ch];
                if(!((mask >> id) & 1)) {
                    pos[ch] = {row, col};
                    row++;
                }
            }
            if(row) col++;
        }
    };

    auto dfs = [&](auto &&dfs, int mask)->ll {
        if(mask == (1LL << k) - 1) {
            return 1;
        }
        if(dp[mask] != -1) return dp[mask];
        pii pos[256];
        calc(mask, pos);
        ll ans = 0;
        rep(i, 0, k - 1) {
            if(!((mask >> i) & 1)) {
                if(del(i, pos)) {
                    ans = (ans + dfs(dfs, mask | (1LL << i))) % MOD;
                }
            }
        }
        return dp[mask] = ans;
    };
    rep(i, 0, k - 1) {
        cin >> s[i];
        for(auto c : s[i]) {
            c_to_str[c] = i;
        }
    }
    cout << dfs(dfs, 0) << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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