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


//快读
ll read(){
    bool flag = false;
    ll ans = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') flag = true;
        c = getchar();
    }
    while(isdigit(c)){
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return flag ? -ans : ans;
}
//快写
void write(ll x){
    if(x == 0){
        putchar('0');
        return;
    }
    if(x < 0){
        putchar('-');
        x = -x;
    }
    char ch[50];
    int index = 0;
    while(x){
        ch[index++] = x % 10 + '0';
        x /= 10;
    }
    for(int i = index - 1; i >= 0; i--) {
        putchar(ch[i]);
    }
}
template <typename T = int>
class DSU {
private:
    int n, total;
    vector<int> fa,sz;
    vector<T> value;
public:
    DSU(int n) : n(n), fa(n + 1), sz(n + 1, 1), value(n + 1, 0), total(n) {
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
			total--;
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
	int get_total() {
		return total;
	}
};

inline void solve() {
	ll n, m; n =read(); m = read();
	vector<array<ll, 3>> edge(m + 1);
	ll l = 0, r = 0, mid;
	for(int i = 1; i <= m; i++) {
		ll u, v, w; u = read();v = read(); w = read();
		edge[i] = {u, v, w};
		r = max(r, w);
	}
	ll ans = r;
	auto check = [&](ll k)->ll {
		DSU dsu(n);
		for(int i = 1; i <= m; i++) {
			auto [u, v, w] = edge[i];
			if(w > k) {
				dsu.merge(u, v);
			}
		}
		return dsu.get_total();
	};
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid) >= 2) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	write(ans);
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