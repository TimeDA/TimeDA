#include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 using namespace std;
 
 #include <math.h>
 #include <stdio.h>
 
 char dat[128][128];
 
 map<char, int> di, dj;
 
 int n, m;
 bool isOut(int i, int j, int ii, int jj) {
 	while (1) {
 		i += ii;
 		j += jj;
 
 		if (i < 0 || i >= n || j < 0 || j >= m) return true;
 		if (dat[i][j] != '.') return false;
 	}
 }
 char dirs[5] = "^>v<";
 int proc(int i, int j) {
 	int ni, nj;
 	ni = i; nj = j;
 	char c = dat[i][j];
 	if (c == '.') return 0;
 
 	if (isOut(i, j, di[c], dj[c])) {
 		for (int t = 0; t < 4; t++) {
 			char tc = dirs[t];
 			if (!isOut(i, j, di[tc], dj[tc])) {
 				return 1;
 			}
 		}
 		return -1;
 	}
 	return 0;
 }
 int main(){
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 
 	di['^'] = -1;
 	dj['^'] = 0;
 
 	di['>'] = 0;
 	dj['>'] = 1;
 
 	di['v'] = 1;
 	dj['v'] = 0;
 
 	di['<'] = 0;
 	dj['<'] = -1;
 	for (int cs = 1; cs <= T; cs++) {
 		scanf("%d %d", &n, &m);
 		for (int i = 0; i < n; i++) scanf("%s", dat[i]);
 
 		int sol = 0;
 		bool pos = true;
 		for (int i = 0; i < n; i++) {
 			for (int j = 0; j < m; j++) {
 				int res = proc(i, j);
 				if (res < 0) pos = false;
 				sol += res;
 			}
 		}
 		printf("Case #%d: ", cs);
 		if (!pos) {
 			printf("IMPOSSIBLE");
 		}
 		else {
 			printf("%d", sol);
 		}
 		printf("\n");
 	}
 
 	return 0;
 }