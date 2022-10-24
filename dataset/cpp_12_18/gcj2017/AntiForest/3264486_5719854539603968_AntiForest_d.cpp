#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<62)-5)
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
 #define SZ(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int getLDiag (int x, int y) {
     return x+y;
 }
 
 int getRDiag (int x, int y) {
     return y-x+100;
 }
 
 int T, N, M, R, C;
 bool usedRow[205];
 bool usedCol[205];
 bool usedLDiag[305];
 bool usedRDiag[305];
 
 void reset() {
     memset(usedRow, 0, sizeof(usedRow));
     memset(usedCol, 0, sizeof(usedCol));
     memset(usedLDiag, 0, sizeof(usedLDiag));
     memset(usedRDiag, 0, sizeof(usedRDiag));
 }
 
 int main() {
     scanf ("%d", &T);
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         reset();
         scanf ("%d %d", &N, &M);
         R = N;
         C = N;
         char gr[105][105];
         char origGr[105][105];
         FO (i,0,R) {
             FO (j,0,C) {
                 gr[i][j] = origGr[i][j] = '.';
             }
         }
         FO (i,0,M) {
             char typ;
             int cY, cX;
             scanf (" %c %d %d", &typ, &cY, &cX);
             cY--;
             cX--;
             if (typ != '+') {
                 usedRow[cY] = usedCol[cX] = true;
             }
             if (typ != 'x') {
                 usedLDiag[getLDiag(cX,cY)] = usedRDiag[getRDiag(cX,cY)] = true;
             }
             gr[cY][cX] = typ;
             origGr[cY][cX] = typ;
         }
         // rows and cols:
         FO (i,0,R) {
             if (usedRow[i]) continue;
             FO (j,0,C) {
                 if (!usedCol[j]) {
                     usedCol[j] = true;
                     if (gr[i][j] != '.') gr[i][j] = 'o';
                     else gr[i][j] = 'x';
                     break;
                 }
             }
         }
         // diagonals:
         FO (sumD,0,R+C) {
             vector <pair<int,int> > xOrd;
             FO (x,0,sumD+1) {
                 int y = sumD-x;
                 if (x >= C || y >= R || y < 0) continue;
                 xOrd.emplace_back (min(x, y), x);
                 /*
                 if (R-y <= C-x) {
                     xOrd.emplace_back (C-(x+R-y), x);
                 } else {
                     xOrd.emplace_back (R-(y+C-x), x);
                 }
                 */
             }
             sort (xOrd.begin(), xOrd.end());
             for (auto pr : xOrd) {
                 int x = pr.second;
                 int y = sumD-x;
                 int rD = getRDiag(x, y);
                 //printf ("rD: %d Used: %d x:%d y:%d\n", rD, usedRDiag[rD], x, y);
                 if (!usedLDiag[sumD] && !usedRDiag[rD]) {
                     usedLDiag[sumD] = true;
                     usedRDiag[rD] = true;
                     if (gr[y][x] != '.') gr[y][x] = 'o';
                     else gr[y][x] = '+';
                     break;
                 }
             }
         }
         int myScore;
         int modelsAdded;
         myScore = modelsAdded = 0;
         FO (i,0,R) {
             FO (j,0,C) {
                 if (gr[i][j] != origGr[i][j]) {
                     modelsAdded++;
                 }
                 if (gr[i][j] == 'x' || gr[i][j] == '+') myScore++;
                 if (gr[i][j] == 'o') myScore += 2;
             }
         }
         printf ("%d %d\n", myScore, modelsAdded);
         FO (i,0,R) {
             FO (j,0,C) {
                 if (gr[i][j] != origGr[i][j]) {
                     printf ("%c %d %d\n", gr[i][j], i+1, j+1);
                 }
             }
         }
     }
     return 0;
 }
 
