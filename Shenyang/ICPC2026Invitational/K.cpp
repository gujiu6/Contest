#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
void solve(){
    int n;cin>>n;
    vector<int> a(2 * n + 1), pre(2 * n + 1);
    rrp(i,1,n)cin >> a[i], a[i + n] = a[i];
    rrp(i,1,2*n) pre[i] = pre[i-1] + a[i];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    int ans = 0;
    for(int l = 2 * n - 1, r = 2 * n - 1; l >= 1; l--) {
        q.push({pre[l], l});
        while(r - l + 1 > n) {
            while(!q.empty() && q.top().second >= r) q.pop();
            r--;
        }
        if(r - l + 1 == n) {
            while(!q.empty() && q.top().second > r) q.pop();
            if(!q.empty() and q.top().first >= pre[l - 1]) {
                ans++;
            }
        }
    }
    cout << ans << endl;

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)solve();
}