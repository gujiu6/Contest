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
const ll INF=1e18;
const int MOD=1e9+7;
const int MAXX=4e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

int cnt, n, m;
// <= m
array<int, MAXX> h, sz, inrk1, inrk2, maxsub, choose, outer;
array<int, MAXX << 1> nxt, to;

void build() {
    cnt = 1;
    fill(h.begin(), h.begin() + n + 1, 0);
}
void addEdge(int u, int v) {
    nxt[cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt++;
}

void dfs1(int u, int f) {
    sz[u] = 1;
    for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
        v = to[ei];
        if(v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[maxsub[u]]) {
            maxsub[u] = v;
        }
        int insz = sz[v] <= m ? sz[v] : inrk1[v];
        if(insz > inrk1[u]) {
            choose[u] = v;
            inrk2[u] = inrk1[u];
            inrk1[u] = insz;
        }
        else if(insz > inrk2[u]) {
            inrk2[u] = insz;
        }
    }
}

void dfs2(int u, int f) {
    for(int ei = h[u], v; ei > 0; ei = nxt[ei]) {
        v = to[ei];
        if(v == f) continue;
        int outsz = n - sz[v];
        if(outsz <= m) outer[v] = outsz;
        else if(choose[u] != v) {
            outer[v] = max(outer[u], inrk1[u]);
        }
        else {
            outer[v] = max(outer[u], inrk2[u]);
        }
        dfs2(v, u);
    }
}

bool check(int u) {
    if(sz[maxsub[u]] > m) {
        return sz[maxsub[u]] - inrk1[maxsub[u]] <= m;
    }
    if(n - sz[u] > m) {
        return n - sz[u] - outer[u] <= m;
    }
    return true;
} 

inline void solve() {
    cin >> n;
    build();
    m = n / 2;
    rep(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++) {
        cout << check(i) << " ";
    }
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