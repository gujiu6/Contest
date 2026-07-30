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
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


template <typename T = ll>
class BIT {
private:
    int n;
    vector<T> tree;

    inline int lowbit(int i) {
        return i & -i;
    }
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}
    BIT(vector<T>& arr, int n) : BIT(n) {
        for(int i = 1; i <= n; i++) {
            tree[i] += arr[i];
            int j = i + lowbit(i);
            if(j <= n) tree[j] += tree[i];
        }
    }
    void add(int i, T v) {
        while(i <= n){
            tree[i] += v;
            i += lowbit(i);
        }
    }

    T qry(int i) {
        T ans = 0;
        while(i > 0) {
            ans += tree[i];
            i -= lowbit(i);
        }
        return ans;
    }

    T range_qry(int left, int right) {
        return qry(right) - qry(left - 1);
    }

    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
};

const int MAXN = 1e5+10, MAXM = 4e5+10;
int n, m;
array<int, MAXN> arr, cnt;
array<ll, MAXM> ans;
BIT bit(MAXN);
int sz;
ll cur_ans;
struct Query {
    int l, r, id;
    bool operator<(const Query &other) const {
        int b1 = l / sz;
        int b2 = other.l / sz;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < other.r) : (r > other.r);
    }
} q[MAXM];

void add(int i) {
	ll x = arr[i];
    cnt[x]++;
    if(cnt[x] == 1)
        bit.add(x, 1);
}

void del(int i) {
	ll x = arr[i];
    cnt[x]--;
    if(cnt[x] == 0)
        bit.add(x, -1);
}

inline void solve() {
	cin >> n;
    vector<vector<int>> pos(n + 10, vector<int>(1));
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
        pos[arr[i]].push_back(i);
	}
    rep(i, 1, n + 1) {
        pos[i].push_back(n + 1);
    }
    m = 0;
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 0; j < pos[i].size() - 1; j++) {
            int l = pos[i][j] + 1, r = pos[i][j + 1] - 1;
            if(l > r) continue;
            q[++m] = {l, r, i};
        }
    }
	sz = max(1, (int)(n / sqrt(m)));
	sort(q + 1, q + m + 1);

	int l = 1, r = 0;
	cur_ans = 0;
    for (int i = 1; i <= m; i++) {
		int jobl = q[i].l, jobr = q[i].r;
        int jobv = q[i].id;
        while (l > jobl) add(--l);
        while (r < jobr) add(++r);
        while (l < jobl) del(l++);
        while (r > jobr) del(r--);
        if(bit.qry(jobv - 1) == jobv - 1)
            ans[jobv] = true;
    }
    rep(i, 1, n + 2) {
        if(ans[i]) continue;
        cout << i << endl;
        return;
    }
}








signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
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