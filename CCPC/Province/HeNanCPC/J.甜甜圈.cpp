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



inline void solve() {
    int n1, n2; cin >> n1 >> n2;
    int n = n1 + n2;
    vector<int> a(n1 + 1), b(n2 + 1);
    vector<pair<ll, int>> arr(n + 1);
    rep(i, 1, n1) {
        cin >> a[i];
        arr[n1 - i + 1] = {a[i], n1 - i + 1};
    }
    rep(i, 1, n2) {
        cin >> b[i];
        arr[n1 + i] = {b[i], n1 + i};
    }
    sort(all(arr, 1), [](pair<ll, int> x, pair<ll, int> y){
        return x.first > y.first;
    });
    BIT bit(n);
    for(int i = 1; i <= n; i++) bit.add(i, 1);
    ll ans = 0;
    int cur = n1;
    for(int i = 1; i <= n; i++) {
        auto p = arr[i].second;
        if (p <= cur) {
            ans += bit.range_qry(p + 1, cur);
        } else {
            ans += bit.range_qry(cur + 1, p - 1);
        }
        bit.add(p, -1);
        cur = p;
    }
    cout << ans << endl;
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