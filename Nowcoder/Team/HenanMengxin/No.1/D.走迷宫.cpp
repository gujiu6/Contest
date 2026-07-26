#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define int long long
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
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};



int dp[2][1001][1001];


inline void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[0][i][j] = dp[1][i][j] = INF;
        }
    }
    vector<vector<char>> mp(n + 1, vector<char>(m + 1));
    pii S = {-1, -1}, T = {-1, -1};
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> mp[i][j];
            if(mp[i][j] == 'S') S = {i, j};
            if(mp[i][j] == 'T') T = {i, j};
        }
    }
    auto fun = [&](array<int, 4> x, array<int ,4> y) {
        return x[0] > y[0];
    };
    priority_queue<array<int, 4>, vector<array<int, 4>>, decltype(fun)> q(fun);
    q.push({0, 1, S[0], S[1]});
    dp[1][S[0]][S[1]] = 0;
    while(!q.empty()) {
        auto [d, p, x, y] = q.top(); q.pop();
        if(d != dp[p][x][y]) continue;
        if(x == T[0] && y == T[1]) {
            cout << d << endl;
            return;
        }
        for(int i = 0; i < 4; i++) {
            int bx = x + dx[i], by = y + dy[i];
            if(bx >= 1 && bx <= n && by >= 1 && by <= m) {
                if(mp[bx][by] == '#') {
                    if(p == 1 && dp[0][bx][by] > d + 1) {
                        dp[0][bx][by] = d + 1;
                        q.push({d + 1, 0, bx, by});
                    }
                }
                else if(dp[p][bx][by] > d + 1){
                    dp[p][bx][by] = d + 1;
                    q.push({d + 1, p, bx, by});
                }
            }
        }
    }
    cout << -1 << endl;
    
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