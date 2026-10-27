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
const int MAXX=100000,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
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

const int MAXN = 100010, MAXM = 100010;
int n, m;
array<int, MAXN> a;
array<ll, MAXM> ans;

BIT<ll> bit_sum(MAXX), bit_cnt(MAXX);
int sz;
ll cur_ans, total_cnt, total_sum;
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
	ll x = a[i];
    ll cnt_le = bit_cnt.qry(x);
    ll cnt_gt = total_cnt - cnt_le;
    ll sum_le = bit_sum.qry(x);
    ll sum_gt = total_sum - sum_le;
    cur_ans += (x * cnt_le - sum_le) + (sum_gt - x * cnt_gt);
    bit_sum.add(x, x);
    bit_cnt.add(x, 1);
    total_cnt++;
    total_sum += x;
}

void del(int i) {
	ll x = a[i];
    bit_sum.add(x, -x);
    bit_cnt.add(x, -1);
    total_cnt--;
    total_sum -= x;
    ll cnt_le = bit_cnt.qry(x);
    ll cnt_gt = total_cnt - cnt_le;
    ll sum_le = bit_sum.qry(x);
    ll sum_gt = total_sum - sum_le;
    cur_ans -= (x * cnt_le - sum_le) + (sum_gt - x * cnt_gt);
}

inline void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sz = max(1, (int)(n / sqrt(m)));

	for(int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort(q + 1, q + m + 1);

	int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        ans[q[i].id] = 2 * cur_ans;
    }

	for(int i = 1; i <= m; i++) {
		cout << ans[i] << endl;
	}
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