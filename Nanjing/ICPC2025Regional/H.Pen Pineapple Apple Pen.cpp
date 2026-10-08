#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
#define int long long
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define dbg(x) cout<<#x<<"="<<x<<endl;
using i64 = long long;
using i128 = __int128;
using ld = long double;
using u64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 998244353;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};



template <class T = i64>
struct ArithmeticDiff {
    int n;
    vector<T> dd;//二阶差分
    ArithmeticDiff (int n): n(n), dd(n + 2) {}
    //[l,r]加等差数列初始s,公差d
    void add(int l, int r, T s, T d) {
		if(l > r) return;
        int len = (r - l + 1);
        T t = s + (len - 1) * d;
        dd[l] += s;
        dd[l + 1] += d - s;
        dd[r + 1] -= t + d;
        dd[r + 2] += t;
    }
    vector<T> build() {
        vector<T> a(n + 1);
        for(int i = 1; i <= n; i++) {
            dd[i] = ((dd[i] + dd[i - 1]) % MOD + MOD) % MOD;
        }
        for(int i = 1; i <= n; i++) {
            a[i] = ((a[i - 1] + dd[i]) % MOD + MOD) % MOD;
        }
        return a;
    }
};


inline void solve() {
	string s; cin >> s;s = ' ' + s;
	int n = s.size() - 1;
	vector<vector<int>> lcs(n + 2, vector<int>(n + 2));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i] == s[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
		}
	}
	vector<vector<int>> d(n + 3, vector<int>(n + 3));
	for(int r = 1; r <= n; r++) {
		for(int k = 1; k <= n; k++) {
			int len = lcs[r][k];
			if(len < 1) continue;
			int l = k - len + 1;
			d[r][l] = (d[r][l] + 1) % MOD;
			d[r][k + 1] = (d[r][k + 1] - 1 + MOD) % MOD;
		}
	}
	vector<vector<int>> C(n + 3, vector<int>(n + 3));
	for(int r = 1; r <= n; r++) {
		int cur = 0;
		for(int l = 1; l <= n; l++) {
			cur = ((cur + d[r][l]) % MOD + MOD) % MOD;
			C[r][l] = cur;
		}
	}
	vector<vector<int>> F(n + 3, vector<int>(n + 3));
	for(int r = 1; r <= n; r++) {
		for(int l = n; l >= 1; l--) {
			F[r][l] = (F[r][l + 1] + C[r][l]) % MOD;
		}
	}
	for(int r = 1; r <= n; r++) {
		for(int l = 1; l <= n; l++) {
			F[r][l] = (F[r - 1][l] + F[r][l]) % MOD;
		}
	}
	vector<vector<int>> mid(n + 3, vector<int>(n + 3));
	for(int j3 = 1; j3 <= n; j3++) {
		ArithmeticDiff d(n);
		for(int j2 = 1; j2 < j3; j2++) {
			int l3 = min(lcs[j2][j3], j3 - j2);
			if(l3 < 1) continue;
			int i2 = j2 - l3 + 1;
			d.add(1, j2 - l3, l3, 0);
			d.add(j2 - l3 + 1, j2 - 1, l3 - 1, -1);
		}
		auto x = d.build();
		for(int i2 = 1; i2 < j3; i2++) {
			mid[i2][j3] = x[i2];
		}
	}
	int ans = 0;
	for(int i2 = 1; i2 <= n; i2++) {
		for(int j3 = i2 + 1; j3 <= n; j3++) {
			ans = (ans + mid[i2][j3] * F[i2 - 1][j3 + 1]) % MOD;
		}
	}
	cout << ans << endl;
}







signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		
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