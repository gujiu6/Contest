#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nL = 1, nR = 500000;
    int mL = 1, mR = 500000;

    // 参数：
    // gen nL nR mL mR
    if (argc >= 5) {
        nL = atoi(argv[1]);
        nR = atoi(argv[2]);
        mL = atoi(argv[3]);
        mR = atoi(argv[4]);
    }

    ensuref(1 <= nL && nL <= nR && nR <= 500000, "Invalid n range");
    ensuref(1 <= mL && mL <= mR && mR <= 500000, "Invalid m range");

    int n = rnd.next(nL, nR);
    int m = rnd.next(mL, mR);

    cout << n << ' ' << m << '\n';
    cout << 1 << ' ' << 1 << '\n';
    if(m > 1) {
        cout << n << ' ' << n << '\n';
    }
    for (int i = 0; i < m - 2; ++i) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);

        cout << l << ' ' << r << '\n';
    }

    return 0;
}