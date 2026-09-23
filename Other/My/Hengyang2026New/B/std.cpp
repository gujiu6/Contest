#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    if(n < 4) {
        cout << -1 << endl;
        return 0;
    }
    cout << n - 1 << " " << n << " ";
    for(int i = 1; i <= n - 2; i++) {
        cout << i << " \n"[i == n - 2];
    }
}