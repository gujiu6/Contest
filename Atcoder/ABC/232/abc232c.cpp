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
	vector<vector<int>> mp1(n + 1, vector<int>(n + 1)), mp2(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		mp1[u][v] = 1;
		mp1[v][u] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		mp2[u][v] = 1;
		mp2[v][u] = 1;
	}
	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);
	do {
		bool ok = 1;
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				if(mp1[u][v] != mp2[p[u]][p[v]]) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) {
			cout << "Yes" << endl;
			return;
		}
	}while(next_permutation(all(p, 1)));
	cout << "No" << endl;
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