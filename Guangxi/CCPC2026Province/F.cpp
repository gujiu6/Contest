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




int cnt;
array<int, MAXX> h, sz_man, fa_man, sz_woman, fa_woman;
array<int, MAXX << 1> nxt, to;

void build(int n){
    cnt = 1;
    fill(sz_man.begin(), sz_man.begin() + n + 1, 1);
    fill(sz_woman.begin(), sz_woman.begin() + n + 1, 1);
    fill(h.begin(), h.begin() + n + 1, 0);
    iota(fa_woman.begin(), fa_woman.begin() + n + 1, 0);
    iota(fa_man.begin(), fa_man.begin() + n + 1, 0);
}

void addEdge(int u, int v){
    nxt[cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt++;
}

int find(array<int, MAXX>& fa, int i){
    if(fa[i] != i){
        fa[i] = find(fa, fa[i]);
    }
    return fa[i];
}

bool merge(array<int, MAXX>& fa, array<int, MAXX>&sz, int x, int y){
    int fx = find(fa, x), fy = find(fa, y);
    if(fx != fy){
        if(sz[fx] >= sz[fy]){
            sz[fx] += sz[fy];
            fa[fy] = fx;
        }
        else{
            sz[fy] += sz[fx];
            fa[fx] = fy;
        }
        return 1;
    }
    return 0;
}

bool is_s(array<int, MAXX>& fa, int x, int y){
    return find(fa, x) == find(fa, y);
}



inline void solve() {
    int n, m, q, s, t; cin >> n >> m >> q >> s >> t;
    build(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    auto bfs = [&]() {
        queue<int> q_man, q_woman;
        vector<bool> vis_man(n + 1), vis_woman(n + 1);
        vis_woman[t] = 1;vis_man[s] = 1;
        q_man.push(s);q_woman.push(t);
        while(!q_man.empty() || !q_woman.empty()) {
            while(!q_man.empty()) {
                auto m = q_man.front();q_man.pop();
                for(int ei = h[m], v; ei > 0; ei = nxt[ei]) {
                    v = to[ei];
                    if(!vis_woman[v] && !is_s(fa_woman, v, t)) {
                        merge(fa_woman, sz_woman, t, v);
                        vis_woman[v] = 1;
                        q_woman.push(v);
                    }
                }
            }
            while(!q_woman.empty()) {
                auto m = q_woman.front();q_woman.pop();
                for(int ei = h[m], v; ei > 0; ei = nxt[ei]) {
                    v = to[ei];
                    if(!vis_man[v] && !is_s(fa_man, v, s)) {
                        merge(fa_man, sz_man, s, v);
                        vis_man[v] = 1;
                        q_man.push(v);
                    }
                }
            }
        }
    };
    bfs();
    while(q--) {
        int a, b; cin >> a >> b;
        if(is_s(fa_man, s, a) && is_s(fa_woman, t, b)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
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