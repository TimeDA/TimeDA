#include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 using namespace std;
 
 #include <math.h>
 #include <stdio.h>
 const int MOD = 1000000009;
 
 int d[6][6];
 int R, C;
 
 int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
 bool check(int a, int b){
 	int c = 0;
 	for (int z = 0; z < 4; z++) {
 		int ta = a + dir[z][0];
 		int tb = b + dir[z][1];
 
 		if (ta < 0) continue;
 		if (ta >= R) continue;
 
 		if (tb < 0) tb += C;
 		if (tb >= C) tb -= C;
 
 		if (d[a][b] == d[ta][tb]) c++;
 	}
 	return d[a][b] == c;
 }
 
 bool overcheck(int a, int b){
 	if (a < 0 || a >= R) return true;
 	if (b < 0) b += C;
 	if (b >= C) b -= C;
 
 	if (d[a][b] == 0) return true;
 	int c = 0;
 	for (int z = 0; z < 4; z++) {
 		int ta = a + dir[z][0];
 		int tb = b + dir[z][1];
 
 		if (ta < 0) continue;
 		if (ta >= R) continue;
 
 		if (tb < 0) tb += C;
 		if (tb >= C) tb -= C;
 
 		if (d[a][b] == d[ta][tb]) c++;
 	}
 	return d[a][b] >= c;
 }
 int cnt = 0;
 int backc[101];
 void back(int a, int b) {
 	if (a >= R) {
 		bool valid = true;
 		for (int i = 0; i < R; i++) {
 			for (int j = 0; j < C; j++) {
 				if (!check(i, j)) {
 					valid = false;
 					break;
 				}
 			}
 			if (!valid) break;
 		}
 		if (valid) {
 			int cc = 1;
 			for (int p = 0; p < C; p++) {
 				bool diff = false;
 				for (int i = 0; i < R; i++){
 					for (int j = 0; j < C; j++) {
 						int tj = (j + p) % C;
 						if (d[i][j] != d[i][tj]) diff = true;
 					}
 				}
 				if (diff) cc++;
 			}
 			backc[cc] ++;
 		}
 		return;
 	}
 	if (b >= C) {
 		back(a + 1, 0);
 		return;
 	}
 	for (int i = 1; i <= 3; i++) {
 		d[a][b] = i;
 		if (!overcheck(a - 1, b) || !overcheck(a, b - 1) || !overcheck(a, b)) {
 			continue;
 		}
 		back(a, b + 1);
 		d[a][b] = 0;
 	}
 }
 
 
 typedef long long LL;
 int dyn[102][52][52][52][2];
 void add(int i, int j, int k,int p, int l, int d) {
 	if (i > R || j > 50 || k > 50 || p > 50) return;
 	dyn[i][j][k][p][l] += d;
 	dyn[i][j][k][p][l] %= MOD;
 }
 
 LL pow3[1001], pow2[1001];
 LL mult(int j, int k, int p) {
 	int a2, a3;
 	a3 = j + p;
 	a2 = k*2 + p;
 
 	if (k > 0) {
 		a2 -= 2;
 	}
 	else if (p > 0) {
 		a2--;
 	}
 
 	if (j + p > 0) {
 		a3--;
 	}
 
 	return (pow2[a2] * pow3[a3]) % MOD;
 }
 int main(){
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("D-small-attempt1.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	pow3[0] = 1;
 	pow2[0] = 1;
 	for (int i = 1; i <= 1000; i++) {
 		pow3[i] = (pow3[i - 1] * 3) % MOD;
 		pow2[i] = (pow2[i - 1] * 2) % MOD;
 	}
 	for (int cs = 1; cs <= T; cs++) {
 		scanf("%d %d", &R, &C);
 		/*
 		memset(backc, 0, sizeof(backc));
 		back(0, 0);
 
 		LL sol = 0;
 		for (int i = 1; i <= C; i++) {
 			if (backc[i] % i != 0){
 				printf("!!");
 			}
 			sol += backc[i] / i;
 		}
 		*/
 		
 		memset(dyn, 0, sizeof(dyn));
 		dyn[0][0][0][0][0] = 1;
 		dyn[0][0][0][0][1] = 1;
 		LL sol = 0;
 		for (int i = 0; i <= R; i++) {
 			for (int j = 0; j <= 50; j++){
 				for (int k = 0; k <= 50; k++) {
 					for (int p = 0; p <= 50; p++) {
 						for (int l = 0; l < 2; l++) {
 							if (dyn[i][j][k][p][l] > 0) {
 								if (l == 0) {
 									add(i + 2, j, k, p, 1, dyn[i][j][k][p][l]);
 								}
 								else if (l == 1) {
 									if (C % 3 == 0) {
 										add(i + 2, j + 1, k, p, 0, dyn[i][j][k][p][l]);
 									}
 									if (C % 4 == 0) {
 										add(i + 3, j, k + 1, p, 0, dyn[i][j][k][p][l]);
 									}
 									if (C % 6 == 0) {
 										add(i + 2, j, k, p + 1, 0, dyn[i][j][k][p][l]);
 									}
 									add(i + 1, j, k, p, 0, dyn[i][j][k][p][l]);
 								}
 
 								if (i == R) {
 									LL a = dyn[i][j][k][p][l];
 									LL b = mult(j, k, p);
 									LL pp = (a*b) % MOD;
 									sol = (sol + pp) % MOD;
 								}
 							}
 						}
 					}
 				}
 			}
 		}
 		
 		printf("Case #%d: %lld\n", cs, sol);
 	}
 
 	return 0;
 }