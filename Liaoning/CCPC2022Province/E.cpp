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



template <typename T = int>
class DSU {
private:
    int n;
    vector<int> fa,sz;
    vector<T> value;
public:
    DSU(int n) : n(n), fa(n + 1), sz(n + 1, 1), value(n + 1, 0) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int i){
        if(fa[i] != i){
            fa[i] = find(fa[i]);
        }
        return fa[i];
    }

    bool is_same(int x, int y){
        return find(x) == find(y);
    }

    bool merge(int x, int y){
        int fx = find(x), fy = find(y);
        if(fx != fy){
            if(sz[fx] >= sz[fy]){
                sz[fx] += sz[fy];
                fa[fy] = fx;
            }
            else{
                sz[fy] += sz[fx];
                fa[fx] = fy;
            }
            return 1;
        }
        return 0;
    }
    T findV(int x){
        return value[find(x)];
    }
    int size(int x){
        return sz[find(x)];
    }
};


inline void solve() {
	int n, m; cin >> n >> m;
	DSU dsu(m + 1);
	int k; cin >> k;
	int p; cin >> p;
	rep(j, 2, k){
		int x; cin >> x;
		dsu.merge(p, x);
	}
	int ans = 1;
	rep(i, 2, n) {
		int k; cin >> k;
		bool f = 0;
		rep(j, 1, k) {
			int x;cin >> x;
			if(dsu.is_same(p, x)) f = 1;
		}
		ans += f;
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