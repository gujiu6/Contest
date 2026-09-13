#include <bits/stdc++.h>
#include <cassert>
//#include <ranges>
using namespace std;
#define ONLINE_JUDGE
#define endl '\n'
// #define int long long
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



//1.快读快写
namespace fast {

template <typename T = i64>
T read(){
    bool flag = false;
    T ans = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') flag = true;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return flag ? -ans : ans;
}
template <typename T = i64>
void write(T x){
    if(x == 0){
        putchar('0');
        return;
    }
    if(x < 0){
        putchar('-');
        x = -x;
    }
    vector<char> ch;
    while(x){
        ch.push_back(x % 10 + '0');
        x /= 10;
    }
    for(int i = ch.size() - 1; i >= 0; i--) {
        putchar(ch[i]);
    }
}

}

//重量Hash(防Hack)
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
    int n = fast::read();
    unordered_map<int, int, Hash> cnt;
    vector<int> small(n + 1);
    for(int i = 1; i <= n; i++) {
        int x = fast::read();
        if(x <= n) small[x]++;
        else cnt[x]++;
    }
    auto get = [&](int x) {
        if(x > n) {
            auto it = cnt.find(x);
            if(it != cnt.end())
                return it->second;
            return 0;
        }
        return small[x];
    };
    int mex = 0;
    while(mex < n && get(mex)) mex++;
    int ans = 0, q = fast::read();
    vector<int> qq(q + 1);
    for(int i = 1; i <= q; i++) {
        qq[i] = fast::read();
    }
    vector<int> v;
    sort(all(qq, 1));
    for(int i = 1; i <= q; ) {
        int j = i;
        while(j <= q && qq[i] == qq[j]) j++;
        if((j - i) & 1) {
            v.push_back(qq[i]);
        }
        i = j;
    }
    for(int x = mex; x < n; x++) {
        vector<int> nxt;
        int cx = get(x);
        for(const auto &k : v) {
            int y = k - x, cy = 0;
            if(y >= 0) {
                cy += get(y);
            }
            int need = (y < 0 || y >= x ? 1 : 2);
            if(cx + cy >= need) {
                nxt.push_back(k);
            }
            else {
                ans ^= x;
            }
        }
        v.swap(nxt);
    }
    if(v.size() & 1) ans ^= n;
    fast::write(ans);
    putchar('\n');


    
    
}







signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    t = fast::read();
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