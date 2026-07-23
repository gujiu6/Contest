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


//矩阵快速幂
vector<vector<ll>> mul(const vector<vector<ll>>& a,const vector<vector<ll>>& b) {
    //a : n * k, b : n * m
    int n = a.size();
    int k = a[0].size();
    int m = b[0].size();
    vector<vector<ll>> ans(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int c = 0; c < k; c++){
                ans[i][j] = (ans[i][j] + 1LL * a[i][c] * b[c][j]) % MOD;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>> A,int p,const vector<vector<ll>>& f) {
    //f : 初始矩阵
    vector<vector<ll>>ans = f;
    while(p > 0) {
        if(p & 1) ans = mul(A, ans);
        A = mul(A, A);
        p >>= 1;
    }
    return ans;
}



inline void solve() {
	ll n, m, k, x; cin >> n >> m >> k >> x;
	vector<ll> cnt(10);
	rep(i, 1, n){
		int a; cin >> a;
		cnt[a]++;
	}
	vector<vector<ll>> f(x, vector<ll>(1));
	for(int i = 1; i < 10; i++) {
		f[i % x][0] += cnt[i];
	}
	vector<vector<ll>> A(x, vector<ll>(x));
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < x; j++) {
			for(int d = 1; d < 10; d++) {
				if(!cnt[d]) continue;
				if((j * 10 + d) % x == i) {
					A[i][j] += cnt[d];
				}
			}
		}
	}
	auto dp = power(A, m - 1, f);
	cout << dp[k][0] << endl;

	
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