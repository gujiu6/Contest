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


bool check(int mask) {
    int ans = 0;
    while (mask) {
        if(mask & 1) ans++;
        mask >>= 1;
    }
    return ans == 7;
}



inline void solve() {
    string s; cin >> s;
    vector<vector<int>> g(9);
    for(int i = 1; i <= 8; i++) {
        int l1 = (i + 2) % 8 + 1, l2 = (i + 4) % 8 + 1; 
        g[i].push_back(l1);
        g[i].push_back(l2);
        g[l1].push_back(i);
        g[l2].push_back(i);
    }
    auto pd = [&](int mask)->bool {
        for(int i = 0; i < 8; i++) {
            if((mask >> i) & 1) continue;
            bool f = 0;
            for(int v : g[i + 1]) {
                if((mask >> (v - 1)) & 1) continue;
                f = 1;
            }
            if(f) return f;
        }
        return false;
    };
    auto dfs = [&](auto &&dfs, int mask)->bool {
        if(check(mask)) {
            return 1;
        }
        if(!pd(mask)) {
            return 0;
        }
        bool ans = 0;
        for(int i = 0; i < 8; i++) {
            if((mask >> i) & 1) continue;
            for(int v : g[i + 1]) {
                if((mask >> (v - 1)) & 1) continue;
                ans |= dfs(dfs, mask | (1 << (v - 1)));
            }
        }
        return ans;
    };
    int mask = 0;
    for(int i = 0; i < 8; i++) {
        if(s[i] == '1') {
            mask |= (1 << i);
        }
    }
    cout << (dfs(dfs, mask) ? "Yes" : "No") << endl;
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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