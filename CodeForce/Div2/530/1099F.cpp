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
const int MAXX = 1e6+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

array<ll, MAXX << 2> cnt, sum, ad;

void up(int i) {
    cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void add(int jobi, ll jobv, int l, int r, int i) {
    if(l == r) {
        cnt[i] += jobv;
        sum[i] += jobv * l;
        return;
    }
    int mid = (l + r) >> 1;
    if(jobi <= mid) {
        add(jobi, jobv, l, mid, i << 1);
    }
    else {
        add(jobi, jobv, mid + 1, r, i << 1 | 1);
    }
    up(i);
}

ll qry(ll jobv, int l, int r, int i) {
    if(jobv <= 0 || cnt[i] == 0) return 0;
    if(l == r) {
        ll num = min(cnt[i], jobv / l);
        jobv -= num * l;
        return num;
    }
    int mid = (l + r) >> 1;
    if(sum[i << 1] <= jobv) {
        jobv -= sum[i << 1];
        return cnt[i << 1] + qry(jobv, mid + 1, r, i << 1 | 1);
    }
    else {
        return qry(jobv, l, mid, i << 1);
    }
}

inline void solve() {
    int n; ll tme; cin >> n >> tme;
    vector<vector<pair<int, ll>>> g(n + 1);
    vector<int> num(n + 1), t(n + 1);
    rep(i, 1, n) cin >> num[i];
    rep(i, 1, n) cin >> t[i];
    rep(u, 2, n) {
        int f, w; cin >> f >> w;
        g[f].push_back({u, w});
    }
    vector<ll> ff(n + 1);
    auto dfs = [&](auto &&dfs, int u, int f, ll total_w)->void {
        add(t[u], num[u], 1, MAXX, 1);
        for(auto [v, w] : g[u]) {
            dfs(dfs, v, u, total_w + w);
        }
        ll rem = tme - 2LL * total_w;
        ff[u] = qry(rem, 1, MAXX, 1);
        add(t[u], -num[u], 1, MAXX, 1);
    };
    dfs(dfs, 1, 0, 0);
    // for(int i = 1; i <= n; i++) {
    //     dbg(i)dbg(ff[i])
    // }
    vector<ll> dp(n + 1);
    auto dfs1 = [&](auto &&dfs1, int u, int f)->void {
        vector<ll> child;
        for(auto [v, w] : g[u]) {
            dfs1(dfs1, v, u);
            child.push_back({dp[v]});
        }
        sort(all(child, 0), greater<ll>());
        if(u == 1) {
            dp[u] = ff[u];
            if(!child.empty()) {
                dp[u] = max(dp[u], child[0]);
            }
        }
        else {
            dp[u] = ff[u];
            if(child.size() > 1) {
                dp[u] = max(dp[u], child[1]);
            }
        }
    };
    dfs1(dfs1, 1, 0);
    cout << dp[1] << endl;
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