#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    string s = ouf.readToken();

    if (s == "-1") {
        if (n < 4)
            quitf(_ok, "No solution");
        else
            quitf(_wa, "Solution exists");
    }
    vector<bool> vis(n + 1, 0);
    long long p = stoll(s);
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            p = ouf.readLong();

        if (p < 1 || p > n)
            quitf(_wa, "p[%d] is out of range", i);

        if (vis[p])
            quitf(_wa, "Duplicate value %lld", p);

        if (llabs(p - i) < 2)
            quitf(_wa, "Invalid position %d", i);

        vis[p] = 1;
    }

    ouf.seekEof();

    quitf(_ok, "Valid construction");
}