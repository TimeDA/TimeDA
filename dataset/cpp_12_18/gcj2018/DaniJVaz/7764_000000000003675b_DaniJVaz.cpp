#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

const int MAXDIST = 2100000;


int main() {
	int iC=0, nC;
	scanf("%d", &nC);

	int * lookupTable = new int[MAXDIST*2];

	for (iC=1; iC<=nC; iC++) {
		int s;
		scanf("%d", &s);
		
		int D[s], A[s], B[s];
		for (int i=0; i<s; i++) {
			scanf("%d %d %d", &D[i], &A[i], &B[i]);
		}

		// For every i, says the last i' consistent on the A or B signs
		int AE[s], BE[s];

		fill(lookupTable, lookupTable+2*MAXDIST, -1);
		for (int i=0; i<s; i++) {
			int m = D[i] + A[i];
			if (lookupTable[m+MAXDIST] == -1)
				AE[i] = i;
			else
				AE[i] = lookupTable[m+MAXDIST];
			lookupTable[m+MAXDIST] = i;
		}

		fill(lookupTable, lookupTable+2*MAXDIST, -1);
		for (int i=0; i<s; i++) {
			int m = D[i] - B[i];
			if (lookupTable[m+MAXDIST] == -1)
				BE[i] = i;
			else
				BE[i] = lookupTable[m+MAXDIST];
			lookupTable[m+MAXDIST] = i;
		}

		int maxLen = 1, maxCount = s;
		for (int i=0; i<s; i++) {
			int ai1 = i, bi1 = -1;
			int ai2 = -1, bi2 = i;

			for (int j=i+1; j<s; j++) {
				if (AE[j] == ai1) {
					ai1 = j;

					if (BE[j] == bi1)
						bi1 = j;
				}
				else {
					if (bi1 == -1 or BE[j] == bi1) {
						bi1 = j;
					}
					else {
						ai1 = -1;
						bi1 = -1;
					}
				}

				if (BE[j] == bi2) {
					bi2 = j;

					if (AE[j] == ai2)
						ai2 = j;
				}
				else {
					if (ai2 == -1 or AE[j] == ai2) {
						ai2 = j;
					}
					else {
						ai2 = -1;
						bi2 = -1;
					}
				}

				if (ai1 != -1 or bi2 != -1) {
					if (j-i+1 > maxLen) {
						maxLen = j-i+1;
						maxCount = 1;
					}
					else if (j-i+1 == maxLen) {
						maxCount ++;
					}
				}
			}
		}

		printf("Case #%d: %d %d\n", iC, maxLen, maxCount);
	}
	return 0;
}