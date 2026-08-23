#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define all(A,i) A.begin()+i,A.end()
#define int ll

void solve(){
    ll n,sum=0;cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(all(a,1));
    vector<int>ans(n+1);
    // cout<<sum<<endl;
    for(int i=n,mx=n,mn=1;i>=3;i--){
        if(sum-a[mx]>a[mx]){
            ans[i]=sum;
            sum-=a[mn++];
        }
        else{
            while(mn>1&&sum-a[mx]<=a[mx]){
                sum-=a[mx--];
                sum+=a[--mn];
            }
            if(sum-a[mx]>a[mx]) {
                ans[i]=sum;
                sum-=a[mn++];
            }
            else{
                sum-=a[mx--];
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
        solve();
}
