#include <bits/stdc++.h>
 
 using namespace std;
 
 char arr[10][110];
 int dpt[50][500];
 int pre[50][500];
 
 int checked[10][110][2]; //0 not check 1 ok 2 failed
 int R, C;
 
 bool check(int r, int c, char type) {
 	int tid = 1;
 	if (type == '|') tid = 0;
 	if (checked[r][c][tid] == 0) {
 		checked[r][c][tid] = 1;
 		if (tid == 0) {
 			for (int i = 1; i + r < R; ++i) {
 				if (arr[i + r][c] == '|' || arr[i + r][c] == '-') checked[r][c][tid] = 2;
 				else if(arr[i + r][c] == '#') break;
 			}
 			for (int i = 1; r - i >= 0; ++i) {
 				if (arr[r - i][c] == '|' || arr[r - i][c] == '-') checked[r][c][tid] = 2;
 				else if(arr[r - i][c] == '#') break;
 			}
 		} else {
 			for (int i = 1; i + c < C; ++i) {
 				if (arr[r][c + i] == '|' || arr[r][c + i] == '-') checked[r][c][tid] = 2;
 				else if(arr[r][c + i] == '#') break;
 			}
 			for (int i = 1; c - i >= 0; ++i) {
 				if (arr[r][c - i] == '|' || arr[r][c - i] == '-') checked[r][c][tid] = 2;
 				else if(arr[r][c - i] == '#') break;
 			}
 		}
 		if (checked[r][c][tid] == 1) {
 			//printf("%d %d %d ok\n", r, c, tid);
 		}
 	}
 	return (checked[r][c][tid] == 1);
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		memset(dpt, 0xff, sizeof(dpt));
 		memset(checked, 0, sizeof(checked));
 		int r, c;
 		scanf("%d%d", &r, &c);
 		R = r;
 		C = c;
 		int max_state = 1;
 		int max_conf = 1;
 		for (int i = 0; i < r; ++i) {
 			max_state *= 3;
 			max_conf *= 2;
 		}
 		for (int i = 0; i < r; ++i) scanf("%s", arr[i]);
 		for (int cc = 0; cc < c; ++cc) {
 			for (int conf = 0; conf < max_conf; ++conf) {
 				//valid conf
 				char tmp[10];
 				int tconf = conf;
 				for (int i = 0; i < r; ++i) {
 					tmp[i] = (tconf & 1) == 0 ? '|' : '-';
 					tconf >>= 1;
 				}
 				bool isValid = true;
 				for (int i = 0; i < r; ++i) {
 					if (arr[i][cc] == '|' || arr[i][cc] == '-') {
 						if (!check(i, cc, tmp[i])) isValid = false;
 					}
 				}
 				//printf("c: %d config %d no ok %c\n", cc, conf, tmp[1]);
 				if (!isValid) continue;
 				//printf("c: %d config %d ok\n", cc, conf);
 				for (int s = 0; s < max_state; ++s) {
 					int curs[10];
 					if (cc == 0 && s > 0) break;
 					if (cc > 0 && dpt[cc - 1][s] == -1) continue;
 					int pres[10];
 					int sss = s;
 					for (int i = 0; i < r; ++i) {
 						pres[i] = sss % 3;
 						sss /= 3;
 					}
 					for (int i = 0; i < r; ++i) {
 						if (pres[i] == 0) curs[i] = -1;
 						else if (pres[i] == 1) curs[i] = 1;
 						else if (pres[i] == 2) curs[i] = 2;
 					}
 					for (int i = 0; i < r; ++i) {
 						if (arr[i][cc] == '#') {
 							if (curs[i] == 2) isValid = false;
 							else curs[i] = 0;
 						} else if(arr[i][cc] == '.') {
 						} else {
 							if (tmp[i] == '-') curs[i] = 1;
 							else {
 								if (curs[i] == 2) isValid = false;
 								curs[i] = 0;
 								for (int di = 1; i + di < r; ++di) {
 									if (arr[i + di][cc] == '#') break;
 									if (curs[i + di] == -1) curs[i + di] = 0;
 								}
 								for (int di = 1; i - di >= 0; ++di) {
 									if (arr[i - di][cc] == '#') break;
 									if (curs[i - di] == -1) curs[i - di] = 0;
 								}
 							}
 						}
 					}
 					int cs = 0;
 					for (int i = r - 1; i >= 0; i--) {
 						if (curs[i] == -1) curs[i] = 2;
 						cs = cs * 3 + curs[i];
 					}
 					if (isValid) {
 						//printf("c: %d, cs: %d, conf: %d\n", cc, cs, conf);
 						dpt[cc][cs] = conf;
 						pre[cc][cs] = s;
 					}
 				}
 			}
 		}
 		int anss = -1;
 		for (int s = 0; s < max_state; ++s) {
 			int curs[10];
 			int ss = s;
 			for (int i = 0; i < r; ++i) {
 				curs[i] = ss % 3;
 				ss /= 3;
 			}
 			bool isOK = true;
 			for (int i = 0; i < r; ++i) {
 				if (curs[i] == 2) isOK = false;
 			}
 			if (isOK && dpt[c - 1][s] != -1) {
 				anss = s;	
 				break;
 			}
 		}
 		if (anss == -1) printf("Case #%d: IMPOSSIBLE\n", t);
 		else {
 			printf("Case #%d: POSSIBLE\n", t);
 			int curs = anss;
 			for (int i = c - 1; i >= 0; --i) {
 				int conf = dpt[i][curs];
 				curs = pre[i][curs];
 				char tmp[10];
 				for (int j = 0; j < r; ++j) {
 					tmp[j] = (conf & 1) == 0 ? '|' : '-';
 					conf >>= 1;
 				}
 				for (int j = 0; j < r; ++j) {
 					if (arr[j][i] == '|' || arr[j][i] == '-') arr[j][i] = tmp[j];
 				}
 			}
 			for (int i = 0; i < r; ++i) puts(arr[i]);
 		}
 	}
 	return 0;
 }
 
