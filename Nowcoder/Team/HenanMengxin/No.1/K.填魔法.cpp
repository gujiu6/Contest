#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
// #define int long long
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
// const int INF=1e9+7;
const int MOD=998244353;
// const int MAXX=2e5+10,LIMIT=20;
// const double eps=1e-6;
// const double PI = acos(-1);
// int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
// int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

int n, m, s;

string to_s(int x) {
    string ans;
    while(x) {
        ans += '0' + x % s;
        x /= s;
    }
    while(ans.size() < m) ans.push_back('0');
    reverse(all(ans, 0));
    return ans;
}

inline void solve() {
    cin >> n >> m >> s;
    vector<string> status;
    string st, ed;
    int st_k = -1, ed_k = -1;
    for(int i = 0; i < m; i++) {
        char c; cin >> c;
        st += c;
    }
    for(int i = 0; i < m; i++) {
        char c; cin >> c;
        ed += c;
    }
    string ss;
    auto dfs = [&](auto &&dfs, int pos) {
        if(pos == m) {
            status.push_back(ss);
            if(ss == st) st_k = status.size() - 1;
            if(ss == ed) ed_k = status.size() - 1;
            return;
        }
        for(int i = 0; i < s; i++) {
            int cur = '0' + i;
            if(pos && cur == ss.back()) continue;
            ss += ('0' + i);
            dfs(dfs, pos + 1);
            ss.pop_back();
        }
    };
    dfs(dfs, 0);
    if(st_k == -1 || ed_k == -1) {
        cout << 0 << endl;
        return ;
    }
    int kk = status.size();
    vector<vector<ll>> dp(n + 2, vector<ll>(kk + 2, 0));
    vector<vector<int>> nxt(kk + 1);
    for(int i = 0; i < kk; i++) {
        for(int j = 0; j < kk; j++) {
            bool f = 1;
            for(int x = 0; x < m; x++) {
                if(status[i][x] == status[j][x]) {
                    f = 0;
                    break;
                }
            }
            if(f)
                nxt[i].push_back(j);
        }
    }
    dp[1][st_k] = 1;
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        for(int pre = 0; pre < kk; pre++) {
            if(dp[i - 1][pre] == 0) continue;
            for(int cur : nxt[pre]) {
                dp[i][cur] = (dp[i][cur] + dp[i - 1][pre]) % MOD;
            }
        }
    }
    cout << dp[n][ed_k] << endl;
    
    
}




signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    //cin>>t;
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