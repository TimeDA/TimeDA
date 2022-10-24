
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
using namespace std;
typedef long long LL;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		LL N, K;
		scanf("%lld %lld", &N, &K);
		map<LL, LL> emp;
		emp[N] = 1;
		LL sol = 0;
		while (1) {
			LL now = emp.rbegin()->first;
			LL cnt = emp[now];
			K -= cnt;
			if (K <= 0) {
				sol = now;
				break;
			}
			emp[(now - 1) / 2] += cnt;
			emp[now / 2] += cnt;
			emp.erase(now);
		}
		static int cs = 1;
		printf("Case #%d: %lld %lld\n", cs++, sol / 2, (sol-1) / 2);
	}
	return 0;
}