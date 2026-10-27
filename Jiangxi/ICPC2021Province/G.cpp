#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
// #define int long long
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
constexpr int MAXX = 1e6+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};

vector<int> prime_mn;
vector<int> prime;
void Prime_Euler(i64 n){
    prime_mn.assign(n + 1, 0);
    for(int i = 2; i <= n; i++){
        if(!prime_mn[i]) prime.emplace_back(i), prime_mn[i] = i;
        for(int j = 0; j < prime.size() && i * prime[j] <= n; j++){
            prime_mn[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

struct Query {
    int l, r, id;
};
template <class Ans = int, class AddL, class AddR, class DelL, class DelR, class Get>
vector<Ans> mo(int n, vector<Query> &q, AddL addL, AddR addR, DelL delL, DelR delR, Get get) {
    int m = q.size() - 1;
    int sz  = max(1, (int)(n / sqrt(m)));
    sort(q.begin() + 1, q.end(), [&](const Query &x, const Query &y){
        auto xl = x.l / sz, yl = y.l / sz;
        if(xl != yl) return xl < yl;
        return xl & 1 ? x.r > y.r : x.r < y.r;
    });
    vector<Ans> ans(m + 1);
    for(int l = 1, r = 0, i = 1; i <= m; i++) {
        int jobl = q[i].l, jobr = q[i].r, jobid = q[i].id;
        while (l > jobl) addL(--l);
        while (r < jobr) addR(++r);
        while (l < jobl) delL(l++);
        while (r > jobr) delR(r--);
        ans[jobid] = get();
        if(i == m) {
            while(l <= r) {
                delL(l++);
            }
        }
    }
    
    return ans;
}
const int maxx = 5e4 + 10;
array<int, maxx> a;
array<int, MAXX> cnt;
array<int, maxx> ff;
array<vector<int>, MAXX> mp;

inline void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i];
        int v = a[i];
        if(mp[a[i]].size() == 0) {
            while(v > 1) {
                int p = prime_mn[v];
                mp[a[i]].push_back(p);
                while(v % p == 0) v /= p;
            }
        }
    }
    vector<Query> q(1);
    for(int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        q.push_back({l, r, i});
    }
    int cur_ans = 0;
    auto add = [&](int i)->void {
        for(int p : mp[a[i]]) {
            cnt[p]++;
            ff[cnt[p] - 1]--;
            ff[cnt[p]]++;
            cur_ans = max(cur_ans, cnt[p]);
        }
    };
    auto del = [&](int i)->void {
        for(int p : mp[a[i]]) {
            cnt[p]--;
            ff[cnt[p] + 1]--;
            ff[cnt[p]]++;
            if(cnt[p] + 1 == cur_ans && ff[cnt[p] + 1] == 0) {
                cur_ans--;
            }
        }
    };
    auto get = [&]()->int {
        return cur_ans;
    };
    auto ans = mo(n, q, add, add, del, del, get);
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    Prime_Euler(MAXX);
    cin >> t;
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