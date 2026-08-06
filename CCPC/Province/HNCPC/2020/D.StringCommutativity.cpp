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
using i64 = long long;
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


vector<int> nextArray(string s) {
    int n = s.size();
    if(n == 1) return {-1, 0};
    vector<int> nxt(n + 1);
    nxt[0] = -1; nxt[1] = 0;
    int i = 2, cnt = 0;
    while(i <= n) {
        if(s[i - 1] == s[cnt]) {
            nxt[i++] = ++cnt;
        }
        else if(cnt > 0) {
            cnt = nxt[cnt];
        }
        else {
            nxt[i++] = 0;
        }
    }
    return nxt;
}
string min_string(string s) {
    int n = s.size();
    vector<int> nxt = nextArray(s);
    int len = n - nxt[n];
    if(n % len == 0) return s.substr(0, len);
    else return s;
}


int n;

inline void solve() {
	string s, x;
	map<string, int> mp; 
	rep(i, 1, n) {
		cin >> s;
		x = min_string(s);
		mp[x]++;
	}
	int ans = 0;
	for(auto [a, b] : mp) {
		ans += (b - 1) * b / 2;
	}
	cout << ans << endl;
}







signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t=1;
	//cin>>t;
	while(cin >> n){
	
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