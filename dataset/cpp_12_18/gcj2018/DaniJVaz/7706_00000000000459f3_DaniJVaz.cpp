#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int DPTable[501][501][502];

int main() {
	int iC=0, nC;
	scanf("%d", &nC);

	/// Pre-compute yay

	int r = 500, b = 500;
	int i, j, l;

	for (i=0; i<=r; i++)
		for (j=0; j<=b; j++)
			for (l = 0; l<=r+1; l++)
				DPTable[i][j][l] = -1;
	DPTable[0][0][0] = 0;
	DPTable[0][0][1] = 0;

	int maxL = 1;
	for (l = 0; l<=maxL; l++) {
		if (l > r+1)
			break;
		for (i=0; i<=r; i++) {
			for (j=0; j<=b; j++) {
				// printf("%d %d %d %d\n", i, j, l, DPTable[i][j][l]);
				if (DPTable[i][j][l] < 0) {
					if (l > 0)
						DPTable[i][j][l] = DPTable[i][j][l-1];
					continue;
				}

				if (l > 0)
					DPTable[i][j][l] = max(DPTable[i][j][l], DPTable[i][j][l-1]);

				int ar = 0, ab = 0;
				int k=0, c=0;
				if (l == 0)
					k = 1;

				while (i+ar <= r and j+ab <= b) {
					ar += l;
					ab += (k++);
					c++;
					if (i+ar <= r and j+ab <= b) {
						// printf("    %d %d %d\n", i+ar, j+ab, c);
						DPTable[i+ar][j+ab][l+1] = max(DPTable[i+ar][j+ab][l+1], DPTable[i][j][l] + c);
						maxL = l+1;
					}
				}
			}
		}
	}

	for (i=0; i<=r; i++)
		for (j=0; j<=b; j++)
			for (l=0; l<=r+1; l++)
				if (DPTable[i][j][l] > DPTable[i][j][i+1])
					DPTable[i][j][i+1] = DPTable[i][j][l];

	for (iC=1; iC<=nC; iC++) {
		scanf("%d %d", &r, &b);

		int maxAchieved = 0;
		for (i=0; i<=r; i++)
			for (j=0; j<=b; j++)
				maxAchieved = max(maxAchieved, DPTable[i][j][i+1]);
		

		printf("Case #%d: %d\n", iC, maxAchieved);


	}
	return 0;
}