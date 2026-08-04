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






inline void solve() {
    int n; cin >> n;
    set<pair<__int128_t, int>> s;
    map<int, __int128_t> mp;
    s.insert({1, 1});
    mp[1] = 1;
    int cur = 2;
    for(int i = 1; i <= n; i++) {
        int op; cin >> op;
        if(op == 1) {
            int x; cin >> x;
            char o; cin >> o;
            __int128_t id = (o == 'L') ? mp[x] * 2 : mp[x] * 2 + 1;
            s.insert({id, cur});
            mp[cur] = id;
            cur++;
        }
        else {
            int x; cin >> x;
            __int128_t iid = mp[x];
            int y = __lg(iid);
            __int128_t ss = (1LL << y), tt = ((1LL << (y + 1)) - 1);
            // dbg(iid)dbg(ss)dbg(tt)
            auto it = s.upper_bound({iid, 0});
            if(it == s.end()) {
                cout << -1 << endl;
            }
            else {
                auto id = (*it).first;
                // dbg(id)
                if(id == iid) it = next(it);
                if(it == s.end()) {
                    cout << -1 << endl;
                }
                else {
                    id = (*it).first;
                    if(id > iid && id <= tt) {
                        cout << (*it).second << endl;
                    }
                    else {
                        cout << -1 << endl;
                    }
                }
            }
        }
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