#include <stdio.h>
 #include <memory.h>
 char dat[10002];
 
 class quaternions;
 
 class quaternions {
 public:
 	static quaternions mult[4][4];
 	static void init() {
 		for (int i = 0; i < 4; i++) {
 			mult[0][i].is_negative = false;
 			mult[0][i].num = i;
 
 			mult[i][0] = mult[0][i];
 		}
 
 		for (int i = 1; i <= 3; i++) {
 			mult[i][i].is_negative = true;
 			mult[i][i].num = 0;
 
 			int ni = i % 3 + 1;
 			int nni = ni % 3 + 1;
 			mult[i][ni].is_negative = false;
 			mult[i][ni].num = nni;
 
 			mult[ni][i].is_negative = true;
 			mult[ni][i].num = nni;
 		}
 	}
 	static quaternions getQuaternions(char c) {
 		quaternions res;
 		res.is_negative = false;
 		if (c == '1') res.num = 0;
 		if (c == 'i') res.num = 1;
 		if (c == 'j') res.num = 2;
 		if (c == 'k') res.num = 3;
 		return res;
 	}
 	bool is_negative;
 	int num;
 
 	quaternions operator * (quaternions a) {
 		const quaternions& m = mult[num][a.num];
 		quaternions res;
 		res.is_negative = is_negative ^ a.is_negative ^ m.is_negative;
 		res.num = m.num;
 		return res;
 	}
 };
 quaternions quaternions::mult[4][4];
 bool chk[10004][2][4];
 int main() {
 	quaternions::init();
 	freopen("C-small-attempt1.in", "r", stdin);
 	freopen("C-small-attempt1.out", "w", stdout);
 	int T, L, X;
 	scanf("%d", &T);
 	for (int t = 1; t <= T; t++) {
 		bool sol = false;
 		scanf("%d %d", &L, &X);
 		scanf("%s", dat);
 
 		quaternions mult;
 		mult.is_negative = false;
 		mult.num = 0;
 		for (int i = 0; i < L; i++) {
 			mult = mult * quaternions::getQuaternions(dat[i]);
 		}
 		quaternions pw;
 		pw.is_negative = false;
 		pw.num = 0;
 
 		for (int i = 0; i < X % 4; i++) {
 			pw = pw * mult;
 		}
 		
 
 		if (pw.is_negative && pw.num == 0) { // mult = -1
 			memset(chk, 0, sizeof(chk));
 			quaternions now;
 			now.is_negative = false;
 			now.num = 0;
 
 			int phase = 0; // 0 : find i, 1 : find j 2 : done
 			for (int p = 0; p < L*X; p++) {
 				int i = p % L;
 				now = now * quaternions::getQuaternions(dat[i]);
 				bool& ch = chk[i][now.is_negative][now.num];
 				if (ch) break;
 
 				ch = true;
 				if (phase == 0) {
 					if (!now.is_negative && now.num == 1) {
 						phase++;
 						now.num = 0;
 						now.is_negative = false;
 						memset(chk, 0, sizeof(chk));
 					}
 				}
 				if (phase == 1) {
 					if (!now.is_negative && now.num == 2) {
 						phase++;
 						break;
 					}
 				}
 			}
 			if (phase == 2) {
 				sol = true;
 			}
 		}
 		printf("Case #%d: %s\n", t, sol ? "YES" : "NO");
 	}
 	return 0;
 }