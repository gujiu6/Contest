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
	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n + 1, vector<char>(m + 1));
	rep(i, 1, n) rep(j, 1, m) cin >> mp[i][j];
	ll ans1 = 0, ans2 = 0;
	rep(i, 1, n) {
		rep(j, 1, m) {
			char c = mp[i][j];
			if(c == '0') continue;
			if(c == '1') {
				if(j + 4 <= m && mp[i][j + 1] == c && mp[i][j + 2] == c && mp[i][j + 3] == c && mp[i][j + 4] == c) ans1++;
				if(i + 4 <= n && mp[i + 1][j] == c && mp[i + 2][j] == c && mp[i + 3][j] == c && mp[i + 4][j] == c) ans1++;
				if(i + 4 <= n && j + 4 <= m && mp[i + 1][j + 1] == c && mp[i + 2][j + 2] == c && mp[i + 3][j + 3] == c && mp[i + 4][j + 4] == c) ans1++;
				if(i + 4 <= n && j - 4 >= 1 && mp[i + 1][j - 1] == c && mp[i + 2][j - 2] == c && mp[i + 3][j - 3] == c && mp[i + 4][j - 4] == c) ans1++;
			}
			else {
				if(j + 4 <= m && mp[i][j + 1] == c && mp[i][j + 2] == c && mp[i][j + 3] == c && mp[i][j + 4] == c) ans2++;
				if(i + 4 <= n && mp[i + 1][j] == c && mp[i + 2][j] == c && mp[i + 3][j] == c && mp[i + 4][j] == c) ans2++;
				if(i + 4 <= n && j + 4 <= m && mp[i + 1][j + 1] == c && mp[i + 2][j + 2] == c && mp[i + 3][j + 3] == c && mp[i + 4][j + 4] == c) ans2++;
				if(i + 4 <= n && j - 4 >= 1 && mp[i + 1][j - 1] == c && mp[i + 2][j - 2] == c && mp[i + 3][j - 3] == c && mp[i + 4][j - 4] == c) ans2++;
			}
	}
}
	cout << ans1 << " " << ans2 << endl;
	
}







signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t=1;
	//cin>>t;
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