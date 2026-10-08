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
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    bool f = 0;
    rep(i, 1, n) {
        cin >> a[i];
        if(a[i] == 1) f = 1;
    }
    int q; cin >> q;
    if(f) {
        while(q--) {
            ll x; cin >> x;
            cout << 0 << endl;
        }
        return;
    }
    vector<ll> arr;
    sort(all(a, 1));
    rep(i, 1, n) {
        bool ok = 1;
        for(auto x : arr) {
            if(a[i] % x == 0) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            arr.push_back(a[i]);
        }
    }
    ll cnt = 0;
    ll x = 0;
    auto dfs = [&](auto &&dfs, ll cur_lcm, int dep, int c)->void {
        if(dep == arr.size()) {
            if(c > 0) {
                ll terms = x / cur_lcm;
                if (c % 2 == 1) cnt += terms;
                else cnt -= terms;
            }
            return ;
        }
        dfs(dfs, cur_lcm, dep + 1, c);
        ll nxt_lcm = lcm(cur_lcm, arr[dep]);
        if(nxt_lcm <= x)
            dfs(dfs, nxt_lcm, dep + 1, c + 1);
    };
    while(q--) {
        cin >> x;
        cnt = 0;
        dfs(dfs, 1, 0, 0);
        cout << x - cnt << endl;
    }
    
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