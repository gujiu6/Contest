#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define int long long
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};



array<int,MAXX>head,inDeg,outDeg;
array<int,MAXX<<1>nxt,to;
int cnt;
priority_queue<int,vector<int>,greater<int>>q;

void build(){
    cnt=1;
    head.fill(0);
    inDeg.fill(0);
    outDeg.fill(0);
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
    inDeg[v]++;
    outDeg[u]++;
}

vector<int>topsort(int n){//字典序
    int cur;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(inDeg[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        cur=q.top();
        ans.push_back(cur);
        q.pop();
        for(int ei=head[cur];ei!=0;ei=nxt[ei]){
            if(--inDeg[to[ei]]==0) q.push(to[ei]);
        }
    }
    return ans;
}


inline void solve() {
    int n, m; cin >> n >> m;
    build();
    rep(i, 1 ,m) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }
    auto ans = topsort(n);
    // dbg(ans.size())
    if(ans.size() == n) {
        cout << "Yes" << endl;
        for(int x : ans) cout << x << " ";
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
    
        solve();
    
    }
    return 0;
}
// 难道我不配AC吗
//   ▄████  █    ██  ▄▄▄██▀▀▀██▓ █    ██
//  ██▒ ▀█▒ ██  ▓██▒   ▒██  ▓██▒ ██  ▓██▒
// ▒██░▄▄▄░▓██  ▒██░   ░██  ▒██▒▓██  ▒██░
// ░▓█  ██▓▓▓█  ░██░▓██▄██▓ ░██░▓▓█  ░██░
// ░▒▓███▀▒▒▒█████▓  ▓███▒  ░██░▒▒█████▓
//  ░▒   ▒ ░▒▓▒ ▒ ▒  ▒▓▒▒░  ░▓  ░▒▓▒ ▒ ▒
//   ░   ░ ░░▒░ ░ ░  ▒ ░▒░   ▒ ░░░▒░ ░ ░
//  ░   ░  ░░░ ░ ░  ░ ░ ░   ▒ ░ ░░░ ░ ░
//       ░    ░      ░   ░   ░     ░