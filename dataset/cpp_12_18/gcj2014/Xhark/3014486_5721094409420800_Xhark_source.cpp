#include <stdio.h>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 const int MX = 999999999;
 int dat[1001];
 int T, N;
 int main() {
 	freopen("B-small-attempt2.in", "r", stdin);
 	freopen("B-small-attempt2.out", "w", stdout);
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for (int t = 1; t <= T; t++) {
 		scanf("%d", &N);
 		vector<pair<int, int> > D;
 		for (int i = 0; i < N; i++) {
 			scanf("%d", &dat[i]);
 			D.push_back(make_pair(dat[i], i));
 		}
 		sort(D.begin(), D.end());
 
 		int sol = 0;
 		for (int i = 0; i < N; i++) {
 			int sdiff = 0, ediff = 0;
 			for (int j = i + 1; j < N; j++) {
 				if (D[j].second < D[i].second) {
 					sdiff++;
 				}
 				else {
 					ediff++;
 				}
 			}
 			sol += min(sdiff, ediff);
 		}
 
 		printf("Case #%d: %d\n", t, sol);
 	}
 	return 0;
 }