#include <cmath>
 #include <vector>
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		int N, W, L;
 		scanf("%d%d%d", &N, &W, &L);
 		vector<pair<int, int> > R(N);
 		for (int i = 0; i < N; ++i) {
 			scanf("%d", &R[i].first);
 			R[i].first *= -1;
 			R[i].second = i;
 		}
 		sort(R.begin(), R.end());
 		for (int i = 0; i < N; ++i) R[i].first *= -1;
 		vector<int> X(N), Y(N);
 		int x = 0, y = -R[0].first;
 		int fh = -1;
 		for (int i = 0; i < N; ++i) {
 			if (fh == -1) fh = R[i].first;
 			y = y + R[i].first;
 			if (y > L) {
 				x += fh + R[i].first;
 				y = 0;
 				fh = R[i].first;
 			}
 			X[i] = x, Y[i] = y;
 			y = y + R[i].first;
 		}
 		printf("Case #%d:", cn);
 		for (int i = 0; i < N; ++i) {
 			for (int j = 0; j < N; ++j) {
 				if (i == R[j].second) {
 					printf(" %d %d", X[j], Y[j]);
 				}
 			}
 		}
 		printf("\n");
 	}
 }
