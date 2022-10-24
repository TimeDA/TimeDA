#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);
		
		int counts[n];
		for (int i=0; i<n; i++)
			scanf("%d", counts+i);

		printf("Case #%d: ", iC);

		if (counts[0] == 0  or counts[n-1] == 0) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		int direction[n];
		int k=0; 
		int height = 0;
		for (int i=0; i<n; i++) {
			while (counts[k] == 0) k++;
			direction[i] = k;

			int dist = k-i;
			if (dist < 0) dist = -dist;
			height = max(dist+1, height);

			counts[k] --;
		}

		// fprintf(stderr, "Directions: ");
		// for (int i=0; i<n; i++)
		// 	fprintf(stderr, "%d ", direction[i]);
		// fprintf(stderr, "\n");

		char toy[height][n+1];
		for (int j=0; j<height; j++) {
			for (int i=0; i<n; i++)
				toy[j][i] = '.';
			toy[j][n] = '\0';

			for (int i=0; i<n; i++) {
				if (direction[i] < i) {
					if (i - direction[i] <= j)
						continue;

					toy[j][i-j] = '/';
				}
				else if (direction[i] > i) {
					if (direction[i] - i <= j)
						continue;

					toy[j][i+j] = '\\';
				}
			}
		}

		printf("%d\n", height);
		for (int j=0; j<height; j++)
			printf("%s\n", &toy[j][0]);
	}
	return 0;
}