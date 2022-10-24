#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 ll bits(ll n, ll start, ll len) {
 	return (n>>start) & ((1LL << len)-1);
 }
 
 bool recDefine(char ** house, int r, int c, int i=0, int j=0) {
 	int nextI = i+1, nextJ = j;
 	if (nextI >= r) {
 		nextI = 0;
 		nextJ ++;
 	}
 
 	// printf("%d %d\n", i, j);
 
 	if (j == c)
 		return true;
 
 	if (house[i][j] == '#' or house[i][j] == '-' or house[i][j] == '|' or house[i][j] == '+')
 		return recDefine(house, r, c, nextI, nextJ);
 
 	// We need to cover this point either horizontally or vertically
 
 	// Vertical
 	{
 		int foundPos = -1;
 		for (int ii = i; ii<r; ii++) {
 			// printf("%d %d %c\n", ii, j, house[ii][j]);
 			if (house[ii][j] == '#')
 				break;
 			if (house[ii][j] == '|' or house[ii][j] == '+') {
 				foundPos = ii;
 				break;
 			}
 		}
 		for (int ii = i; ii>=0; ii--) {
 			if (house[ii][j] == '#')
 				break;
 			if (house[ii][j] == '|' or house[ii][j] == '+') {
 				foundPos = ii;
 				break;
 			}
 		}
 
 		// printf("%d\n", foundPos);
 
 		if (foundPos == -1) {}
 		else if (house[foundPos][j] == '|') {
 			if (recDefine(house, r, c, nextI, nextJ))
 				return true;
 		}
 		else if (house[foundPos][j] == '+') {
 			house[foundPos][j] = '|';
 			if (recDefine(house, r, c, nextI, nextJ))
 				return true;
 			house[foundPos][j] = '+';
 		}
 	}
 
 
 	// Horizontal
 	{
 		int foundPos = -1;
 		for (int jj = j; jj<c; jj++) {
 			if (house[i][jj] == '#')
 				break;
 			if (house[i][jj] == '-' or house[i][jj] == '+') {
 				foundPos = jj;
 				break;
 			}
 		}
 		for (int jj = j; jj>=0; jj--) {
 			if (house[i][jj] == '#')
 				break;
 			if (house[i][jj] == '-' or house[i][jj] == '+') {
 				foundPos = jj;
 				break;
 			}
 		}
 
 		if (foundPos == -1) {}
 		else if (house[i][foundPos] == '-') {
 			if (recDefine(house, r, c, nextI, nextJ))
 				return true;
 		}
 		else if (house[i][foundPos] == '+') {
 			house[i][foundPos] = '-';
 			if (recDefine(house, r, c, nextI, nextJ))
 				return true;
 			house[i][foundPos] = '+';
 		}
 	}
 	return false;
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int r,c;
 		scanf("%d %d", &r, &c);
 
 		char * house[r];
 		char  _house[r*(c+10)];
 		for (int i=0; i<r; i++) {
 			house[i] = &_house[i*(c+10)];
 			scanf("%s", house[i]);
 		}
 
 		bool fail = false;
 
 
 		for (int i=0; i<r; i++) {
 			for (int j=0; j<c; j++) {
 				if (house[i][j] == '-' or house[i][j] == '|')
 					house[i][j] = '+';
 			}
 		}
 
 		for (int i=0; i<r; i++) {
 			int foundTurret = -1;
 			for (int j=0; j<c; j++) {
 				if (house[i][j] == '+') {
 					if (foundTurret >= 0) {
 						house[i][j] = '|';
 						house[i][foundTurret] = '|';
 					}
 
 					foundTurret = j;
 				}
 				else if (house[i][j] == '#') {
 					foundTurret = -1;
 				}
 			}
 		}
 
 
 
 		for (int j=0; j<c; j++) {
 			int foundTurret = -1;
 			for (int i=0; i<r; i++) {
 				if (house[i][j] == '+' or house[i][j] == '|') {
 					if (foundTurret >= 0) {
 						if (house[i][j] == '|' or house[foundTurret][j] == '|') {
 							fail = true;
 							break;
 						}
 
 						house[i][j] = '-';
 						house[foundTurret][j] = '-';
 					}
 
 					foundTurret = i;
 				}
 				else if (house[i][j] == '#') {
 					foundTurret = -1;
 				}
 			}
 		}
 
 		// int N=(1LL<<(2*r);
 		// int dpTable[c+1][N]; // We'll store the protection status of the cells on the boundary, 
 		// // if such a solution exists, it points to the status on the previous column that enables it
 
 		// for (int j=0; j<=c; j++) {
 		// 	for (int i=0; i<N; i++)
 		// 		dpTable[j][i] = -1;
 		// }
 		// dpTable[0][0] = 0;
 
 		// for (int j=1; j<=c; j++) {
 		// 	int mask = 0;
 
 		// 	for (int l=0; l<r; l++)
 		// 		if (house[l][j] == '#')
 		// 			mask |= (1LL << l);
 
 		// 	for (int i=0; i<N; i++)
 		// 		if (dpTable[j][i] == -1)
 		// 			continue;
 
 		// 		int statusH = 0, statusV = 0;
 
 		// 		for (int l=0; l<r; l++) {
 		// 			if (house[l][j] == '#') {
 
 		// 			}
 		// 			else if ((bits(dpTable[j][i], 2*l, 2)&1) > 0 ) {
 		// 				statusV |= 1<<(2*l);
 		// 				statusH |= 1<<(2*l);
 		// 			}
 		// 			else { // Cell is not covered, we must either pick an horizontal or a vertical one to cover it
 
 		// 			}
 
 		// 		}
 		// 		dpTable[j][i]
 
 		// }
 
 
 		if (!fail and !recDefine(house, r, c))
 			fail = true;
 
 		for (int i=0; i<r; i++) {
 			for (int j=0; j<c; j++) {
 				if (house[i][j] == '+')
 					house[i][j] = '-';
 			}
 		}
 
 		printf("Case #%d: %s\n", iC, fail?"IMPOSSIBLE":"POSSIBLE");
 		if (!fail) {
 			for (int i=0; i<r; i++)
 				printf("%s\n", house[i]);
 		}
 
 	}
 	return 0;
 }