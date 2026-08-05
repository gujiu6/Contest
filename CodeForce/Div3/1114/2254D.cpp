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




struct Node {
    int val, id;
    bool operator< (const Node& other) const{
        if(val != other.val) return val < other.val;
        return id < other.id;
    }
};

inline void solve() {
    int n; cin >> n;
    vector<Node> b(n + 1);
    vector<int> a(n + 1);
    rep(i, 1, n) {
        cin >> b[i].val;
        b[i].id = i;
    }
    sort(all(b, 1));
    if(b[1].val != 0) {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> g;
    vector<int> u;
    for(int i = 1; i <= n;) {
        vector<int> cur_g;
        int j = i;
        while(j <= n && b[j].val == b[i].val) {
            cur_g.push_back(b[j].id);
            j++;
        }
        u.push_back(b[i].val);
        g.push_back(cur_g);
        i = j;
    }
    // for(int i = 0; i < u.size(); i++){ 
    //     dbg(u[i])dbg(g[i].size())
    // }
    int mx = 0;
    for(int i = 1; i < u.size(); i++) {
        int v = u[i] - u[i - 1];
        int c = g[i - 1].size();
        if(v % c != 0) {
            cout << -1 << endl;
            return;
        }
        int vv = v / c;
        if(vv <= mx) {
            cout << -1 << endl;
            return;
        }
        for(int j : g[i - 1]) {
            a[j] = vv;
        }
        mx = vv;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) cout << mx + 1 << " ";
        else cout << a[i] << " ";
    }
    cout << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
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