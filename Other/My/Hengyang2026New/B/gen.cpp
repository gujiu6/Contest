#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int test_id = opt<int>(1, 1);

    int l = 1, r = 5000000;
    if (test_id <= 10) {
        l = 1;
        r = test_id;
    } else if (test_id <= 30) {
        l = 100;
        r = 100000;
    } else if (test_id <= 50) {
        l = 1000000;
        r = 4000000;
    } else {
        l = 4000000;
        r = 5000000;
    }

    ensuref(1 <= l && l <= 5000000, "Invalid l range: %d", l);
    ensuref(l <= r && r <= 5000000, "Invalid r range: %d", r);

    int n = rnd.next(l, r);
    cout << n << "\n";

    return 0;
}