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
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(n + 1), ans(m + 1), nxt(n + 10, n + 1), pre(n + 1);
    nxt[0] = 0;
    rep(i, 1, n) cin >> a[i];
    map<ll, int> mp;
    for(int l = 1, r = 1; l <= n; l++) {
        while(r <= n && mp.size() < k) {
            mp[a[r]]++;
            r++;
        }
        if(mp.size() == k) {
            nxt[l] = r - 1;
        }
        else {
            nxt[l] = n + 1;
        }
        mp[a[l]]--;
        if(mp[a[l]] == 0) mp.erase(a[l]);
    }

    rep(i, 1, n) pre[i] = pre[i - 1] + nxt[i];
    rep(i, 1, m) {
        ll lll, rrr; cin >> lll >> rrr;
        ll l = min(lll ^ ans[i - 1], rrr ^ ans[i - 1]) + 1;
        ll r = max(lll ^ ans[i - 1], rrr ^ ans[i - 1]) + 1;
        if (l > r) {
            ans[i] = 0;
            cout << 0 << endl;
            continue;
        }
        auto pos = upper_bound(nxt.begin() + l, nxt.begin() + r + 1, r) - nxt.begin() - 1;
        ll res = 0;
        if(pos >= l && pos <= r) {
            res = 1LL * (pos - l + 1) * (r + 1) - (pre[pos] - pre[l - 1]);
        }
        ans[i] = res;
        cout << res << endl;
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