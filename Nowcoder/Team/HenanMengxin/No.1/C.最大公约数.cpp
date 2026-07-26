#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
// #define int long long
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
const int MAXX=5e5+10,LIMIT=20;
// const double eps=1e-6;
// const double PI = acos(-1);
// int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
// int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

array<array<ll, LIMIT>, MAXX> st_min, st_gcd;
array<int, LIMIT> lg2;
array<ll, MAXX> arr;

void build(int n) {
    lg2[0] = -1;
    for(int i = 1; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
        st_gcd[i][0] = st_min[i][0] = arr[i];
    }
    for(int p = 1; p <= lg2[n]; p++) {
        for(int i = 1; i + (1LL << p) - 1 <= n; i++) {
            st_gcd[i][p] = gcd(st_gcd[i][p - 1], st_gcd[i + (1LL << (p - 1))][p - 1]);
            st_min[i][p] = min(st_min[i][p - 1], st_min[i + (1LL << (p - 1))][p - 1]);
        }
    }
}

ll qry_min(int l, int r) {
    if(l > r) return -INF;
    int p = lg2[r - l + 1];
    int ans = min(st_min[l][p], st_min[r - (1LL << p) + 1][p]);
    return ans;
}

ll qry_gcd(int l, int r) {
    if(l > r) return -INF;
    int p = lg2[r - l + 1];
    int ans = gcd(st_gcd[l][p], st_gcd[r - (1LL << p) + 1][p]);
    return ans;
}

inline void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> arr[i];
    build(n);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = i, r = i;
        while(l <= n) {
            r = l;
            int ll = l, rr = n;
            int g = qry_gcd(i, l);
            while(ll <= rr) {
                int mid = (ll + rr) >> 1;
                if(qry_gcd(i, mid) == g) r = max(r, mid), ll = mid + 1;
                else rr = mid - 1;  
            }
            int pr = r;
            if(qry_min(i, r) == g){
                ll = l, rr = r;
                while(ll <= rr) {
                    int mid = (ll + rr) >> 1;
                    if(qry_min(i, mid) == g) pr = min(pr, mid), rr = mid - 1;
                    else ll = mid + 1;
                }
                ans += (r - pr + 1);
            }
            l = r + 1;
        }
    }
    cout << ans << endl;
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