#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> son(n + 1), dep(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> ans;
    int ok = 1;
    auto dfs = [&](auto &&self, int u, int f)->void {
        son[u] = u;
        dep[u] = dep[f] + 1;
        vector<int> sson;
        for(const auto &v : g[u]) {
            if(v == f) continue;
            self(self, v, u);
            sson.push_back(son[v]);
        }
        sort(sson.begin(), sson.end(), [&](const auto &x, const auto &y) {
            return dep[x] < dep[y];
        });
        if(sson.size() % 2 == 1) {
            for(int i = 0; i + 1 < sson.size(); i += 2) {
                ans.push_back({sson[i], sson[i + 1]});
            }
            if(u == 1) {
                if(dep[sson.back()] > dep[u] + 1) {
                    ans.push_back({u, sson.back()});
                }
                else {
                    ok = 0;
                    return;
                }
            }
            son[u] = sson.back();
        }
        else if(sson.size()){
            for(int i = 0; i < sson.size() - 2; i += 2) {
                ans.push_back({sson[i], sson[i + 1]});
            }
            if(u == 1) {
                ans.push_back({sson[sson.size() - 2], sson.back()});
                return;
            }
            if(dep[sson.back()] > dep[u] + 1) {
                ans.push_back({u, sson.back()});
                son[u] = sson[sson.size() - 2];
            }
            else {
                ans.push_back({sson[sson.size() - 2], sson.back()});
            }
        }
    };
    dfs(dfs, 1, 0);
    if(!ok) {
        cout << -1 << endl;
    }
    else {
        cout << ans.size() << endl;
        for(auto &[u, v] : ans) {
            cout << u << " " << v << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
