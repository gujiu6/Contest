#include "testlib.h"
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int l = 1, r = 5000000;

    // 参数：
    // gen l r
    if (argc >= 3) {
        l = stoi(argv[1]);
        r = stoi(argv[2]);
    }

    ensuref(1 <= l && l <= 5000000, "Invalid l range");
    ensuref(l <= r && r <= 5000000, "Invalid r range");

    int n = rnd.next(l, r);
    cout << n << endl;

    return 0;
}