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





int n, m;
inline void solve() {
    vector<int> a(n + 2, INF);
    rep(i, 1, n) cin >> a[i];
    vector<int> L(n + 1), R(n + 1);
    vector<int> st{0};
    rep(i, 1, n) {
        int cur = a[i];
        while(a[st.back()] < cur) {
            st.pop_back();
        }
        L[i] = st.back();
        st.push_back(i);
    }
    st.assign(1, n + 1);
    per(i, n, 1) {
        int cur = a[i];
        while(a[st.back()] <= cur) {
            st.pop_back();
        }
        R[i] = st.back();
        st.push_back(i);
    }
    vector<int> f(n + 100);
    auto add = [&](int l, int r, int s, int d) {
        if(l > r) return;
        f[l] += s;
        f[l + 1] += d - s;
        f[r + 1] -= (r - l + 1) * d + s;
        f[r + 2] += (r - l) * d + s;
    };
    rep(i, 1, n) {
        int mx = a[i];
        int len_mx = mx - m;
        if(len_mx <= 0) continue;
        int l = max(L[i] + 1, i - len_mx + 1);
        int r = min(R[i] - 1, i + len_mx - 1);
        int llen = (i - l);
        if(llen >= 1) {
            // for(int j = i; j <= r; j++) {
            //     int rlen = (j - i + 1);
            //     f[j] += min(len_mx - rlen, llen) + 1;
            // }
            if(len_mx - 1 >= llen) {
                int mid = len_mx - llen + i - 1;
                add(i, min(mid - 1, r), llen + 1, 0);
                add(mid, r, llen + 1, -1);
            }
            else {
                add(i, r, len_mx, -1);
            }
        }
        else {
            // for(int j = i; j <= r; j++) {
            //     f[j]++;
            // }
            add(i, r, 1, 0);
        }
    }
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + f[i];
    }
    
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + f[i];
        cout << f[i] << " ";
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
    //cin >> t;
    while(cin >> n >> m){
    
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