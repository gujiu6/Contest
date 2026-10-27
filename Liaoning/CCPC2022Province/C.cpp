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
const int MAXX=500000+100,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};



int cnt,lg2, n, k;
ll total;
array<int,MAXX>h,deep,sz, pa;
array<int,MAXX<<1>nxt,to;
array<array<int,LIMIT>,MAXX>stjump;

void build(){
    cnt=1;
    lg2=__lg(n);
    fill(h.begin(),h.begin()+n+1,0);
    fill(deep.begin(),deep.begin()+n+1,0);
}

void addEdge(int u,int v){
    nxt[cnt]=h[u];
    to[cnt]=v;
    h[u]=cnt++;
}

void dfs(int u,int f){
	pa[u]=f;
    deep[u]=deep[f]+1;
    stjump[u][0]=f;
	sz[u] = 1;
    for(int p=1;p<=lg2;p++){
        stjump[u][p]=stjump[stjump[u][p-1]][p-1];
    }
    for(int ei=h[u];ei>0;ei=nxt[ei]){
        if(to[ei]!=f) {
			dfs(to[ei],u);
			sz[u] += sz[to[ei]];
		}
    }
	total += (sz[u] - 1) >= k;
}


inline void solve() {
	cin >> n >> k;
	build();
	rep(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	auto calc = [&](int u)->ll {
		int fa = pa[u];
		if(!fa) return 0;
		int high = fa;
		if(sz[high] > sz[u] + k) return 0;
		for(int p = lg2; p >= 0; p--) {
			int f = stjump[high][p];
			if(f && sz[f] <= sz[u] + k) {
				high = f;
			}
		}
		int low = fa;
		if(sz[fa] <= k) {
			for(int p = lg2; p >= 0; p--) {
				int f = stjump[low][p];
				if(f && sz[f] <= k) {
					low = f;
				}
			}
			low = stjump[low][0];
		}
		if(low && deep[low] >= deep[high]) {
			return deep[low] - deep[high] + 1;
		}
		return 0;
	};
	ll ans = total;
	rep(i, 2, n) {
		ll res = calc(i);
		ans = min(ans, total - res);
		// dbg(i)dbg(res)
	}
	cout << ans << endl;
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