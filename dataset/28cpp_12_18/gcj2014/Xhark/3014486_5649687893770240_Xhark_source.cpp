#include <stdio.h>
 #include <algorithm>
 using namespace std;
 const long long MOD = 1000000007ll;
 
 int M, N;
 int sol = 0;
 char data[1024][128];
 
 int tr[1024 * 128][26];
 int tcc[1024 * 128];
 bool isLast[1024 * 128];
 int tcnt;
 
 int createNode() {
 	int t = tcnt;
 	for (int i = 0; i < 26; i++) tr[t][i] = -1;
 	tcnt++;
 	tcc[t] = 0;
 	return t;
 }
 
 void insertTree(int t, char *S) {
 	tcc[t] ++;
 
 	if (*S == '\0') {
 		isLast[t] = true;
 		return;
 	}
 
 	int c = (*S) - 'A';
 	
 	int next = tr[t][c];
 	if (next == -1) {
 		next = createNode();
 		tr[t][c] = next;
 	}
 	insertTree(next, S + 1);
 }
 
 long long dyn[1024 * 128][128];
 int nxt[128];
 long long R = 0, RR[1024*128];
 long long Ru[1024 * 128][128];
 long long Comb[128][128];
 long long Perm[128][128];
 void calcSol(int t){
 	int gn = min(tcc[t], N);
 	R += gn;
 	
 	int Acc = 0;
 	RR[t] = 1;
 
 	for (int i = 0; i <= gn; i++) {
 		Ru[t][i] = 1;
 	}
 
 	int xn = 0;
 	for (int c = 0; c < 26; c++){
 		if (c < 26)	{
 			int child = tr[t][c];
 			if (child == -1) continue;
 			int tr = min(N, tcc[child]);
 			xn = max(xn, tr);
 		}
 	}
 
 	for (int c = 0; c < 27; c++){
 		int Bcc = 0;
 		long long Rmult = 0;
 		if (c < 26)	{
 			int child = tr[t][c];
 			if (child == -1) continue;
 			calcSol(child);
 			Bcc = min(N, tcc[child]);
 			Rmult = RR[child];
 		}
 		else {
 			Rmult = 1;
 			if (isLast[t]) {
 				Bcc = 1;
 			}
 			else {
 				continue;
 			}
 		}
 
 		for (int i = xn; i <= gn; i++) {
 			Ru[t][i] *= Comb[i][Bcc];
 			Ru[t][i] %= MOD;
 			Ru[t][i] *= Rmult;
 			Ru[t][i] %= MOD;
 		}
 	}
 	for (int i = xn; i <= gn; i++) {
 		for (int j = xn; j < i; j++) {
 			long long mi = (Ru[t][j] * Comb[i][j]) % MOD;
 			Ru[t][i] = (Ru[t][i] - mi + MOD) % MOD;
 		}
 	}
 	RR[t] = Ru[t][gn];
 	if (RR[t] > 999999) {
 		t = t;
 	}
 
 }
 int main() {
 	memset(Comb, 0, sizeof(Comb));
 	for (int i = 0; i < 128; i++) {
 		Comb[i][0] = 1;
 		for (int j = 1; j <= i; j++) {
 			Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
 		}
 	}
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("D-small-attempt1.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int t = 1; t <= T; t++) {
 		memset(tcc, 0, sizeof(tcc));
 		memset(dyn, 0, sizeof(dyn));
 		memset(RR, 0, sizeof(RR));
 		memset(isLast, 0, sizeof(isLast));
 		memset(Ru, 0, sizeof(Ru));
 		scanf("%d %d", &M, &N);
 		tcnt = 0;
 		int root = createNode();
 		for (int i = 0; i < M; i++) {
 			scanf("%s", data[i]);
 			insertTree(root, data[i]);
 		}
 		R = 0;
 		calcSol(root);
 		printf("Case #%d: %lld %lld\n", t, R, RR[root]);
 	}
 	return 0;
 }