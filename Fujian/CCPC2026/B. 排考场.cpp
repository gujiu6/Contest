#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9+7;
using pii = array<int, 2>;


void solve(){
    int n, m; cin >> n >> m;
    vector<pii> a(m); 
    for(int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    auto check = [&](int k) {
        int res = 0;
        for(auto [r, c] : a) {
            res += r * ((c - 1) / (k + 1) + 1);
        }
        return res;
    };
    int l = 0, r = INF, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid) >= n) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}



signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) 
        solve();
}