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
using i128 = __int128_t;
using ld = long double;
using ui64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};



struct RollbackDSU {
    vector<int> fa;
    struct History {
        int x, px;
        int y, py;
        bool merged;
    };
    vector<History> st;
    RollbackDSU(int n = 0): fa(n + 1, -1){}
    int find(int i) const {
        while(fa[i] >= 0) {
            i = fa[i];
        }
        return i;
    }
    int snap() const {
        //返回当前回滚栈高度作为快照编号
        return st.size();
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            st.push_back({x, 0, y, 0, false});
            return false;
        }
        if(fa[x] > fa[y]) swap(x, y);
        st.push_back({x, fa[x], y, fa[y], true});
        fa[x] += fa[y];
        fa[y] = x;
        return true;
    }
    void rollback(int s) {
        //s:此前由snap返回的回滚栈高度;撤销到快照s时的并查集状态,无返回值
        while(st.size() > s) {
            auto &[x, px, y, py, merged] = st.back();
            st.pop_back();
            if(merged) {
                fa[x] = px;
                fa[y] = py;
            }
        }
    }
    bool same(int x, int y) const {
        return find(x) == find(y);
    }
    int size(int i) const {
        return -fa[find(i)];
    }
};


inline void solve() {
	int n, m; cin >> n >> m;
	vector<DEdge> edge(m + 1);
	rep(i, 1, m) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	int q; cin >> q;
	vector<pair<DEdge, int>> ques;
    rep(i, 1, q) {
        int k; cin >> k;
        while(k--) {
            int x; cin >> x;
            ques.push_back({edge[x], i});
        }
    }
    sort(all(edge, 1), [](auto x, auto y){
        return x.w < y.w;
    });
    sort(all(ques, 0), [](auto x, auto y) {
        if(x.first.w != y.first.w) return x.first.w < y.first.w;
        return x.second < y.second;
    });
    RollbackDSU d(n);
    vector<bool> ans(q + 1, 1);
    int cur = 0;
    for(int i = 0; i < ques.size();) {
        int j = i, cur_w = ques[i].first.w, cur_id = ques[i].second;
        while(j < ques.size() && ques[j].first.w == cur_w && ques[j].second == cur_id) {
            j++;
        }
        while(cur + 1 <= m && edge[cur + 1].w < cur_w) {
            d.merge(edge[cur + 1].u, edge[cur + 1].v);
            cur++;
        }
        int p = d.snap();
        if(ans[cur_id] == 1) {
            for(int k = i; k < j; k++) {
                if(!d.merge(ques[k].first.u, ques[k].first.v)) {
                    ans[cur_id] = 0;
                    break;
                }
            }
            d.rollback(p);
        }
        i = j;
    }
    for(int i = 1; i <= q; i++) {
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
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