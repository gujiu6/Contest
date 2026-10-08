#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin >> s;
    auto it = s.find('f');
    int ans = 0;
    string t = "fjcpc";
    while(it != -1) {
        int j = 0;
        s = s.substr(it);
        while(j < s.size() && s[j] == t[j]) j++;
        if(j >= t.size()) ans ++;
        s = s.substr(1);
        it = s.find('f');
    }
    cout << ans << endl;
}