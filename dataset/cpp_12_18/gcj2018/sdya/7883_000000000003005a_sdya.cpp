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
int r, c, h, v;
string s[maxN];
int rs[maxN], cs[maxN];

int a[maxN], b[maxN];

void solve(int test) {
    cin >> r >> c >> h >> v;
    for (int i = 0; i < r; ++i) {
        cin >> s[i];
    }

    int total = 0;
    for (int i = 0; i < r; ++i) {
        rs[i] = 0;
        for (int j = 0; j < c; ++j) {
            rs[i] += (s[i][j] == '@');
        }
        total += rs[i];
    }
    for (int j = 0; j < c; ++j) {
        cs[j] = 0;
        for (int i = 0; i < r; ++i) {
            cs[j] += (s[i][j] == '@');
        }
    }

    if (total % ((h + 1) * (v + 1)) != 0) {
        printf("Case #%d: IMPOSSIBLE\n", test);
        return;
    }

    int R = total / (h + 1);
    int j = -1, curS = 0;
    for (int i = 0; i < h; ++i) {
        bool found = false;
        while (j < r) {
            //cerr << i << ": " << curS << " " << j << endl;
            if (curS == R) {
                found = true;
                a[i + 1] = j + 1;
                curS = 0;
                break;
            } else {
                ++j;
                curS += rs[j];
            }
        }
        if (!found) {
            printf("Case #%d: IMPOSSIBLE\n", test);
            return;
        }
    }
    a[h + 1] = r;

    //cerr << a[0] << " " << a[1] << " " << a[2] << endl;

    int C = total / (v + 1);
    j = -1, curS = 0;
    for (int i = 0; i < v; ++i) {
        bool found = false;
        while (j < c) {
            if (curS == C) {
                found = true;
                b[i + 1] = j + 1;
                curS = 0;
                break;
            } else {
                ++j;
                curS += cs[j];
            }
        }
        if (!found) {
            printf("Case #%d: IMPOSSIBLE\n", test);
            return;
        }
    }
    b[v + 1] = c;
    //cerr << b[0] << " " << b[1] << " " << b[2] << endl;

    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= v; ++j) {
            int cur = 0;
            for (int k = a[i]; k < a[i + 1]; ++k) {
                for (int l = b[j]; l < b[j + 1]; ++l) {
                    cur += s[k][l] == '@';
                }
            }
            if (cur * (h + 1) * (v + 1) != total) {
                printf("Case #%d: IMPOSSIBLE\n", test);
                return;
            }
        }
    }
    printf("Case #%d: POSSIBLE\n", test);
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