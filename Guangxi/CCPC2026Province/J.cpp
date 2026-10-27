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
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};






inline void solve() {
	int n; cin >> n;
	ll mxa = -INF, mxb = -INF, mna = INF, mnb = INF;
	vector<ll> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i], mxa = max(mxa, a[i]), mna = min(mna, a[i]);
	rep(i, 1, n) cin >> b[i], mxb = max(mxb, b[i]), mnb = min(mnb, b[i]);
	if(n == 1) {
		cout << (a[1] == b[1] ? 0 : -1) << endl;
		return;
	}
	if(mxb > mxa || mnb < mna) {
		cout << -1 << endl;
		return;
	}
	if(n == 2) {
		if((a[1] >= a[2] && b[1] >= b[2]) || (a[1] <= a[2] && b[1] <= b[2])) {
			
		}
		else {
			cout << -1 << endl;
			return;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += abs(a[i] - b[i]);
	}
	int x = -1, y = -1, j = -1, k = -1;
	rep(i, 1, n) {
		if(a[i] == mxa && x == -1) x = i;
		if(a[i] == mna && y == -1) y = i;
		if(b[i] == mxb && j == -1) j = i;
		if(b[i] == mnb && k == -1) k = i;
	}
	if(x == k && y == j) {
		sort(all(a, 1));
		sort(all(b, 1));
		ans += min({a[2] - b[1], b[2] - b[1], b[n] - b[n -1], b[n] - a[n - 1]}) * 2;
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