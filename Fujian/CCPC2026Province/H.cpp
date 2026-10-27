#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, y; cin >> n >> y;
    int x = n - y;
    int f = 0;
    if(y % 3) {
        if(x % 3) {
            if(x % 3 + y % 3 > 3) f++;
        }
        else f++;
    }
    cout << (y / 3 + f) << " " << min((n + 9) / 10, y / 6) << endl;
}



signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) 
        solve();
}