#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
#define pii array<int,2>
void solve(){
    int arr[7]={};
    rrp(i,1,6){cin>>arr[i];arr[i]++;}
    sort(arr+1,arr+6+1);
    arr[0] = 1;
    int k;cin>>k;
    int g = 1;
    rrp(a,0,6){
        rrp(b,0,6){
            rrp(c,0,6){
                rrp(d,0, 6){
                    rrp(e,0, 6){
                        rrp(f,0,6){
                            int s = arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f];
                            if (s<=k && a+b+c+d+e+f >= 19){
                                g =0;
                                cout<<"YES\n";
                                cout<<arr[a]+k-s<<" "<<arr[b]<<" "<<arr[c]<<" "<<arr[d]<<" "<<arr[e]<<" "<<arr[f]<<"\n";
                                // cout<<a<<b<<c<<d<<e<<f<<' '<<a+b+c+d+e+f;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    if(g) cout<<"NO\n";
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--)solve();
}
