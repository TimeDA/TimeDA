#include <algorithm>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		int N;
 		scanf("%d", &N);
 		vector<int> a(N, 0);
 		vector<pair<int, int> > vp;
 		for (int i = 0; i < N - 1; ++i) {
 			int m;
 			scanf("%d", &m);
 			vp.push_back(make_pair(i + 1, m));
 			int x = 0;
 			for (int j = m - 2; j >= i + 1; --j) {
 				x++;
 				a[j] -= x;
 			}
 		}
 		bool impos = false;
 		for (int i = 0; i < N - 1; ++i)
 			for (int j = i + 1; j < N - 1; ++j) {
 				if (vp[i].second < vp[j].second && vp[i].second > vp[j].first) {
 					impos = true;
 				}
 			}
 		if (impos) {
 			printf("Case #%d: Impossible\n", cn);
 			continue;
 		} else {
 			int min = 0;
 			for (int i = 0; i < N; ++i)
 				if (min > a[i]) min = a[i];
 			printf("Case #%d:", cn);
 			for (int i = 0; i < N; ++i) {
 				printf(" %d", a[i] - min);
 			}
 			printf("\n");
 		}
 	}
 }
