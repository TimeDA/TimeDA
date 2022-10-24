#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
const int maxM = 110000;
int n, p;
int a[maxN], b[maxN];
double c[maxN];

double dp[maxM];

void solve(int test) {
    scanf("%d%d", &n, &p);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        c[i] = 2.0 * sqrt((double)(a[i] * a[i] + b[i] * b[i]));
        res += 2 * (a[i] + b[i]);
    }

    for (int i = 0; i < maxM; ++i) {
        dp[i] = -1e18;
    }
    dp[0] = 0.0;

    for (int i = 0; i < n; ++i) {
        int d = min(a[i], b[i]) * 2;
        for (int j = maxM - 1; j >= 0; --j) {
            if (j + d < maxM) {
                dp[j + d] = max(dp[j + d], dp[j] + c[i]);
            }
        }
    }

    double best = res;
    for (int i = 0; i < maxM; ++i) {
        int L = res + i;
        double R = (double)(res) + dp[i]; 

        if (L > p) {
            continue;
        }
        double buf = min(R, (double)(p));
        best = max(best, buf);
    }
    printf("Case #%d: %.10lf\n", test, best);
}

int main(int argc, char* argv[]) {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		//cerr << i << ": " << clock() << endl;
	}
	return 0;
}