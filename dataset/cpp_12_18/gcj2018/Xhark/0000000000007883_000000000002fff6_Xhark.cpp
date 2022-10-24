
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_C = 1024;
typedef long long LL;
LL R, B, C;
LL M[MAX_C], S[MAX_C], P[MAX_C];
bool possible(LL t) {
	vector<LL> bit;
	for (int i = 0; i < C; i++) {
		LL pos = (t - P[i]) / S[i];
		if (pos > 0) {
			bit.push_back(min(M[i], pos));
		}
	}
	sort(bit.begin(), bit.end());
	int bn = (int)bit.size();
	LL sum = 0;
	for (int i = 0; i < R && i < bn; i++) {
		sum += bit[bn - 1 - i];
	}
	return (sum >= B);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%lld %lld %lld", &R, &B, &C);
		for (int i = 0; i < C; i++) {
			scanf("%lld %lld %lld", &M[i], &S[i], &P[i]);
		}
		LL s = 1, e = 1;
		
		while (!possible(e)) e = e * 2;
		while (s <= e) {
			LL m = (s + e) / 2;
			if (possible(m)) e = m - 1;
			else s = m + 1;
		}
		static int cs = 1;
		printf("Case #%d: %lld\n", cs++, s);
	}
	return 0;
}