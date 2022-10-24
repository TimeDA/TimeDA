#include <cstdio>
#include <cstdlib>
using namespace std;

bool f1[4+1][5+1], f2[10+1][20+1];
int dx[] = {0,1,1,0,-1,-1,-1,0,1}, dy[] = {0,0,1,1,1,0,-1,-1,-1};
bool fill1 (int i,int j) {
	int cnt = 0;
	for (int k=0;k<9;++k) if (f1[i+dx[k]][j+dy[k]]) ++cnt;
	while (cnt < 9) {
		printf("%d %d\n",i,j);
		fflush(stdout);
		int a, b;
		scanf("%d %d",&a,&b);
		if (a == 0) return true;
		if (!f1[a][b]) f1[a][b] = 1, ++cnt;
	}
	return false;
}
bool fill2 (int i,int j) {
	int cnt = 0;
	for (int k=0;k<9;++k) if (f2[i+dx[k]][j+dy[k]]) ++cnt;
	while (cnt < 9) {
		printf("%d %d\n",i,j);
		fflush(stdout);
		int a, b;
		scanf("%d %d",&a,&b);
		if (a == 0) return true;
		if (!f2[a][b]) f2[a][b] = 1, ++cnt;
	}
	return false;
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		int A;
		scanf("%d",&A);
		if (A == 20) {
			for (int i=1;i<=4;++i) for (int j=1;j<=5;++j) f1[i][j] = 0;
			if (fill1(2,2) || fill1(3,2) || fill1(2,4) || fill1(3,4)) continue;
		}
		else {
			for (int i=1;i<=10;++i) for (int j=1;j<=20;++j) f2[i][j] = 0;
			bool solved = 0;
			for (int j=0;j<6;++j) if (fill2(2, 2 + 3 * j) || fill2(4, 2 + 3 * j) || fill2(7, 2 + 3 * j) || fill2(9, 2 + 3 * j)) {
				solved = 1;
				break;
			}
			if (solved) continue;
			if (fill2(2, 19) || fill2(4, 19) || fill2(7, 19) || fill2(9, 19)) continue;
		}
	}
	return 0;
}
