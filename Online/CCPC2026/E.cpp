#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
#define pii array<int,2>
const int MAXX = 2e5+10, MOD = 1e9+7, BASE = 131;
int binpow(int a,int b,int p){
    if(b==0)return 0;
    int r=binpow(a, b>>1, p);
    if(b%2)return a*r%p*r%p;
    else return r*r%p;
}
vector<int> pw(MAXX);
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    rrp(i, 1, n) cin >> a[i];
    rrp(i, 1, n) cin >> b[i];
    rrp(i, 1, n) cin >> c[i];
    int ans = 0, hash1 = 0, hash2 = 0, hash3 = 0;
    for(int i = 1; i <= n; i++) {
        hash1 = (hash1 + a[i] * pw[a[i]] % MOD) % MOD;
        hash2 = (hash2 + b[i] * pw[b[i]] % MOD) % MOD;
        hash3 = (hash3 + c[i] * pw[c[i]] % MOD) % MOD;
        if(hash1 == hash2 or hash1 == hash3 or hash2 == hash3) {
            ans++;
        }
    }
    cout << ans << endl;
}
signed main(){
    int t=1;
    cin>>t;
    pw[0] = 1;
    for(int i = 1; i <= MAXX; i++) {
        pw[i] = pw[i - 1] * BASE % MOD;
    }
    while(t--)solve();
}