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
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


int cnt, n;
array<int, MAXX> h, dp, val, fa;
array<int, MAXX << 1> nxt, to, wei;
void build() {
    cnt = 1;
    fill(h.begin(), h.begin() + n + 1, 0);
    fill(dp.begin(), dp.begin() + n + 1, 0);
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = h[u];
    to[cnt] = v;
    wei[cnt] = w;
    h[u] = cnt++;
}

void dfs(int u, int f) {
    val[u] = 0;
    fa[u] = f;
    for(int ei = h[u], v, w; ei > 0; ei = nxt[ei]) {
        v = to[ei];
        w = wei[ei];
        if(v == f) continue;
        dfs(v, u);
        val[u] += w + val[v];
    }
}

inline void solve() {
    cin >> n;
    build();
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        addEdge(u, v, 0);
        addEdge(v, u, 1);
    }
    dfs(1, 0);
    auto dfs = [&](auto &&dfs, int u, int f, int w)->void {
        if(u != 1) {
            dp[u] = dp[f] + !w - w;
        }
        for(int ei = h[u], v, w; ei > 0; ei = nxt[ei]) {
            v = to[ei];
            w = wei[ei];
            if(v == f) continue;
            dfs(dfs, v, u, w);
        }
    };
    dp[1] = val[1];
    dfs(dfs, 1, 0, 0);
    vector<int> ans;
    int mn = INF;
    for(int i = 1; i <= n; i++) {
        if(dp[i] < mn) {
            mn = dp[i];
            ans.assign(1, i);
        }
        else if(dp[i] == mn) {
            ans.push_back(i);
        }
        // dbg(i)dbg(dp[i])dbg(val[i])
    }
    cout << mn << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
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