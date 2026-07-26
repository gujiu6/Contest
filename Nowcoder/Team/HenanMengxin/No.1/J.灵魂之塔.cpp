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
    int n; cin >> n;
    vector<int> a(n + 2), pre(n + 2), suf(n + 2);
    rep(i, 1, n) {
        cin >> a[i];
    }
    if(n <= 2) {
        cout << n << endl;
        return;
    }
    for(int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + (abs(a[i]) % 2 == abs(a[i - 1]) % 2);
        // cout << pre[i] << " ";
    }
    // cout << endl;
    for(int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] + (abs(a[i]) % 2 == abs(a[i + 1]) % 2);
    }
    int ans = 0;
    rep(i, 1, n) {
        if(i == 1 && suf[i + 1] == 0) {
            ans++;
        }
        else if(i == n && pre[i - 1] == 0) {
            ans++;
        }
        else if(pre[i - 1] + suf[i + 1] + (abs(a[i - 1]) % 2 == abs(a[i + 1]) % 2) == 0) {
            ans++;
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