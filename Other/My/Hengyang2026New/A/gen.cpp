#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nL = 1, nR = 200000;
    int mL = 1, mR = 200000;

    ensuref(1 <= nL && nL <= nR && nR <= 200000, "Invalid n range");
    ensuref(1 <= mL && mL <= mR && mR <= 200000, "Invalid m range");

    int n = rnd.next(nL, nR);
    int m = rnd.next(mL, mR);

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; ++i) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);

        cout << l << ' ' << r << '\n';
    }

    return 0;
}