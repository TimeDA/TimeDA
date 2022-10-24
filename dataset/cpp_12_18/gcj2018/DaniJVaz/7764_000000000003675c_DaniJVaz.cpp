#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

void doMagic(ll *G, int m, int *L, int*R, int i, ll g, bool* visited);

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int m;
		scanf("%d", &m);

		int L[m], R[m];
		for (int i=0; i<m; i++) {
			scanf("%d %d", &L[i], &R[i]);
			L[i]--;
			R[i]--;
		}

		ll Gc[m];
		for (int i=0; i<m; i++)
			scanf("%lld", &Gc[i]);

		ll g = Gc[0]; 
		bool possible = true;
		while (possible) {
			g++;

			ll G[m];
			for (int i=0; i<m; i++)
				G[i] = Gc[i];

			bool visited[m];
			fill(visited, visited+m, false);
			doMagic(G, m, L, R, 0, g, visited);

			for (int i=0; i<m; i++)
				if (G[i] < 0)
					possible = false;
		}

		printf("Case #%d: %lld\n", iC, g-1);
	}
	return 0;
}

void doMagic(ll *G, int m, int *L, int*R, int i, ll g, bool* visited) {
	if (visited[i])
		return;
	visited[i] = true;

	G[L[i]] -= g-G[i];
	G[R[i]] -= g-G[i];
	G[i] = g;

	if (G[L[i]] < 0)
		doMagic(G, m, L, R, L[i], 0, visited);
	if (G[R[i]] < 0)
		doMagic(G, m, L, R, R[i], 0, visited);
}