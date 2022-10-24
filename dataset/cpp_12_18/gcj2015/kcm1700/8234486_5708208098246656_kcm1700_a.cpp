#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 char dat[128][128];
 
 int main()
 {
 	int TT;
 	scanf("%d", &TT);
 	for (int testcase = 1; testcase <= TT; testcase++)
 	{
 		int n, m;
 		scanf("%d%d", &n,&m);
 		for (int i = 0; i < n; i++) {
 			scanf("%s", dat[i]);
 		}
 		int ans = 0;
 		bool imp = false;
 		for (int i = 0; i < n; i++) {
 			for (int j = 0; j < m; j++) {
 				if (dat[i][j] == '.') continue;
 				const int dir[4][2] = { 0, -1, 0, 1, -1, 0, 1, 0 };
 				bool ok[4] = { false, false, false, false };
 				for (int k = 0; k < 4; k++) {
 					int nr = i;
 					int nc = j;
 					bool met = false;
 					for (int l = 0;; l++){
 						nr += dir[k][0];
 						nc += dir[k][1];
 						if (nr < 0 || nc < 0 || nr >= n || nc >= m) break;
 						if (dat[nr][nc] != '.') {
 							met = true;
 							break;
 						}
 					}
 					ok[k] = met;
 				}
 				switch (dat[i][j]) {
 				case '<':
 					if (ok[0]) break;
 					else if (ok[1] || ok[2] || ok[3]) ans++;
 					else imp = true;
 					break;
 				case '>':
 					if (ok[1]) break;
 					else if (ok[0] || ok[2] || ok[3]) ans++;
 					else imp = true;
 					break;
 				case '^':
 					if (ok[2]) break;
 					else if (ok[1] || ok[0] || ok[3]) ans++;
 					else imp = true;
 					break;
 				case 'v':
 					if (ok[3]) break;
 					else if (ok[1] || ok[2] || ok[0]) ans++;
 					else imp = true;
 					break;
 				}
 			}
 		}
 		if (imp) {
 			printf("Case #%d: IMPOSSIBLE\n", testcase);
 		}
 		else {
 			printf("Case #%d: %d\n", testcase, ans);
 		}
 	}
 	return 0;
 }