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
    int n, q; cin >> n >> q;
    BIT bit(n << 1);
    vector<ll> a(n + 1);
    rep(i, 1, n) {
        cin >> a[i];
        if(i >= 2 && a[i - 1] > a[i]) {
            bit.add(i - 1, 1);
        }
    }
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int i, x; cin >> i >> x;
            if(i < n) {
                if(a[i] <= a[i + 1] && x > a[i + 1]) {
                    bit.add(i, 1);
                }
                else if(a[i] > a[i + 1] && x <= a[i + 1]) {
                    bit.add(i, -1);
                }
            }
            if(i > 1) {
                if(a[i - 1] <= a[i] && a[i - 1] > x) {
                    bit.add(i - 1, 1);
                }
                else if(a[i - 1] > a[i] && a[i - 1] <= x) {
                    bit.add(i - 1, -1);
                }
            }
            a[i] = x;
        }
        else {
            int l, r; cin >> l >> r;
            cout << (bit.qry(r - 1) - bit.qry(l - 1) == 0 ? "Yes" : "No") << endl;
        }
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