#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int test) {
    int d, n;
    cin >> d >> n;
    vector < int > p(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> s[i];
    } 
    double l = 0.0, r = 1e20;
    for (int i = 0; i < 300; ++i) {
        double m = (l + r) / 2.0;
        bool good = true;
        for (int j = 0; j < n; ++j) {
            double t = (double)(d) / m;
            double pos = (double)(p[j]) + t * (double)(s[j]);
            if (pos < (double)(d)) {
                good = false;
            }
        }
        if (good) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("Case #%d: %.10lf\n", test, l);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    return 0;
}