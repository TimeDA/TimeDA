
 #pragma warning(disable:4996)
 #pragma comment(linker, "/STACK:36777216")
 #include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <memory.h>
 using namespace std;
 int N, C, M;
 const int MAX_N = 1024;
 vector<int> cus[MAX_N];
 int cnt[MAX_N];
 int main() {
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	while (T-- > 0) {
 		static int cs = 1;
 		scanf("%d %d %d", &N, &C, &M);
 		for (int i = 0; i < C; i++) cus[i].clear();
 		for (int i = 0; i < M; i++) {
 			int P, B;
 			scanf("%d %d", &P, &B);
 			P--; B--;
 			cus[B].push_back(P);
 		}
 		memset(cnt, 0, sizeof(cnt));
 		int mx = 0, mxp = 0;
 
 		int sol1 = 0, sol2 = 0;
 		for (int i = 0; i < C; i++) {
 			sol1 = max(sol1, (int)cus[i].size());
 			for (int p : cus[i]) {
 				cnt[p] ++;
 				if (cnt[p] >= mx) {
 					mx = cnt[p];
 					mxp = p;
 				}
 			}
 		}
 		if (mx > sol1) {
 			if (mxp == 0) {
 				sol1 = mx;
 			}
 			else {
 				sol2 = mx - sol1;
 			}
 		}
 
 		for (int i = 0; i < C; i++) cus[i].clear();
 
 		printf("Case #%d: %d %d\n", cs++, sol1, sol2);
 	}
 	return 0;
 }