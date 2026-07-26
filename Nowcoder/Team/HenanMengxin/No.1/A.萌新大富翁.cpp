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






inline void solve() {
    int n, m; cin >> n >> m;
    vector<int> c(n), g(m), toll(m), price(m);
    vector<int> pos(n, 0);
    vector<vector<int>> cnt(n);
    vector<int> order(m, -1);
    vector<bool> vis(n, 0);
    rep(i, 0, n - 1) cin >> c[i];
    rep(i, 0, m - 1) {
        cin >> g[i];
        if(g[i] == 1) {
            cin >> price[i] >> toll[i];
        }
    }
    int shenyu = n;
    int k; cin >> k;
    int i = 0;
    while(shenyu > 1 && k--) {
        int d; cin >> d;
        while(vis[i] || c[i] == -1) {
            vis[i] = 0;
            i = (i + 1) % n;
        }
        pos[i] = (pos[i] + d) % m;
        if(pos[i] == 0) c[i] += 200;
        if(g[pos[i]] == 1) {
            if(order[pos[i]] == -1) {
                if(c[i] >= price[pos[i]]) {
                    c[i] -= price[pos[i]];
                    order[pos[i]] = i;
                    cnt[i].push_back(pos[i]);
                }
            }
            else if(order[pos[i]] != i){
                if(c[i] >= toll[pos[i]]) {
                    c[i] -= toll[pos[i]];
                    c[order[pos[i]]] += toll[pos[i]];
                }
                else {
                    c[order[pos[i]]] += c[i];
                    shenyu--;
                    c[i] = -1;
                    for(int p : cnt[i]) {
                        order[p] = -1;
                    }
                    cnt[i].clear();
                }
            }
        }
        else if(g[pos[i]] == 2) {
            c[i] += 150;
        }
        else if(g[pos[i]] == 3) {
            if(c[i] >= 100) c[i] -= 100;
            else {
                shenyu--;
                c[i] = -1;
                for(int p : cnt[i]) {
                    order[p] = -1;
                }
                cnt[i].clear();
            }
        }
        else if(g[pos[i]] == 4){
            vis[i] = 1;
        }
        i = (i + 1) % n;
    }
    for(int i = 0; i < n; i++) {
        if(c[i] == -1) {
            cout << "bankrupt 0" << endl;
        }
        else {
            cout << c[i] << " " << cnt[i].size() << endl;
        }
    }
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