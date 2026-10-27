#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii array<int,2>
#define rrp(i,l,r) for(int i=l;i<=r;i++)
#define prr(i,l,r) for(int i=r;i>=l;i--)
#define dbg(x) {for(auto xxy:x)cout<<xxy<<' ';cout<<'\n';}

tuple<int, int, int> exgcd(int a, int b) {
    if (!b) {
        return {abs(a), a < 0 ? -1 : 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s; s = " " + s;
    // cout << s << endl;
    int a = (x + y) / n, b = (x + y) % n;
    vector<int> cnt(n + 1, a);
    int c = 0, d = 0, e = 0;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (b and i <= b) {
            cnt[i]++;
        }
        if (s[i] == '0') {
            c += cnt[i];
        }
        else if (s[i] == '1') {
            d += cnt[i];
        }
        else {
            e += cnt[i];
            mp[cnt[i]].push_back(i);
        }
    }
    x -= c, y -= d;
    if (x < 0 or y < 0 or x + y != e) {
        cout << -1 << endl;
        return;
    }
    if(mp.size() == 0) {
        cout << s.substr(1) << endl;
        return;
    }
    if(mp.size() == 1) {
        if(mp.find(0) != mp.end()) {
            for(int i = 1; i <= n; i++) {
                cout << ((s[i] == '2') ? '0' : s[i]);
            }
            cout << endl;
            return;
        }
        else {
            auto [val, ve] = *mp.begin();
            if(x % val == 0 and y % val == 0) {
                int n1 = x / val, n2 = y / val;
                for(int i = 0; i < ve.size(); i++) {
                    if(i < n1) {
                        s[ve[i]] = '0';
                    }
                    else {
                        s[ve[i]] = '1';
                    }
                }
                cout << s.substr(1) << endl;
                return;
            }
        }
    }
    else {
        auto [val1, ve1] = *mp.begin();
        auto [val2, ve2] = *next(mp.begin());
        if(val1 == 0) {
            if(x % val2 == 0 and y % val2 == 0) {
                int n1 = x / val2, n2 = y / val2;
                for(int i = 0; i < ve2.size(); i++) {
                    if(i < n1) {
                        s[ve2[i]] = '0';
                    }
                    else {
                        s[ve2[i]] = '1';
                    }
                }
                for(int i = 0; i < ve1.size(); i++) {
                    s[ve1[i]] = '0';
                }
                cout << s.substr(1) << endl;
                return;
            }
        }
        else {
            auto [g, xx, yy] = exgcd(val1, val2);
            if (x % g == 0) {
                xx *= x / g;
                yy *= x / g;
                int p = val2 / g, q = val1 / g;
                int sz1 = ve1.size(), sz2 = ve2.size();
                int l = max((int)ceil((double)(-xx) / p), (int)ceil((double)(yy - sz2) / q));
                int r = min((int)floor((double)(sz1 - xx) / p), (int)floor((double)yy / q));
                if (l <= r) {
                    int xxx = xx + l * p;
                    int yyy = yy - l * q;
                    for (int i = 0; i < ve1.size(); i++) {
                        if (i < xxx) {
                            s[ve1[i]] = '0';
                        } else {
                            s[ve1[i]] = '1';
                        }
                    }
                    for (int i = 0; i < ve2.size(); i++) {
                        if (i < yyy) {
                            s[ve2[i]] = '0';
                        } else {
                            s[ve2[i]] = '1';
                        }
                    }
                    cout << s.substr(1) << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while (t--)solve();
}