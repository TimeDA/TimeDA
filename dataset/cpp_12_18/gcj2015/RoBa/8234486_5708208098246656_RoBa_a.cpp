#include <cstdio>
 
 const int MAXN = 110;
 char buf[MAXN][MAXN];
 int R, C;
 const int dir[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
 
 int check(int i, int j, int d) {
 	i += dir[d][0];
 	j += dir[d][1];
 	while (i >= 0 && i < R && j >= 0 && j < C) {
 		if (buf[i][j] != '.') return 1;
 		i += dir[d][0];
 		j += dir[d][1];
 	}
 	return 0;
 }
 
 int main() {
 	int T, ca;
 	scanf("%d",&T);
 	for (int ca = 1 ; ca <= T ; ++ca) {
 		scanf("%d%d",&R,&C);
 		for (int i = 0 ; i < R ; ++i) {
 			scanf("%s", buf[i]);
 		}
 		int ans = 0, fail = 0;
 		for (int i = 0 ; i < R ; ++i)
 			for (int j = 0 ; j < C ; ++j) {
 				if (buf[i][j] == '.') continue;
 				int d;
 				switch (buf[i][j]) {
 					case '^': d = 0; break;
 					case '>': d = 1; break;
 					case 'v': d = 2; break;
 					case '<': d = 3; break;
 				}
 				if (!check(i, j, d)) {
 					// printf("i:%d j:%d d:%d %c\n", i, j, d, buf[i][j]);
 					int flg = 0;
 					for (int td = 0 ; td < 4 ; ++td)
 						if (check(i, j, td)) {flg = 1; break;}
 					if (flg) ++ans;
 					else {fail = 1; break;}
 				}
 			}
 		printf("Case #%d: ", ca);
 		if (fail) printf("IMPOSSIBLE\n");
 		else printf("%d\n", ans);
 	}
 	return 0;
 }