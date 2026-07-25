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
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=2e5+10,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};



const int MAXN = 1e5 + 10, MAXM = 1e5 + 10;

int n, m;
array<int, MAXN> arr;
array<ll, MAXM> ans;
array<int, MAXX> cnt, f;

int sz;
ll cur_ans;

struct Query {
    int l, r;
    int t;
    int id;

    bool operator<(const Query &other) const {
        int bl1 = l / sz;
        int bl2 = other.l / sz;
        if (bl1 != bl2) return bl1 < bl2;

        int br1 = r / sz;
        int br2 = other.r / sz;
        if (br1 != br2) return (bl1 & 1) ? (br1 < br2) : (br1 > br2);

        return t < other.t;
    }
} q[MAXN];


struct Modify {
    int pos;
    int val;
} update[MAXM];

int qcnt = 0;
int ccnt = 0;
int total = 0;
void init() {
    vector<int> a;
    for(int i = 1; i <= n; i++) {
        a.push_back(arr[i]);
    }
    for(int i = 1; i <= ccnt; i++) {
        a.push_back(update[i].val);
    }
    sort(all(a, 0));
    a.erase(unique(all(a, 0)), a.end());
    total = a.size();
    for(int i = 1; i <= n; i++) {
        arr[i] = lower_bound(all(a, 0), arr[i]) - a.begin() + 1;
    }
    for(int i = 1; i <= ccnt; i++) {
        update[i].val = lower_bound(all(a, 0), update[i].val) - a.begin() + 1;
    }
}

void add(int i) {
    int x = arr[i];
    if(cnt[x]) {
        f[cnt[x]]--;
    }
    cnt[x]++;
    f[cnt[x]]++;
    for(int j = 1; j <= total; j++) {
        if(f[j] == 0) {
            cur_ans = j;
            break;
        }
    }
}

void del(int i) {
    int x = arr[i];
    f[cnt[x]]--;
    cnt[x]--;
    f[cnt[x]]++;
    for(int j = 1; j <= total; j++) {
        if(f[j] == 0) {
            cur_ans = j;
            break;
        }
    }
}

void moveTime(int l, int r, int t){
    int p = update[t].pos;
    int v = update[t].val;
    if(l <= p && p <= r){
        del(p);
        swap(arr[p], update[t].val);
        add(p);
    }else{
        swap(arr[p], update[t].val);
    }
}


inline void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sz = max(1, (int)pow(n, 2.0 / 3));
    qcnt = ccnt = 0;
    for(int i = 1; i <= m; i++){
        int op;
        cin >> op;
		//查询
        if(op == 1){
            ++qcnt;
            cin >> q[qcnt].l >> q[qcnt].r;
            if(q[qcnt].l > q[qcnt].r)
                swap(q[qcnt].l , q[qcnt].r);
            q[qcnt].t = ccnt;
            q[qcnt].id = qcnt;
        }
		//修改
        else{
            ++ccnt;
            cin >> update[ccnt].pos >> update[ccnt].val;
        }
    }
    init();
    sort(q + 1, q + qcnt + 1);

    int l=1, r=0, t=0;
    cur_ans=0;
    for(int i = 1; i <= qcnt; i++){
        int jobl = q[i].l, jobr = q[i].r, jobt = q[i].t;
        while(l > jobl) add(--l);
        while(r < jobr) add(++r);
        while(l < jobl) del(l++);
        while(r > jobr) del(r--);

        while(t < jobt)
            moveTime(l, r, ++t);

        while(t > jobt)
            moveTime(l, r, t--);
        ans[q[i].id] = cur_ans;
    }

    for(int i = 1; i <= qcnt; i++)
        cout << ans[i] << endl;
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