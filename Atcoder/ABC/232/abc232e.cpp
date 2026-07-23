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
const int MOD=998244353;
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
//0 : (x == x2 && y == y2)
//1 : (x == x2 && y != y2)
//2 : (x != x2 && y == y2)
//3 : (x != x2 && y != y2)
inline void solve() {
	ll n, m, k; cin >> n >> m >> k;
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	vector<vector<ll>> A{{0,1,1,0},{m-1,m-2,0,1},{n-1,0,n-2,1},{0,n-1,m-1,n+m-4}};
	vector<vector<ll>> dp(4, vector<ll>(1));
	if(x1 == x2 && y1 == y2) {
		dp[0][0] = 1;
	}
	else if(x1 == x2 || y1 == y2) {
		if(x1 == x2) dp[1][0] = 1;
		else dp[2][0] = 1;
	}
	else {
		dp[3][0] = 1;
	}
	dp = power(A, k, dp);
	cout << dp[0][0] << endl;
	
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