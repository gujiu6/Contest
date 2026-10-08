#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
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
const ll INF = 1e18;
const int MOD = 1e9+7;
const int MAXX = 2e5+10, LIMIT = 20;
const double eps = 1e-6, PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

array<int, MAXX> h, inDeg, outDeg;
array<int, MAXX << 1> nxt, to;
int cnt, n;
priority_queue<int, vector<int>, greater<int>>q;

void build(){
    cnt = 1;
    h.fill(0);
    inDeg.fill(0);
    outDeg.fill(0);
}

void addEdge(int u, int v){
    nxt[cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt++;
    inDeg[v]++;
    outDeg[u]++;
}

vector<int>topsort(){//字典序
    int cur;
    vector<int> ans;
    for(int i = 1;i <= n; i++){
        if(inDeg[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        cur = q.top();
        ans.push_back(cur);
        q.pop();
        for(int ei = h[cur]; ei != 0; ei = nxt[ei]){
            if(--inDeg[to[ei]] == 0) q.push(to[ei]);
        }
    }
    return ans;
}

int find(vector<char>& arr, char x) {
    return lower_bound(all(arr, 0), x) - arr.begin() + 1;
}


inline void solve() {
    int m; cin >> m;
    vector<char> arr;
    vector<array<char, 3>> a(m + 1);
    rep(i, 1, m) {
        string s; cin >> s;
        char mid = s[0], l = s[2], r = s[3];
        a[i] = {l, mid, r};
        arr.push_back(l);
        arr.push_back(mid);
        arr.push_back(r);
    }
    sort(all(arr, 0));
    arr.erase(unique(all(arr, 0)), arr.end());
    // for(auto x : arr) cout << x << endl;
    n = arr.size();
    build();
    rep(i, 1, m) {
        auto [l, mid, r] = a[i];
        int ll = find(arr, l), mmid = find(arr, mid), rr = find(arr, r);
        // dbg(l)dbg(mid)dbg(r)dbg(ll)dbg(mmid)dbg(rr)cout<<endl;
        addEdge(ll, mmid);
        addEdge(mmid, rr);
    }
    auto ans = topsort();
    if(ans.size() != n) {
        cout << "No Answer" << endl;
    }
    else {
        for(auto id : ans) {
            // dbg(id)
            cout << arr[id - 1];
        }
        cout << endl;
    }
}







signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t=1;
    //cin>>t;
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