#include <cstdio>
#include <algorithm>
#include <vector>
#include <cinttypes>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);

		ll array[n];
		for (int i=0; i<n; i++)
			scanf("%" PRId64, array+i);

		ll arrayEven[n], arrayOdd[n];
		int countEven = 0, countOdd = 0;
		for (int i=0; i<n; i++) {
			if (i%2 == 0)
				arrayEven[countEven++] = array[i];
			else
				arrayOdd[countOdd++] = array[i];
		}

		sort(arrayEven, arrayEven+countEven);
		sort(arrayOdd, arrayOdd+countOdd);

		for (int i=0; i<countEven; i++)
			array[2*i] = arrayEven[i];

		for (int i=0; i<countOdd; i++)
			array[2*i+1] = arrayOdd[i];

		int badIndex = -1;
		for (int i=0; i<n-1; i++) {
			if (array[i] > array[i+1]) {
				badIndex = i;
				break;
			}
		}

		printf("Case #%d: ", iC);
		if (badIndex < 0)
			printf("OK\n");
		else
			printf("%d\n", badIndex);
	}
	return 0;
}