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

const int maxN = 1100;
int r, b, c;
long long m[maxN], s[maxN], p[maxN];
long long cnt[maxN];

bool check(long long t) {
    for (int i = 0; i < c; ++i) {
        if (t < p[i]) {
            cnt[i] = 0;
        } else {
            cnt[i] = min(m[i], (t - p[i]) / s[i]);
        }
    }
    sort(cnt, cnt + c);
    reverse(cnt, cnt + c);

    long long total = 0;
    for (int i = 0; i < r; ++i) {
        total += cnt[i];
    }
    return total >= (long long)(b);
}

void solve(int test) {
    cin >> r >> b >> c;
    for (int i = 0; i < c; ++i) {
        cin >> m[i] >> s[i] >> p[i];
    }

    long long l = 0, r = 3000000000000000000LL;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    long long res = r;
    if (check(l)) {
        res = l;
    }
    printf("Case #%d: ", test);
    cout << res << endl;
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