#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 using namespace std;
 #define MAXN 5
 
 int N;
 char mat[MAXN][MAXN], mat2[MAXN][MAXN];
 bool used[MAXN];
 int perm[MAXN];
 bool bad (int _i) {
 	if (_i == N) return 0;
 	int i = perm[_i];
 	bool found = 0;
 	for (int j=0;j<N;++j) if (mat2[i][j] && !used[j]) {
 		found = 1;
 		used[j] = 1;
 		if (bad(_i+1)) {
 			found = 0;
 			used[j] = 0;
 			break;
 		}
 		used[j] = 0;
 	}
 	return !found;
 }
 
 void main2 () {
 	scanf("%d",&N);
 	for (int i=0;i<N;++i) scanf("%s",mat[i]);
 	int N2 = N * N, best = N2;
 	for (int i=0;i<(1<<N2);++i) {
 		for (int x=0;x<N;++x) for (int y=0;y<N;++y) mat2[x][y] = (mat[x][y] == '1' || (i&(1<<(x*N+y))));
 		for (int j=0;j<N;++j) perm[j] = j;
 		bool ok =1;
 		do {
 			for (int j=0;j<N;++j) used[j] = 0;
 			if (bad(0)) {
 				ok = 0;
 				break;
 			}
 		} while (next_permutation(perm,perm+N));
 		if (ok) best=min(best, __builtin_popcount(i));
 	}
 	printf("%d\n",best);
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
