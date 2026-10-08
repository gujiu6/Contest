#include <bits/stdc++.h>
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
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr ll INF = 1e18;
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




inline void solve() {
    cin >> n;
    build();
    vector<int> p(n + 1);
    rep(u, 2, n + 1) {
        cin >> p[u - 1];
        addEdge(u, p[u - 1]);
        addEdge(p[u - 1], u);
    }
    dfs(1, 0);
    int a = 1, b = 1, d = 0, ans = -1;
    for(int i = 1; i <= n; i++) {
        int u = i + 1;
        int da = dist(a, u), db = dist(b, u);
        int dmx = max(da, db);
        if(dmx == d) {
            ans = i;
            break;
        }
        else if(dmx > d) {
            d++;
            if(da == d) {
                b = u;
            }
            else {
                a = u;
            }
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