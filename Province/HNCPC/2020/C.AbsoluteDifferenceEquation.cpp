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
const int MAXX=1e6+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};



string s;
class CC{
private:
    vector<ll>f, inv;
public:
    ll power(ll a,ll b){
        ll ans = 1;
        a %= MOD;
        while(b > 0){
            if(b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    CC(int n) : f(n + 1, 1), inv(n + 1, 0){
        for(int i = 1; i <= n; i++){
            f[i] = f[i-1] * i % MOD;
        }
        inv[n] = power(f[n], MOD - 2);
        for(int i = n - 1; i >= 0; i--){
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    ll C(int n, int m){
        if(m < 0 || m > n) return 0;
        return f[n] * inv[m] % MOD * inv[n-m] % MOD;
    }
    ll P(int n, int m){
        if(m < 0 || m > n) return 0;
        return f[n] * inv[n - m] % MOD;
    }
    ll prefix_sum_C(int n, int m) {
        if (m < 0) return 0;
        if (m >= n) return power(2,n);
        ll sum = 0;
        for (int k = 0; k <= m; k++) {
            sum = (sum + C(n, k)) % MOD;
        }
        return sum;
    }
};
CC C(MAXX);

inline void solve() {
	int n = s.size();
	if(n == 1) {
		if(s[0] == '0') cout << 0 << endl;
		else if(s[0] == '?') cout << 1 << endl;
		else cout << 1 << endl;
		return;
	}
	int cnt = 0, sum = 0, c = 0;
	for(int i = 0; i < n; i++) {
		if((i & (n - 1)) == i) {
			if(s[i] == '?') cnt++;
			else sum ^= (s[i] - '0');
		}
		else {
			if(s[i] == '?') c++;
		}
	}
	// dbg(c)dbg(cnt)dbg(sum)
	int ans = 0;
	if(sum == 0) {
		for(int i = 1; i <= cnt; i += 2) {
			ans = (ans + C.C(cnt, i) * C.power(2, c)) % MOD;
		}
	}
	else {
		for(int i = 0; i <= cnt; i += 2) {
			ans = (ans + C.C(cnt, i) * C.power(2, c)) % MOD;
		}
	}
	cout << ans << endl;
}







signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t=1;
	//cin>>t;
	while(cin >> s){
	
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
