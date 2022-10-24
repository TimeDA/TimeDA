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

const int maxN = 110000;
int n;
int a[maxN], b[maxN], c[maxN];

void solve(int test) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int u = 0, v = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            b[u++] = a[i];
        } else {
            c[v++] = a[i];
        }
    }
    sort(b, b + u);
    sort(c, c + v);
    int res = -1;
    u = v = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a[i] = b[u++];
        } else {
            a[i] = c[v++];
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            res = i;
            break;
        }
    }
    if (res < 0) {
        printf("Case #%d: OK\n", test);
    } else {
        printf("Case #%d: %d\n", test, res);
    }
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