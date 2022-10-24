#include <cstdio>
#include <algorithm>
#include <vector>
#include <cinttypes>

typedef long long ll;

const int LEN = 50;

using namespace std;

ll intPow (ll a, ll b);

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		ll D;
		char P[LEN];
		scanf("%" PRId64 " %s", &D, P);
		// printf("%" PRId64 "\n", intPow(2, 12));

		int beams[LEN];
		fill(beams, beams+LEN, 0);

		int index = 0;
		ll power = 1, damage = 0;
		for (int i=0; P[i] != '\0'; i++) {
			if (P[i] == 'C') {
				index ++;
				power *= 2;
			}
			else if (P[i] == 'S') {
				beams[index] ++;
				damage += power;
			}
		}

		// printf("%lld %lld\n", damage, D);

		int noHacks = 0;
		while (damage > D) {
			int j;
			for (j=LEN-1; j>0; j--) if (beams[j] > 0) break;

			if (j == 0) {
				noHacks = -1;
				break;
			}

			noHacks ++;
			beams[j] --;
			beams[j-1]++;
			damage -= intPow(2, j-1);
		}

		printf("Case #%d: ", iC);
		if (noHacks >= 0)
			printf("%d\n", noHacks);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

ll intPow (ll a, ll b) {
	ll res = 1;
	ll pow = 2;
	while (b > 0) {
		if (b%2 == 1)
			res *= pow;
		b /= 2;
		pow *= pow;
	}
	return res;
}