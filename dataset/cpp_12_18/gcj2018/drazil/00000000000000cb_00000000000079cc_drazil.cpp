#include <bits/stdc++.h>

using namespace std;

const long double pi = 2 * acos(0.0);
const long double eps = 1e-16;
const long double p = sqrt(2);

long double area(long double th) {
    th += pi / 4;
    return p * fabs(sin(th));
}

void pp(long double th) {
    long double a, b;
    a = cos(th) / 2;
    b = sin(th) / 2;
    printf("%.16f %.16f 0\n", (double)a, (double)b);
}

void print(long double th) {
    pp(th);
    th += pi / 2;
    pp(th);
    puts("0 0 0.5");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        long double L = 0, R = pi / 2;
        double a;
        scanf("%lf", &a);
        long double aa = a;
        int r = 100;
        while (R - L > eps && r--) {
            double m = (R + L) / 2;
            if (area(m) < aa) L = m;
            else R = m;
        }
        printf("Case #%d:\n", t);
        print((L + R) / 2);
    }

    return 0;
}
