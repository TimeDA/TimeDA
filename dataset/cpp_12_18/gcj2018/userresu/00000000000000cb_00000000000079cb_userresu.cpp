#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[100001];
void BS_sort() {
	vector<int> a, b;
	for (int i=1;i<=N;++i) {
		if (i%2 == 1) a.push_back(A[i]);
		else b.push_back(A[i]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for (int i=1;i<=N;++i) {
		if (i%2 == 1) A[i] = a[i/2];
		else A[i] = b[i/2-1];
	}
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		scanf("%d",&N);
		for (int i=1;i<=N;++i) scanf("%d",&A[i]);
		BS_sort();
		int bad = 0;
		for (int i=1;i<N;++i) if (A[i] > A[i+1]) {
			bad = i;
			break;
		}
		printf("Case #%d: ",z);
		if (bad) printf("%d\n",bad-1);
		else printf("OK\n");
	}
	return 0;
}
