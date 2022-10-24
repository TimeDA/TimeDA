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

const long long inf = 1000000000000000000LL;

long long damage(const string &s) {
    long long res = 0;
    long long p = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'C') {
            p = min(p + p, inf);
        } else {
            res = min(res + p, inf);
        }
    }
    return res;
}

void solve(int test) {
    long long D;
    string s;
    cin >> D >> s;
    int n = s.size();

    int res = 0;
    while (true) {
        long long current = damage(s);
        if (current <= D) {
            break;
        }

        int index = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == 'C' && s[i + 1] == 'S') {
                index = i;
                break;
            }
        }
        if (index == -1) {
            break;
        }
        swap(s[index], s[index + 1]);
        ++res;
    }

    if (damage(s) <= D) {
        printf("Case #%d: %d\n", test, res);
    } else {
        printf("Case #%d: IMPOSSIBLE\n", test);
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