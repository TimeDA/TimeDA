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

const int maxN = 50;
bool used[maxN][maxN];

void solve(int test) {
    int a;
    cin >> a;

    int n;
    for (int i = 3; i <= 15; ++i) {
        if (i * i >= a) {
            n = i;
            break;
        }
    }

    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j < maxN; ++j) {
            used[i][j] = false;
        }
    }

    int shift = 25;
    while (true) {
        int x = -1, y = -1, cnt = -1;
        for (int i = 1; i + 1 < n; ++i) {
            for (int j = 1; j + 1 < n; ++j) {
                int cur = 0;
                for (int u = -1; u <= 1; ++u) {
                    for (int v = -1; v <= 1; ++v) {
                        if (!used[i + u][j + v]) {
                            ++cur;
                        }
                    }
                }
                if (cur > cnt) {
                    cnt = cur;
                    x = i;
                    y = j;
                }
            }
        }
        cout << shift + x << " " << shift + y << endl;
        int u, v;
        cin >> u >> v;
        if (u == 0 && v == 0) {
            break;
        }
        used[u - shift][v - shift] = true;
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