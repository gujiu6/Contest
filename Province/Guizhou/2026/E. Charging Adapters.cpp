#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
#define int long long
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define dbg(x) cout<<#x<<"="<<x<<endl;
using i64 = long long;
using i128 = __int128;
using ld = long double;
using u64 = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
constexpr i64 INF = 1e18;
constexpr int MOD = 1e9+7;
constexpr int MAXX = 2e5+10, LIMIT = 20;
constexpr ld eps = 1e-6;
const ld PI = acos(-1);
constexpr int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
constexpr int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};
struct WEdge {int v;i64 w = 0;};struct DEdge {int u, v;i64 w = 0;};struct Edge {int v;};




class Hash{
private:
    static u64 mix(u64 x){
        // SplitMix64 finalizer：雪崩扰动
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    static u64 seed(){
        static const u64 s = chrono::steady_clock::now().time_since_epoch().count();
        return s;
    }
public:
    //整数
    template <class T> requires is_integral_v<T>
    size_t operator()(T x) const{
        return mix(static_cast<u64>(x) + seed());
    }
    //pair
    template <class A, class B>
    size_t operator()(const pair<A, B>& x) const{
        u64 h1 = (*this)(x.first);
        u64 h2 = (*this)(x.second);
        return mix(h1 ^ (h2 << 1));
    }
    //tuple<A, B, C>
    template <class A, class B, class C>
    size_t operator()(const tuple<A, B, C>& x) const{
        u64 h1 = (*this)(get<0>(x));
        u64 h2 = (*this)(get<1>(x));
        u64 h3 = (*this)(get<2>(x));
        return mix(h1 ^ (h2 << 1) ^ (h3 << 2));
    }
    //array
    template <class T, size_t N>
    size_t operator()(const array<T, N>& x) const{
        u64 h = seed();
        for (const auto& v : x) {
            h = mix(h ^ (*this)(v));
        }
        return h;
    }
};

inline void solve() {
    int n, k, s, t; cin >> n >> k >> s >> t;
    vector<int> x(n + 1);
    vector<vector<pii>> mp(n + 1);
    rep(i, 1, n) cin >> x[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int m; cin >> m;
        while(m--) {
            int c, w; cin >> c >> w;
            mp[i].push_back({c, w});
            cnt++;
        }
    }
    vector<int> ch(k + 1);
    unordered_map<pii, int, Hash> pre, suf;
    for(int i = 1; i <= n; i++) {
        for(const auto &[c, w] : mp[i]) {
            if(ch[c] != 0) {
                pre[{i, c}] = ch[c];
            }
            ch[c] = i;
        }
    }
    ch.assign(k + 1, n + 1);
    for(int i = n; i >= 1; i--) {
        for(const auto & [c, w] : mp[i]) {
            if(ch[c] != n + 1) {
                suf[{i, c}] = ch[c];
            }
            ch[c] = i;
        }
    }
    unordered_map<pii, int, Hash> dis;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
    for(const auto &[c, w] : mp[s]) {
        dis[{s, c}] = w;
        q.push({w, s, c});
    }
    while(!q.empty()) {
        auto [d, u, f] = q.top(); q.pop();
        auto it1 = dis.find({u, f});
        if(it1 == dis.end() or it1->second != d) continue;
        if(u > cnt) {
            int pos = u - cnt;
            for(const auto &[c, w] : mp[pos]) {
                int nd = d + w;
                auto itt = dis.find({pos, c});
                if(itt == dis.end() or nd < itt->second) {
                    dis[{pos, c}] = nd;
                    q.push({nd, pos, c});
                }
            }
            continue;
        }
        int v = u + cnt;
        auto hub = dis.find({v, 0});
        if(hub == dis.end() or d < hub->second) {
            dis[{v, 0}] = d;
            q.push({d, v, 0});
        }
        auto it = pre.find({u, f});
        if(it != pre.end()) {
            int v = it->second;
            int nd = d + abs(x[v] - x[u]);
            auto it2 = dis.find({v, f});
            if(it2 == dis.end() or nd < it2->second) {
                dis[{v, f}] = nd;
                q.push({nd, v, f});
            }
        }
        it = suf.find({u, f});
        if(it != suf.end()) {
            int v = it->second;
            int nd = d + abs(x[v] - x[u]);
            auto it2 = dis.find({v, f});
            if(it2 == dis.end() or nd < it2->second) {
                dis[{v, f}] = nd;
                q.push({nd, v, f});
            }
        }
    }
    int ans = INF;
    for(const auto &[c, w] : mp[t]) {
        auto it = dis.find({t, c});
        if(it != dis.end()) {
            ans = min(ans, it->second);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        
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