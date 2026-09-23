#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500000, "m");
    inf.readEoln();
    for(int i = 0; i < m; i++) {
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        int r = inf.readInt(l, n, "r");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
