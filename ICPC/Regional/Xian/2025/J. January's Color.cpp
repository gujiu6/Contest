#include <bits/stdc++.h>
using namespace std;
const int MAXX=3e5+10,INF=1e9+7,LIMIT=25;
using ll=long long;
#define all(A,i) A.begin()+i,A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
#define int ll

array<int,MAXX>h,a,fa,deep,dp;
array<array<int,2>,MAXX>mn;
array<int,MAXX<<1>nxt,to;
array<array<int,LIMIT>,MAXX>up,sum;
array<int,MAXX>in,out;
ll n,cnt,times;
void build(){
    fill(h.begin(),h.begin()+n+1,0);
    fill(a.begin(),a.begin()+n+1,0);
    cnt=1;
    times=0;
    deep[0]=0;
}

void addEdge(int u,int v){
    nxt[cnt]=h[u];
    to[cnt]=v;
    h[u]=cnt++;
}
void dfs(int u,int f){
    fa[u]=f;
    deep[u]=deep[f]+1;
    in[u]=++times;
    dp[u]=a[u];
    int mn1=INF,mn2=INF;
    for(int ei=h[u],v;ei>0;ei=nxt[ei]){
        v=to[ei];
        if(v!=f){
            dfs(v,u);
            if(dp[v]<=mn1){
                mn2=mn1;
                mn1=dp[v];
            }
            else if(dp[v]<mn2){
                mn2=dp[v];
            }
        }
    }
    dp[u]=min(dp[u],mn1+mn2);
    mn[u]={mn1,mn2};
    out[u]=times;
}
void init(){
    rep(u,1,n){
        int f=fa[u];
        up[u][0]=f;
        if(u!=1){
            sum[u][0]=(dp[u]==mn[f][0]?mn[f][1]:mn[f][0]);
        }
    }
    rep(k,1,LIMIT-1){
        rep(u,1,n){
            int v=up[u][k-1];
            up[u][k]=up[v][k-1];
            sum[u][k]=sum[u][k-1]+sum[v][k-1];
        }
    }
}
bool ok(int x,int y){
    return in[y]<=in[x] && out[x]<=out[y];
}
int qry(int x,int y){
    if(x==y) return 0;
    if(!ok(x,y)) return -1;
    int ans=0,dd=deep[x]-deep[y];
    per(k,0,LIMIT-1){
        if(dd&(1LL<<k)){
            ans+=sum[x][k];
            x=up[x][k];
        }
    }
    return ans;
}


void solve(){
    ll m;cin>>n>>m;
    int u,v,ans=0;
    build();
    rep(i,1,n) cin>>a[i];
    rep(i,1,n-1){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,0);
    init();
    int x,y;
    while(m--){
        cin>>x>>y;
        cout<<qry(x,y)<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
        solve();
}