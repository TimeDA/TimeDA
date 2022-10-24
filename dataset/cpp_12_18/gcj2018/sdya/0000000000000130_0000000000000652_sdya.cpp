#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <bitset>

using namespace std;

map < long long, long long > M;

void solve(int test) {
    M.clear();
	long long n, k;

    cin >> n >> k;
    long long oldk = k;
    M[n] = 1;

    long long len = 0;
    while (k > 0) {
        pair < long long, long long > p = *M.rbegin();

        long long d = min(k, p.second);

        len = p.first;
        
        M[p.first] -= d;
        k -= d;

        M[(p.first - 1) / 2] += d;
        M[p.first / 2] += d;

        if (M[p.first] == 0) {
            M.erase(p.first);
        }
    }
    printf("Case #%d: %lld %lld\n", test, len / 2, (len - 1) / 2);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
	}

	return 0;
}