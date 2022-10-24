#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int N;
		scanf("%d", &N);
		vector<int> R, C;
		for (int i = 0; i < N; i++) {
			int r, c;
			scanf("%d %d", &r, &c);
			R.push_back(r);
			C.push_back(c);
		}
		sort(R.begin(), R.end());
		sort(C.begin(), C.end());
		int Rc = (R[N - 1] - R[0] + 1) / 2;
		int Cc = (C[N - 1] - C[0] + 1) / 2;
		static int cs = 1;
		printf("Case #%d: %d\n", cs++, max(Rc, Cc));
	}
	return 0;
}