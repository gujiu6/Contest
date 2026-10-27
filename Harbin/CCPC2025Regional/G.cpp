#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii array<int,2>
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define rep(i,l,r) for(int i=l;i<r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> h(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> h[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int s = 0;
        for(int j = m; j >= 1; j--) {
            if(h[i][j] < 0) {
                s += h[i][j];
            }
            else {
                if(h[i][j] + s >= 0) {
                    h[i][j] += s;
                    if(i + 1 <= n) {
                        h[i + 1][j] += h[i][j];
                        h[i][j] = 0;
                    }
                    s = 0;
                }
                else {
                    s += h[i][j];
                    h[i][j] = 0;
                }
            }
        }
        ans += abs(s);
    }
    for(int j = 1; j <= m; j++) {
        if(h[n][j] >= 0) ans += h[n][j];
    }
    cout << ans << endl;

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
}