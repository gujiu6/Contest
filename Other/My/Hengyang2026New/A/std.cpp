#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int MOD = 1e9+7;

signed main() {
    int n, m; cin >> n >> m;
    vector<int> R(n + 1);
    while(m--) {
        int l, r; cin >> l >> r;
        R[l] = max(R[l], r);
    }
    int ans = 0;
    for(int l = 1; l <= n; l++) {
        R[l] = max(R[l], R[l - 1]);
        int cur = max(0LL, R[l] - l + 1);
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
    return 0;
}