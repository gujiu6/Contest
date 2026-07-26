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
using pii = array<ll, 2>;
const ll INF=1e18;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
    int n, k, d; cin >> n >> k >> d;
    vector<int> a(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> q1;
    map<int, int> mp2, mp3;
    priority_queue<pii> q2;
    ll ans = 0;
    rep(i, 1, n) cin >> a[i];
    for(int r = 1, l1 = 1, l2 = 1, l3 = 1; r <= n; r++) {
        q1.push({a[r], r});q2.push({a[r], r});
        mp2[a[r]]++;mp3[a[r]]++;
        while(q2.top()[0] - q1.top()[0] > d) {
            l1++;
            while(q2.top()[1] < l1) q2.pop();
            while(q1.top()[1] < l1) q1.pop();
        }
        if(mp2.size() < k) continue;
        while(mp2.size() > k) {
            mp2[a[l2]]--;
            if(mp2[a[l2]] == 0) mp2.erase(a[l2]);
            l2++;;
        }
        while(mp3.size() > k - 1) {
            mp3[a[l3]]--;
            if(mp3[a[l3]] == 0) mp3.erase(a[l3]);
            l3++;
        }
        ans += max(0LL, min(l3 - 1, r) - max(l1, l2) + 1LL);
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