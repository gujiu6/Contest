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
const ll INF=1e18;
const int MOD=998244353;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

const ll G = 3;
ll power(ll a, ll b) {
    ll ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wn = power(G, (MOD - 1) / len);
        if (invert)
            wn = power(wn, MOD - 2);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wn % MOD;
            }
        }
    }
    if (invert) {
        ll inv_n = power(n, MOD - 2);
        for (auto &x : a)
            x = x * inv_n % MOD;
    }
}

vector<ll> mul(vector<ll> A, vector<ll> B) {
    int result_len = A.size() + B.size() - 1;
    int n = 1;
    while (n < result_len)
        n <<= 1;
    A.resize(n);
    B.resize(n);
    ntt(A, false);
    ntt(B, false);
    for (int i = 0; i < n; i++) {
        A[i] = A[i] * B[i] % MOD;
    }
    ntt(A, true);
    A.resize(result_len);
    return A;
}



inline void solve() {
    int n; cin >> n;
    ll len = 1;
    while(len <= 4e5) {
        len <<= 1;
    }
    vector<int> a(n + 1), b(n + 1);
    vector<ll> cnt_a(len), cnt_b(len), cnt_c(len);
    rep(i, 1, n) cin >> a[i], cnt_a[a[i]]++;
    rep(i, 1, n) cin >> b[i], cnt_b[b[i]]++;
    for(int i = 0; i < len; i++) {
        cnt_c[i] = cnt_a[i] && cnt_b[i];
    }
    auto cnt_aa = cnt_a, cnt_bb = cnt_b, cnt_cc = cnt_c;
    ntt(cnt_aa, false);
    ntt(cnt_bb, false);
    ntt(cnt_cc, false);
    for(int i = 0; i < len; i++) {
        cnt_aa[i] = cnt_aa[i] * cnt_aa[i] % MOD;
        cnt_bb[i] = cnt_bb[i] * cnt_bb[i] % MOD;
        cnt_cc[i] = cnt_cc[i] * cnt_cc[i] % MOD;
    }
    ntt(cnt_aa, true);
    ntt(cnt_bb, true);
    ntt(cnt_cc, true);
    for(int i = 0; i < len / 2; i++) {
        cnt_aa[i * 2] = (cnt_aa[i * 2] - cnt_a[i] + MOD) % MOD;
        cnt_bb[i * 2] = (cnt_bb[i * 2] - cnt_b[i] + MOD) % MOD;
        cnt_cc[i * 2] = (cnt_cc[i * 2] - cnt_c[i] + MOD) % MOD;
    }
    ll ans = 0;
    for(int s = 0; s < len; s++) {
        ans = (ans + 1LL * cnt_aa[s] * cnt_bb[s] - 2 * cnt_cc[s]  % MOD) % MOD;
    }
    cout << ans << endl;
    
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
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