#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

typedef long long ll;

int ceilDiv(int a, int b) {
	return (a+b-1)/b;
}

using namespace std;

struct needPair {
	int i;
	int need;
};

bool operator< (const needPair & a, const needPair & b) {
	return a.need > b.need;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, l;
		scanf("%d %d", &n, &l);

		int remaining = n;
		int perc = 0;
		
		int C[n];
		for (int i=0; i<l; i++) {
			scanf("%d", &C[i]);
			remaining -= C[i];
			perc += (C[i]*100)/n;
		}

		for (int i=l; i<n; i++)
			C[i] = 0;

		priority_queue<needPair> q;

		int need[n];
		for (int i=0; i<n; i++){
			need[i] = (n+1)/2 - (C[i]*100)%n;
			if (need[i] <= 0) {
				perc += 1;
				need[i] = n + need[i];
			}

			needPair p;
			p.i = i;
			p.need = need[i];
			q.push(p);
			// printf("%d %d\n", i, need[i]);
		}
		// printf("%d\n", remaining);


		while (!q.empty() and remaining*100 >= q.top().need) {
			needPair p = q.top();
			int i = p.i;
			int r = p.need;
			q.pop();

			// printf("%d %d %d\n", i, r, perc);

			if (remaining*100 >= r) {
				int j = ceilDiv(r, 100);

				remaining -= j;
				need[i] = need[i] - j*100;
				// printf("%d %d %d\n", perc, (-need[i])/n, -(-need[i])%n);
				perc += (-need[i])/n;
				need[i] = -(-need[i])%n;

				if (need[i] <= 0) {
					perc += 1;
					need[i] += n;
				}

				p.need = need[i];
				q.push(p);
			}
		}

		printf("Case #%d: %d\n", iC, perc);
	}
	return 0;
}