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
const int MAXX = 1e6+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};


template <typename T = ll>
class BIT {
private:
    int n, lg2;
    vector<T> tree;

    inline int lowbit(int i) {
        return i & -i;
    }
public:
    BIT(int n) : n(n), tree(n + 1, 0), lg2(__lg(n)) {}
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

    T kth(int k) {
        T pos = 0;
        int pw = 1 << lg2;
        for(int p = pw; p > 0; p >>= 1) {
            int nxt = pos + p;
            if(nxt <= n && tree[nxt] < k) {
                pos = nxt;
                k -= tree[nxt];
            }
        }
        return pos + 1;
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
    BIT bit(MAXX);
    rep(i, 1, n) {
        int x; cin >> x;
        bit.add(x, 1);
    }
    int total = n;
    while(q--) {
        int k; cin >> k;
        if(k < 0) {
            k = abs(k);
            bit.add(bit.kth(k), -1);
            total--;
        }
        else {
            bit.add(k, 1);
            total++;
        }
    }
    if(total == 0) cout << 0 << endl;
    else {
        cout << bit.kth(1) << endl;
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