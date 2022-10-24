#include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		int N;
 		scanf("%d", &N);
 		vector<int> P(N), L(N);
 		for (int i = 0; i < N; ++i) {
 			scanf("%d%d", &P[i], &L[i]);
 		}
 		int D;
 		scanf("%d", &D);
 		vector<int> A(N);
 		bool isok = false;
 		A[0] = P[0];
 		for (int i = 0; i < N; ++i) {
 			if (P[i] + A[i] >= D) isok = true;
 			for (int j = i + 1; j < N; ++j) {
 				if (P[i] + A[i] >= P[j]) {
 					A[j] = max(A[j], min(P[j] - P[i], L[j]));
 				} else {
 					break;
 				}
 			}
 		}
 		printf("Case #%d: ", cn);
 		if (isok) printf("YES\n"); else printf("NO\n");
 	}
 }
 
