#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 #include <string>
 using namespace std;
 
 string best[20][3];
 char f[] = {'P','R','S'};
 void main2 () {
 	int P, R, S;
 	int N;
 	scanf("%d %d %d %d",&N,&R,&P,&S);
 	for (int i=0;i<3;++i) best[0][i] = f[i];
 	for (int h=1;h<=N;++h) for (int i=0;i<3;++i) {
 		int a = i, b = (i+1)%3;
 		if (best[h-1][a] < best[h-1][b]) best[h][i] = best[h-1][a] + best[h-1][b];
 		else best[h][i] = best[h-1][b] + best[h-1][a];
 	}
 	string ans = "";
 	for (int i=0;i<3;++i) {
 		int A = P, B = R, C = S;
 		for (int j=0;j<(1<<N);++j) {
 			if (best[N][i][j] == 'P') --A;
 			else if (best[N][i][j] == 'R') --B;
 			else --C;
 		}
 		if (A == 0 && B == 0 && C == 0) {
 			if (ans == "" || ans > best[N][i]) ans = best[N][i];
 		}
 	}
 	if (ans == "") printf("IMPOSSIBLE\n");
 	else printf("%s\n",ans.c_str());
 	return;
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
