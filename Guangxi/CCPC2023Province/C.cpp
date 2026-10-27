#include <bits/stdc++.h>
#include <cassert>
//#include <bit>
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


int cnt, lg2, n;
array<int, MAXX> h, deep;
array<int, MAXX << 1> nxt, to, wei;
array<array<int, LIMIT>, MAXX> stjump;

void build(){
    cnt = 1;
    lg2 = __lg(n);
    fill(h.begin(), h.begin() + n + 1, 0);
    fill(deep.begin(), deep.begin() + n + 1, 0);
}

void addEdge(int u, int v, int w = 0){
    nxt[cnt] = h[u];
    to[cnt] = v;
    wei[cnt] = w;
    h[u] = cnt++;
}

void dfs(int u, int f){
    deep[u] = deep[f] + 1;
    stjump[u][0] = f;
    for(int p = 1; p <= lg2; p++){
        int mid = stjump[u][p - 1];
        stjump[u][p] = stjump[mid][p - 1];
    }
    for(int ei = h[u], v;ei > 0; ei = nxt[ei]){
        v = to[ei];
        if(v == f) continue;
        dfs(v, u);
    }
}

int lca(int a, int b){
    if(deep[a] < deep[b]) swap(a, b);
    for(int p = lg2; p >= 0; p--){
        if(deep[stjump[a][p]] >= deep[b]){
            a = stjump[a][p];
        }
    }
    if(a == b) return a;
    for(int p = lg2; p >= 0; p--){
        if(stjump[a][p] != stjump[b][p]){
            a = stjump[a][p];
            b = stjump[b][p];
        }
    }
    return stjump[a][0];
}

int dist(int u, int v) {
    return deep[u] + deep[v] - 2 * deep[lca(u, v)];
}
int up_k(int u, int k) {
    for(int p = lg2; p >= 0; p--) {
        int cur = (1LL << p);
        if(cur <= k) {
            u = stjump[u][p];
            k -= cur;
        }
    }
    // dbg(k)
    return u;
}


inline void solve() {
    int q; cin >> n >> q;
    build();
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    while(q--) {
        int s, t, ss; cin >> s >> t >> ss;
        int c_s_t = lca(s, t), c_s_ss = lca(s, ss);
        int d_s_t = dist(s, t);
        int d_s_c = dist(s, c_s_t);
        int d_ss_c = dist(ss, c_s_t);
        int d_ss_s = dist(ss, s);
        int d_ss_t = dist(ss, t);
        int ans = 0, p = 0;
        if(c_s_ss == ss || c_s_ss == s) {
            if(c_s_ss == ss) {
                if(d_s_t < d_ss_t) {
                    ans = d_ss_t;
                    p = t;
                }
                else {
                    ans = (d_ss_s + 2 - 1) / 2;
                    if (ans <= d_s_c) p = up_k(s, ans);
                    else p = up_k(t, d_s_t - ans);
                }
            }
            else {
                if(d_s_t < d_ss_t) {
                    ans = d_ss_t;
                    p = t;
                }
                else {
                    ans = (d_ss_s + 2 - 1) / 2;
                    if (ans <= d_s_c) p = up_k(s, ans);
                    else p = up_k(t, d_s_t - ans);
                }
            }
        }
        else if(d_ss_c <= d_s_c) {
            ans = (d_ss_s + 2 - 1) / 2;
            p = up_k(s, ans);
        }
        else {
            if(d_ss_t <= d_s_t) {
                ans = (d_ss_s + 2 - 1) / 2;
                p = up_k(t, d_s_t - ans);
            }
            else {
                ans = d_ss_t;
                p = t;
            }
        }
        cout << ans << " " << p << endl;
    }
    
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