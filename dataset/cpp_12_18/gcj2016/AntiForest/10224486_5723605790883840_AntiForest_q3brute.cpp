#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int _T;
 int R, C, p[100];
 char grid[100][100];
 
 pii whichSquare[500];
 
 bool tryMaze() {
     bool seen[20][20][2][50];
     int cX, cY, cTop;
     // Try top ones first:
     memset(seen,0,sizeof(seen));
     FO (i,1,2*R+2*C+1) {
         if (i <= C) {
             cX = i; cY = 1; cTop = true;
         } else if (i <= R+C) {
             cX = C; cY = i-C;
             if (grid[cY][cX] == '\\') cTop = true;
             else cTop = false;
         } else if (i <= C+R+C) {
             cY = R;
             cX = i-R-C;
             cX = C+1-cX;
             cTop = false;
         } else {
             cX = 1;
             cY = i-R-C-C;
             cY = R+1-cY;
             if (grid[cY][cX] == '\\') cTop = false;
             else cTop = true;
         }
         //printf ("NEW TRIP:\n");
         for (;;) {
             //printf ("AT: %d %d %d %d\n", cY, cX, cTop, i);
             seen[cY][cX][cTop][i] = true;
             // Case bash all possibilities:
             int nY, nX, nTop;
             if (grid[cY][cX] == '\\') {
                 if (cTop) {
                     nY = cY-1;
                     nX = cX; 
                     nTop = false;
                     if (nY == 0) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else if (!seen[nY][nX][nTop][i]) {
                         cY = nY; cX = nX; cTop = nTop;
                         continue;
                     }
                     nY = cY;
                     nX = cX+1;
                     if (nX == C+1) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else {
                         if (grid[nY][nX] == '/') nTop = true;
                         else nTop = false;
                         if (!seen[nY][nX][nTop][i]) {
                             cY = nY; cX = nX; cTop = nTop;
                             continue;
                         }
                     }
                     return false;
                 } else {
                     nY = cY+1;
                     nX = cX;
                     nTop = true;
                     if (nY == R+1) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else if (!seen[nY][nX][nTop][i]) {
                         cY = nY; cX = nX; cTop = nTop;
                         continue;
                     }
                     nY = cY;
                     nX = cX-1;
                     if (nX == 0) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else {
                         if (grid[nY][nX] == '/') nTop = false;
                         else nTop = true;
                         if (!seen[nY][nX][nTop][i]) {
                             cY = nY; cX = nX; cTop = nTop;
                             continue;
                         }
                     }
                 }
                     return false;
             } else {
                 if (cTop) {
                     nY = cY-1;
                     nX = cX;
                     nTop = false;
                     if (nY == 0) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else if (!seen[nY][nX][nTop][i]) {
                         cY = nY; cX = nX; cTop = nTop;
                         continue;
                     }
                     nY = cY;
                     nX = cX-1;
                     if (nX == 0) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else {
                         if (grid[nY][nX] == '/') nTop = false;
                         else nTop = true;
                         if (!seen[nY][nX][nTop][i]) {
                             cY = nY; cX = nX; cTop = nTop;
                             continue;
                         }
                     }
                         return false;
                 } else {
                     nY = cY+1;
                     nX = cX;
                     nTop = true;
                     if (nY == R+1) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else if (!seen[nY][nX][nTop][i]) {
                         cY = nY; cX = nX; cTop = nTop;
                         continue;
                     }
                     nY = cY;
                     nX = cX+1;
                     if (nX == C+1) {
                         if (grid[nY][nX] != i && grid[nY][nX] != p[i]) return false;
                         if (grid[nY][nX] == p[i]) break;
                     } else {
                         if (grid[nY][nX] == '/') nTop = true;
                         else nTop = false;
                         if (!seen[nY][nX][nTop][i]) {
                             cY = nY; cX = nX; cTop = nTop;
                             continue;
                         }
                     }
                 }
                     return false;
             }
         }
     }
     // CHECK ALL SQUARES NOW:
     return true;
 }
 
 
 bool genAllMazes(int sqInd) {
     if (sqInd == R*C) {
         /* 
         FO (i,0,R+2) {
             FO (p,0,C+2) {
                 if (grid[i][p] <= 32) printf ("%d", grid[i][p]);
                 else printf ("%c", grid[i][p]);
             }
             printf ("\n");
         }
         printf ("~~~~~~~\n");
         */
         return tryMaze();
     }
     int cR = whichSquare[sqInd].fi;
     int cC = whichSquare[sqInd].se;
     grid[cR][cC] = '/';
     if (genAllMazes(sqInd+1)) return true;
     grid[cR][cC] = '\\';
     if (genAllMazes(sqInd+1)) return true;
     return false;
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &R, &C);
         FO (i,1,R+C+1) {
             int _a, _b;
             scanf ("%d %d", &_a, &_b);
             p[_a] = _b; p[_b] = _a;
         }
         int cInd = 1;
         memset(grid,0,sizeof(grid));
         memset(whichSquare,0,sizeof(whichSquare));
         FO (i,1,C+1) {
             grid[0][i] = cInd++;
         }
         FO (i,1,R+1) {
             grid[i][C+1] = cInd++;
         }
         for (int i = C; i >= 1; i--) {
             grid[R+1][i] = cInd++;
         }
         for (int i = R; i >= 1; i--) {
             grid[i][0] = cInd++;
         }
         cInd = 0;
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 whichSquare[cInd++] = mp(i,p);
             }
         }
         if (genAllMazes(0)) {
             printf ("\n");
             FO(i,1,R+1) {
                 FO (p,1,C+1) {
                     printf ("%c", grid[i][p]);
                 }
                 printf ("\n");
             }
         } else {
             printf ("\nIMPOSSIBLE\n");
         }
     }
     return 0;
 }
