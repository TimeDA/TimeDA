#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int A;
		scanf("%d", &A);

		int len = (A+2)/3;

		bool prepared[3][len];
		bool readyCol[len];
		for (int j=0; j<len; j++) {
			readyCol[j] = false;
			for (int i=0; i<3; i++)
				prepared[i][j] = 0;
		}

		for (int j=0; j<len; j++) {
			if (prepared[0][j] and prepared[1][j] and prepared[2][j])
				readyCol[j] = true;

			while (!readyCol[j]) {
				printf("%d %d\n", 11, 10 + min(j+1, len-2));
				fflush(stdout);

				int rx, ry;
				scanf("%d %d", &rx, &ry);

				if (rx <= 0 and ry <= 0)
					break;

				prepared[rx-10][ry-10] = true;
				if (prepared[0][j] and prepared[1][j] and prepared[2][j])
					readyCol[j] = true;
			}
		}





		// printf("Case #%d: %d\n", iC, 0);
	}
	return 0;
}